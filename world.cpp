#include "world.h"

World::World(Camera* newCamera)
{
    cam = newCamera;
    BgColor = QVector3D(0, 60, 0);
    IoR = 1;

    //future object importer code will live here

    //------------- testplane ---------------
    Object* plane = new Object(new Plane(QVector3D(0, -2, 0), QVector3D(0, 1, 0), QVector3D(0, 0, 1)), new Material());
    objects.append(plane);


    //------------- testsphere --------------
    /*
    Object* sphere1 = new Object(new Sphere(QVector3D(0, -4, 0), 3), new Material());
    objects.append(sphere1);

    Object* sphereGlass = new Object(new Sphere(QVector3D(0, 0, 0), 0.7), new Material(QVector3D(200, 200, 200), QVector3D(50, 50, 50), 100, 0, true, 1.51));
    objects.append(sphereGlass);

    Object* sphere3 = new Object(new Sphere(QVector3D(-2, 0, 3), 0.3), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
    objects.append(sphere3);

    Object* sphere4 = new Object(new Sphere(QVector3D(-1.3, 0, 3), 0.3), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
    objects.append(sphere4);

    Object* sphere5 = new Object(new Sphere(QVector3D(-0.6, 0, 3), 0.3), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
    objects.append(sphere5);

    Object* sphere6 = new Object(new Sphere(QVector3D(0.1, 0, 3), 0.3), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
    objects.append(sphere6);

    Object* sphereOnTheRight = new Object(new Sphere(QVector3D(3, 0, 0), 1.5), new Material(QVector3D(50, 50, 150), QVector3D(50, 50, 50), 100, 0.6, false, 1));
    objects.append(sphereOnTheRight);

    //Object* sphere8 = new Object(new Sphere(QVector3D(0, 0, 0), 20), new Material(QVector3D(50, 50, 150), QVector3D(50, 50, 50), 100, 0, false, 1));
    //objects.append(sphere8);
    */
    //------------- testlight ---------------
    Light* light = new Light(QVector3D(3, 3, -2), QVector3D(250, 230, 230), 3);
    lights.append(light);

    //Object* sphere5 = new Object(new Sphere(QVector3D(3, 1, -0.6), 0.5), new Material(QVector3D(150, 150, 150), QVector3D(50, 50, 50), 1000, 0.3));
    //objects.append(sphere5);

    //Snowman
    Light* light2 = new Light(QVector3D(-3, 2, -3), QVector3D(250, 250, 200), 8);
    lights.append(light2);

    Object* body1 = new Object(new Sphere(QVector3D(0, -1.5, 0), 1), new Material(QVector3D(200, 200, 200), QVector3D(1, 1, 1), 30, 0, false, 1));
    objects.append(body1);

    Object* body2 = new Object(new Sphere(QVector3D(0, 0, 0), 0.8), new Material(QVector3D(200, 200, 200), QVector3D(1, 1, 1), 30, 0, false, 1));
    objects.append(body2);

    Object* head = new Object(new Sphere(QVector3D(0, 1.1, -0.1), 0.6), new Material(QVector3D(200, 200, 200), QVector3D(1, 1, 1), 30, 0, false, 1));
    objects.append(head);

    Object* eye1 = new Object(new Sphere(QVector3D(0.2, 1.1, -1), 0.05), new Material(QVector3D(20, 20, 20), QVector3D(10, 10, 10), 100, 0.2, false, 1));
    objects.append(eye1);

    Object* eye2 = new Object(new Sphere(QVector3D(-0.2, 1.1, -1), 0.05), new Material(QVector3D(20, 20, 20), QVector3D(10, 10, 10), 100, 0.2, false, 1));
    objects.append(eye2);

    Object* knopf1 = new Object(new Sphere(QVector3D(0, 0.4, -1), 0.05), new Material(QVector3D(20, 20, 20), QVector3D(10, 10, 10), 100, 0.2, false, 1));
    objects.append(knopf1);

    Object* knopf2 = new Object(new Sphere(QVector3D(0, 0.1, -1), 0.05), new Material(QVector3D(20, 20, 20), QVector3D(10, 10, 10), 100, 0.2, false, 1));
    objects.append(knopf2);

    Object* knopf3 = new Object(new Sphere(QVector3D(0, -0.2, -1), 0.05), new Material(QVector3D(20, 20, 20), QVector3D(10, 10, 10), 100, 0.2, false, 1));
    objects.append(knopf3);

    Object* nose = new Object(new Sphere(QVector3D(0, 0.9, -1), 0.05), new Material(QVector3D(180, 50, 20), QVector3D(10, 10, 10), 100, 0.17, false, 1));
    objects.append(nose);
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

QVector3D World::getBgColor(){
    return BgColor;
}

double World::getIoR(){
    return IoR;
}
