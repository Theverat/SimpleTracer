#include "raytracer.h"

RayTracer::RayTracer(int x, int y):
    renderImage(new QImage(800, 600, QImage::Format_ARGB32))
{
    camera = new Camera(QVector3D(0, 0, -5), 800, 600);
    sphere = new Sphere(QVector3D(0, 0, 3), 3.4);
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

    //std::cout << "distance == " << sphere->getIntersectionInfo(camera->shootRay(x, y)).distance << std::endl;

    Ray ray = camera->shootRay(x, y);

    if(sphere->getIntersectionInfo(ray).hit == true){

        QVector3D normal = sphere->getNormal(QVector3D(ray.getDirection().x(), ray.getDirection().y(), sphere->getIntersectionInfo(ray).distance));

        //std::cout << "normal.x() == " << normal.x() << std::endl;
        //std::cout << "normal.y() == " << normal.y() << std::endl;
        //std::cout << "normal.z() == " << normal.z() << std::endl;
        //std::cout << std::endl;

        //Formula: Val = 255 * (angle(ray, normal) / 180);

        int ColorValue = 500 * (acos(QVector3D::dotProduct(ray.getDirection(), normal)/(ray.getDirection().length()*normal.length())));
        std::cout << "ColorValue == " << ColorValue << std::endl;

        return QColor(ColorValue, ColorValue, ColorValue);
    }

    return QColor(0, 0, 0);
}
