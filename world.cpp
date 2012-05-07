#include "world.h"

World::World(Camera* newCamera)
{
    cam = newCamera;

    //future object importer code will live here

    //------------- testplane ---------------
    //Object* plane = new Object(new Plane(QVector3D(0, -1, 0), QVector3D(0, 1, 0), QVector3D(0, 0, 1)), new Material(QVector3D(100, 100, 200)));
    //objects.append(plane);


    //------------- testsphere --------------
    Object* sphere1 = new Object(new Sphere(QVector3D(0, 0.8, 0), 1), new Material());//
    objects.append(sphere1);

    Object* sphere2 = new Object(new Sphere(QVector3D(0.3, -1.3, 0), 1), new Material(QVector3D(30, 30, 30), QVector3D(50, 50, 50), 100, 0.8));
    objects.append(sphere2);

    Object* sphere3 = new Object(new Sphere(QVector3D(-2, 0.5, 0), 1), new Material());
    objects.append(sphere3);

    Object* sphere4 = new Object(new Sphere(QVector3D(-2, -1.5, 0), 1), new Material(QVector3D(50, 50, 150), QVector3D(50, 50, 50), 100, 0.5));
    objects.append(sphere4);

    //------------- testlight ---------------
    Light* light = new Light(QVector3D(1, 1, -2.2), QVector3D(250, 250, 250), 1);
    lights.append(light);

    Object* sphere5 = new Object(new Sphere(QVector3D(1, 1, -1.5), 0.1), new Material());
    objects.append(sphere5);

    //Light* light2 = new Light(QVector3D(-3, -1, -3), QVector3D(30, 250, 20), 1);
    //lights.append(light2);
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
