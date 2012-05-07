#include "raytracer.h"

RayTracer::RayTracer(int x, int y):
    renderImage(new QImage(x, y, QImage::Format_ARGB32))
{
    world = new World(new Camera(QVector3D(0, 0, -5), x, y));
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

    QVector3D ColorAtPixel = raytrace(ray);

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

QVector3D RayTracer::raytrace(Ray ray){

    double nearestDist = world->getCamera()->getFarClip(); //far clipping border of the scene
    Object* nearestObj = new Object(new Sphere(QVector3D(0, 0, 0), 1), new Material());
    double shade = 1; //amount of shadowing at the hitpoint

    QVector3D Accumulated_Color = QVector3D(0, 0, 0);   //the color of the pixel, stored in a QVector3D
                                                        //gets accumulated in the following process

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
        return QVector3D(0, 60, 0); //background color

    //hitpoint on the object's surface
    QVector3D hitpoint = ray.getOrigin() + ray.getDirection() * nearestDist;

    //trace lights
    for(int l = 0; l < world->getLights().size(); l++){
        Light* light = world->getLights().at(l);

        //vector from hitpoint to light, normalized
        QVector3D lightray = (light->getPosition() - hitpoint).normalized();

        QVector3D normal = (nearestObj->getMesh()->getNormal(hitpoint)).normalized();

        /* Something's wrong here...
          ----------------------------------------------------------------------------------
        //check if there's at least one object occluding the lightsource from the hitpoint
        QVector3D shadowray = light->getPosition() - hitpoint;
        double tdist = shadowray.length();

        for(int o = 0; o < world->getObjects().size(); o++){
            Object* obstacle = world->getObjects().at(o);
            Geometry::IntersectionInfo ShadowInfo = obstacle->getMesh()->getIntersectionInfo(Ray(hitpoint + shadowray * EPSILON, shadowray));

            if(ShadowInfo.hit == true && ShadowInfo.distance <= tdist && ShadowInfo.distance > 0){
                shade = 0;
                break;
            }
        }
          ----------------------------------------------------------------------------------
        */

        //calculate diffuse shading
        //dotproduct of lightray and surface normal
        double dotLN = QVector3D::dotProduct(lightray, normal);

        if(dotLN > 0){
            //get the color the surface has at the hitpoint and multiply it with the shadowing factor
            QVector3D diffuseCol = dotLN * nearestObj->getMat()->getDiffuseColor() * shade;
            //add the diffuse color to the ray's color
            Accumulated_Color += (diffuseCol * light->getColor() * light->getIntensity())/100;
        }

        //calculate specular shading
        QVector3D Incoming_Vector = ray.getDirection();
        QVector3D Reflected_Vector = lightray - 2 * QVector3D::dotProduct(lightray, normal) * normal;
        double dotIR = QVector3D::dotProduct(Incoming_Vector, Reflected_Vector);

        if(dotIR > 0){
            double specularAmount = powf(dotIR, 20) * nearestObj->getMat()->getSpecularColor().length()/100;
            //add the specular color to the ray's color
            Accumulated_Color += (specularAmount * light->getColor() * light->getIntensity());
        }
    }

    return Accumulated_Color;
}

//obsolete function that was only used for testing purposes
QVector3D RayTracer::Render_Normal(double distance, Ray ray, Object *obj){

    QVector3D PointOnSphereSurface = QVector3D(ray.getDirection().x(), ray.getDirection().y(), distance);
    QVector3D normal = obj->getMesh()->getNormal(PointOnSphereSurface);

    QVector3D diff = (QVector3D::dotProduct(ray.getDirection(), normal) * obj->getMat()->getDiffuseColor())/100000000;

    return diff;
}
