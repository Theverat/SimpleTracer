#include "raytracer.h"

RayTracer::RayTracer(int x, int y):
    renderImage(new QImage(x, y, QImage::Format_ARGB32))
{
    camera = new Camera(QVector3D(0, 0, -5), x, y);
    object = new Object(new Sphere(QVector3D(0, 0, 6), 2), new Material(QColor(10, 120, 10)));
}

void RayTracer::raytrace(){

    for(int y = 0; y < camera->getImgHeigth(); y++){
        for(int x = 0; x < camera->getImgWidth(); x++){
            renderImage->setPixel(x, y, getColorForPixel(x, y).rgba());
        }
    }
    std::cout << "render finished" << std::endl;
    emit returnImage(renderImage.data());

}

QColor RayTracer::getColorForPixel(int x, int y){

    //missing code in this function:
    // - multiple objects support (will get own function) with test which object is the nearest to the camera
    // - diffuse and specular shading etc. (will also get own functions with names like Render_DiffuseShading etc.)

    //std::cout << "distance == " << sphere->getIntersectionInfo(camera->shootRay(x, y)).distance << std::endl; //debugging

    Ray ray = camera->shootRay(x, y);
    Geometry::IntersectionInfo IntersectInfo = object->getShape()->getIntersectionInfo(ray);

    /*
    if(IntersectInfo.hit == true){

        return Render_Normal(IntersectInfo, ray);
    }
    */

    if(IntersectInfo.hit == true){

        QColor Computed_Normal_Color = Render_Normal(IntersectInfo, ray);
        QColor Computed_Diffuse_Color = Render_DiffuseColor();

        return QColor((Computed_Normal_Color.red() * Computed_Diffuse_Color.red()/100),
                      (Computed_Normal_Color.green() * Computed_Diffuse_Color.green()/100),
                      (Computed_Normal_Color.blue() * Computed_Diffuse_Color.blue())/100); //multiply the two colors
    }

    return QColor(0, 0, 0);
}

QColor RayTracer::Render_Normal(Geometry::IntersectionInfo Info, Ray ray){

    QVector3D PointOnSphereSurface = QVector3D(ray.getDirection().x(), ray.getDirection().y(), Info.distance);
    QVector3D normal = object->getShape()->getNormal(PointOnSphereSurface);

    //This part isn't finished... I had no idea what I was doing here =) (just wanted to see some colors depending on the angle between normal and ray)
    //Formula: Val = 255 * angle(ray, normal);
    int ColorValue = 600 * (acos(QVector3D::dotProduct(ray.getDirection(), normal)/(ray.getDirection().length()*normal.length())));
    //std::cout << "ColorValue == " << ColorValue << std::endl; //only for debugging

    return QColor(ColorValue, ColorValue, ColorValue);
}

QColor RayTracer::Render_DiffuseColor(){
    //has to be extended
    return object->getMat()->getDiffuseColor();
}
