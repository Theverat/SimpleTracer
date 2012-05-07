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
    //missing code in this function:
    // - multiple objects support (will get own function) with test which object is the nearest to the camera
    // - diffuse and specular shading etc. (will also get own functions with names like Render_DiffuseShading etc.)

    double nearestDist = 9999999999999;
    Object* nearestObj = new Object(new Sphere(QVector3D(0, 0, 6), 4), new Material(QVector3D(250, 10, 10)));

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

    if(distance == 9999999999999)
        return QVector3D(0, 60, 0); //background color

    //hitpoint on the object's surface
    QVector3D hitpoint = ray.getOrigin() + ray.getDirection() * distance;

    //trace lights
    for(int l = 0; l < world->getLights().size(); l++){
        Light* light = world->getLights().at(l);


        //vector from hitpoint to light, normalized
        QVector3D lightray = (light->getPosition() - hitpoint).normalized();
        double shade = 1; //amount of shadowing at the hitpoint
        QVector3D normal = (obj->getMesh()->getNormal(hitpoint)).normalized();

        //check if there's at least one object occluding the lightsource from the hitpoint
        QVector3D shadowray = light->getPosition() - hitpoint;
        double tdist = shadowray.length();
        shadowray = shadowray * (1.0f / tdist);

        for(int o = 0; o < world->getObjects().size(); o++){
            Object* obstacle = world->getObjects().at(o);
            if(obstacle->getMesh()->getIntersectionInfo(Ray(hitpoint + shadowray * EPSILON, shadowray)).hit == true){
                shade = 0;
                break;
            }
        }

        //calculate diffuse shading
        //dotproduct of lightray and surface normal
        double dot = QVector3D::dotProduct(lightray, normal);

        if(dot > 0){
            //get the color the surface has at the hitpoint
            QVector3D diffuseCol = dot * obj->getMat()->getDiffuseColor() * shade;
            //return diffuse color, should be added to the ray color in the main raytrace loop
            return diffuseCol;
        }
    }
}

QVector3D RayTracer::Render_Normal(double distance, Ray ray, Object *obj){

    QVector3D PointOnSphereSurface = QVector3D(ray.getDirection().x(), ray.getDirection().y(), distance);
    QVector3D normal = obj->getMesh()->getNormal(PointOnSphereSurface);

    QVector3D diff = (QVector3D::dotProduct(ray.getDirection(), normal) * obj->getMat()->getDiffuseColor())/100000000;

    return diff;
}
