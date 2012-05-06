#include "raytracer.h"

RayTracer::RayTracer(int x, int y):
    renderImage(new QImage(x, y, QImage::Format_ARGB32))
{
    camera = new Camera(QVector3D(0, 0, -5), x, y);

    world = new World(camera);

    //now in world.cpp:
    //object = new Object(new Sphere(QVector3D(0, 0, 6), 4), new Material(QColor(250, 10, 10)));
    //plane = new Object(new Plane(QVector3D(0, 0, 8), QVector3D(1, 0, 0), QVector3D(0.1, 0.1, 1)), new Material(QColor(0, 30, 200)));
}

void RayTracer::render(){

    for(int y = 0; y < camera->getImgHeigth(); y++){
        for(int x = 0; x < camera->getImgWidth(); x++){
            renderImage->setPixel(x, y, getColorForPixel(x, y).rgba());
            //std::cout << "for-schleife: y == " << y << std::endl
            //          << "for-schleife: x == " << x << std::endl;
        }
    }
    std::cout << "render finished" << std::endl;
    emit returnImage(renderImage.data());
}

QColor RayTracer::getColorForPixel(int x, int y){

    Ray ray = camera->shootRay(x, y);

    QVector3D ColorAtPixel = raytrace(ray);

    return QColor(ColorAtPixel.x(), ColorAtPixel.y(), ColorAtPixel.z());
}

QVector3D RayTracer::raytrace(Ray ray){
    //missing code in this function:
    // - multiple objects support (will get own function) with test which object is the nearest to the camera
    // - diffuse and specular shading etc. (will also get own functions with names like Render_DiffuseShading etc.)

    double nearestDist = 9999999999999;
    Object* nearestObj = new Object(new Sphere(QVector3D(0, 0, 6), 4), new Material(QColor(250, 10, 10)));

    //find closest intersection (can be accelerated extremely!)
    for(int i = 0; i < world->getObjects().size(); i++){
        Object* obj = world->getObjects().at(i);
        Geometry::IntersectionInfo IntersectInfo = obj->getMesh()->getIntersectionInfo(ray);

        if(IntersectInfo.hit == true){

            if(IntersectInfo.distance < nearestDist){
                nearestDist = IntersectInfo.distance;
                nearestObj = new Object(obj->getMesh(), obj->getMat());
                //std::cout << "nearestObj zugewiesen, i == " << i << std::endl;
            }
        }
    }
    //std::cout << "for-schleife beendet" << std::endl;
    return Render_Normal(nearestDist, ray, nearestObj);

    return QVector3D(0, 0, 0); //maybe replace with world->backgroundcolor later
}

/*QColor RayTracer::Render_Normal(Geometry::IntersectionInfo Info, Ray ray){

    QVector3D PointOnSphereSurface = QVector3D(ray.getDirection().x(), ray.getDirection().y(), Info.distance);
    //QVector3D normal = object->getSphere()->getNormal(PointOnSphereSurface);
    QVector3D normal = plane->getPlane()->getNormal();

    //This part isn't finished... I had no idea what I was doing here =) (just wanted to see some colors depending on the angle between normal and ray)
    //Formula: Val = 255 * angle(ray, normal);
    int ColorValue = 255 * (acos(QVector3D::dotProduct(ray.getDirection(), normal)/(ray.getDirection().length()*normal.length()))/3);
    //std::cout << "ColorValue == " << ColorValue << std::endl; //only for debugging

    return QColor(ColorValue, ColorValue, ColorValue);
}*/

QVector3D RayTracer::Render_Normal(double distance, Ray ray, Object *obj){

    QVector3D PointOnSphereSurface = QVector3D(ray.getDirection().x(), ray.getDirection().y(), distance);
    QVector3D normal = obj->getMesh()->getNormal(PointOnSphereSurface);

    double diff = (QVector3D::dotProduct(ray.getDirection(), normal) * obj->getMat()->getDiffuseColor().rgb())/100000000;
    //std::cout << "diff == " << diff << std::endl; //only for debugging

    return QVector3D(diff, diff, diff);
}

QVector3D RayTracer::Render_DiffuseColor(Object *obj){
    //has to be extended (maybe with oren-nayar implementation?)
    return QVector3D(obj->getMat()->getDiffuseColor().red(), obj->getMat()->getDiffuseColor().green(), obj->getMat()->getDiffuseColor().blue());
}
