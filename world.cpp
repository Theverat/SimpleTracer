#include "world.h"

World::World(Camera* newCamera)
{
    cam = newCamera;

    //future object importer code will live here

    //------------- testplane ---------------
    //Object* plane = new Object(new Plane(QVector3D(0, -1, 0), QVector3D(0, 1, 0), QVector3D(0, 0, 1)), new Material(QVector3D(100, 100, 200)));
    //objects.append(plane);


    //------------- testsphere --------------
    Object* sphere1 = new Object(new Sphere(QVector3D(0, 0, 0), 1), new Material(QVector3D(250, 10, 10)));//
    objects.append(sphere1);

    Object* sphere2 = new Object(new Sphere(QVector3D(-1.8, 0, 1), 1), new Material(QVector3D(200, 100, 100)));
    objects.append(sphere2);

    //------------- testlight ---------------
    Light* light = new Light(QVector3D(4, 3, -1.5), QVector3D(250, 250, 250), 1);
    lights.append(light);
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

QVector<Light*>& World::getLights(){
    return lights;
}
