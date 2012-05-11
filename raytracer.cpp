#include "raytracer.h"

RayTracer::RayTracer(int x, int y, uint newDepth):
    renderImage(new QImage(x, y, QImage::Format_ARGB32))
{
    world = new World(new Camera(QVector3D(0, 0, -5), QVector3D(0, 0, 1), x, y, 60));
    depth = newDepth;
}

void RayTracer::render(){

    for(int y = 0; y < world->getCamera()->getImgHeigth(); y++){
        for(int x = 0; x < world->getCamera()->getImgWidth(); x++){
            renderImage->setPixel(x, y, getColorForPixel(x, y).rgba());
        }
        //emit returnLine(renderImage.data());
    }
    std::cout << "render finished" << std::endl;
    emit returnImage(renderImage.data());
}

QColor RayTracer::getColorForPixel(int x, int y){

    Ray ray = world->getCamera()->shootRay(x, y);

    QVector3D ColorAtPixel = raytrace(ray, 0);

    //clamping
    int r = ColorAtPixel.x();
    int g = ColorAtPixel.y();
    int b = ColorAtPixel.z();

    if(r > 255)
        r = 255;
    if(g > 255)
        g = 255;
    if(b > 255)
        b = 255;

    if(r < 0)
        r = 0;
    if(g < 0)
        g = 0;
    if(b < 0)
        b = 0;

    return QColor(r, g, b);
}

QVector3D RayTracer::raytrace(Ray ray, uint current_depth){

    /*****************************************************************************************************************/
    double nearestDist = world->getCamera()->getFarClip(); //far clipping border of the scene
    Object* nearestObj = new Object(new Sphere(QVector3D(0, 0, 0), 1), new Material());

    QVector3D Accumulated_Color = QVector3D(0, 0, 0);   //the color of the pixel, stored in a QVector3D
                                                        //gets accumulated in the following process
    /*****************************************************************************************************************/
    //find closest intersection (can be accelerated extremely lateron!)
    for(int i = 0; i < world->getObjects().size(); i++){
        Object* obj = world->getObjects().at(i);
        Geometry::IntersectionInfo IntersectInfo = obj->getMesh()->getIntersectionInfo(ray);

        if(IntersectInfo.hit == true){

            if(IntersectInfo.distance < nearestDist){
                nearestDist = IntersectInfo.distance;
                nearestObj = new Object(obj->getMesh(), obj->getMat());
            }
        }
    }

    //not physically correct, has to be extended or replaced later (maybe with oren-nayar implementation?)

    if(nearestDist == world->getCamera()->getFarClip())
        return Accumulated_Color += world->getBgColor(); //background color

    //hitpoint on the object's surface
    QVector3D hitpoint = ray.getOrigin() + ray.getDirection() * nearestDist;
    QVector3D normal = (nearestObj->getMesh()->getNormal(hitpoint)).normalized();

    /*****************************************************************************************************************/
    //trace lights
    for(int l = 0; l < world->getLights().size(); l++){
        Light* light = world->getLights().at(l);
        //LOG("l == " << l)

        //vector from hitpoint to light, normalized
        QVector3D lightray = (light->getPosition() - hitpoint).normalized();
        double lightrayLength = (light->getPosition() - hitpoint).length();

        /*****************************************************************************************************************/
        //calculate shadows
        double shade = 1; //amount of shadowing at the hitpoint
        //check if there's at least one object occluding the lightsource from the hitpoint
        QVector3D shadowray = light->getPosition() - hitpoint;
        double tdist = shadowray.length();

        for(int o = 0; o < world->getObjects().size(); o++){
            Object* obstacle = world->getObjects().at(o);
            Geometry::IntersectionInfo ShadowInfo = obstacle->getMesh()->getIntersectionInfo(Ray(hitpoint + shadowray * EPSILON, shadowray));

            if(ShadowInfo.hit == true && ShadowInfo.distance <= tdist){
                shade = 0;
                break;
            }
        }

        /*****************************************************************************************************************/
        //calculate diffuse shading
        //dotproduct of lightray and surface normal
        if(nearestObj->getMat()->getDiffuseColor().length() > 0.0f){
            double dotLN = fabs(QVector3D::dotProduct(lightray, normal));

            if(dotLN > 0){
                //get the color the surface has at the hitpoint and multiply it with the shadowing factor
                QVector3D diffuseCol = dotLN * nearestObj->getMat()->getDiffuseColor() * shade;
                //add the diffuse color to the ray's color
                //square light falloff
                //Accumulated_Color += (diffuseCol * ((light->getColor() * light->getIntensity())/pow((lightrayLength + EPSILON), 2)))/100; //first implementation, only direct lighting
                //linear light falloff
                Accumulated_Color += (diffuseCol * ((light->getColor() * light->getIntensity())/(lightrayLength + EPSILON)))/100;
            }
        }

        /*****************************************************************************************************************/
        //calculate specular shading
        if(nearestObj->getMat()->getSpecularColor().length() > 0.0f){
            QVector3D Incoming_Vector = ray.getDirection();
            QVector3D Reflected_Vector = lightray - 2 * QVector3D::dotProduct(lightray, normal) * normal; //normalized by design
            double dotIR = QVector3D::dotProduct(Incoming_Vector, Reflected_Vector);

            if(dotIR > 0){
                double specularAmount = powf(dotIR, nearestObj->getMat()->getExponent()) * nearestObj->getMat()->getSpecularColor().length()/100;
                //add the specular color to the ray's color
                Accumulated_Color += (specularAmount * light->getColor() * light->getIntensity());
            }
        }

        /*****************************************************************************************************************/
        //calculate reflection
        if((current_depth < depth) && (nearestObj->getMat()->getReflectionAmount() > 0.0f)){
            QVector3D Reflected_Vector = ray.getDirection() - 2 * QVector3D::dotProduct(ray.getDirection(), normal) * normal; //normalized by design
            QVector3D Reflected_Color = raytrace(Ray(hitpoint + Reflected_Vector * EPSILON, Reflected_Vector), current_depth + 1);
            Accumulated_Color += Reflected_Color * nearestObj->getMat()->getReflectionAmount();
        }

        /*****************************************************************************************************************/
        //calculate refraction
        if((current_depth < depth) && (nearestObj->getMat()->getTransparency() == true)){
            QVector3D Refracted_Vector;
            QVector3D normal = nearestObj->getMesh()->getNormal(hitpoint);
            double n = world->getIoR()/nearestObj->getMat()->getIoR();
            double cosI = QVector3D::dotProduct(normal, ray.getDirection());
            double sinT2 = n*n * (1.0 - cosI*cosI);
            if(sinT2 <= 1.0)
            {
                Refracted_Vector = n * ray.getDirection() - (n + sqrtf(1.0 - sinT2)) * normal;
                QVector3D Refracted_Color = raytrace(Ray(hitpoint + Refracted_Vector * EPSILON, Refracted_Vector), current_depth + 1);
                Accumulated_Color = Refracted_Color; //maybe add a blending factor with the diffuse color later
            }
        }
    }

    delete nearestObj;

    return Accumulated_Color;
}

//obsolete function that was only used for testing purposes
QVector3D RayTracer::Render_Normal(double distance, Ray ray, Object *obj){

    QVector3D PointOnSphereSurface = QVector3D(ray.getDirection().x(), ray.getDirection().y(), distance);
    QVector3D normal = obj->getMesh()->getNormal(PointOnSphereSurface);

    QVector3D diff = (QVector3D::dotProduct(ray.getDirection(), normal) * obj->getMat()->getDiffuseColor())/100000000;

    return diff;
}
