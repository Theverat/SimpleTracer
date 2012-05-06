#include "world.h"

World::World(Camera* newCamera)
{
    cam = newCamera;

    //future object importer code will live here

    /*
    //------------- testplane ---------------
    Object* plane = new Object(new Plane(QVector3D(0, 0, 8), QVector3D(1, 0, 0), QVector3D(0.1, 0.1, 1)), new Material(QColor(0, 30, 200)));
    objects.append(plane);
    */

    //------------- testsphere --------------
    Object* sphere = new Object(new Sphere(QVector3D(0, 0, 6), 4), new Material(QColor(250, 10, 10)));
    objects.append(sphere);

    Object* sphere2 = new Object(new Sphere(QVector3D(1, 1, 4), 3), new Material(QColor(200, 10, 10)));
    objects.append(sphere2);
}

Camera* World::getCamera(){
    return cam;
}

void World::setCamera(Camera* newCam){
    cam = newCam;
}

QVector<Object*>& World::getObjects(){
    return objects;
}

//QVector<Light*>& World::getLights(){
//    return lights;
//}
