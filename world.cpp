#include "world.h"

World::World(Camera* newCamera)
{
    cam = newCamera;

    //future object importer code will live here

    /*
    //------------- testplane ---------------
    Object* plane = new Object(new Plane(QVector3D(0, -2, 8), QVector3D(1, 0, 0), QVector3D(0.1, 0.1, 1)), new Material(QColor(0, 30, 200)));
    objects.append(plane);
    */

    //------------- testsphere --------------
    Object* sphere1 = new Object(new Sphere(QVector3D(0, -3, 7), 3), new Material(QVector3D(250, 10, 10)));//
    objects.append(sphere1);

    Object* sphere2 = new Object(new Sphere(QVector3D(1, -3, 4), 2), new Material(QVector3D(200, 100, 100)));
    objects.append(sphere2);

    Object* sphere3 = new Object(new Sphere(QVector3D(7, 6, 20), 5), new Material(QVector3D(200, 100, 100)));
    objects.append(sphere3);

    Object* sphere4 = new Object(new Sphere(QVector3D(-5, -2, 3), 1), new Material(QVector3D(50, 100, 100)));
    objects.append(sphere4);

    Object* sphere5 = new Object(new Sphere(QVector3D(7, 4, 10), 2), new Material(QVector3D(200, 100, 100)));
    objects.append(sphere5);

    //------------- testlight ---------------
    Light* light = new Light(QVector3D(6, 5, 1), QVector3D(250, 250, 250), 1);
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
