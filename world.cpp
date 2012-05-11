#include "world.h"

World::World(Camera* newCamera)
{
    cam = newCamera;
    //BgColor = QVector3D(93, 156, 220); //blue sky
    BgColor = QVector3D(40, 30, 0);
    IoR = 1;

    //future object importer code will live here

    //------------- testplane ---------------
    //Object* plane = new Object(new Plane(QVector3D(0, -1.8, 0), QVector3D(-0.3, 0, 0), QVector3D(0, 0, 1000)), new Material(QVector3D(200, 200, 200), QVector3D(10, 10, 10), 100, 0, false, 1));
    //objects.append(plane);

    //------------- testtriangle-------------
    /*
    Object* triangle = new Object(new Triangle(QVector3D(-1, 1, 2), QVector3D(0, -1, 1), QVector3D(1, 1, 1)), new Material());
    objects.append(triangle);

    //little spheres on the triangle's vertices
    Object* vert_marker_1 = new Object(new Sphere(QVector3D(-1, 1, 2), 0.2), new Material());
    objects.append(vert_marker_1);

    Object* vert_marker_2 = new Object(new Sphere(QVector3D(1, 1, 1), 0.2), new Material());
    objects.append(vert_marker_2);

    Object* vert_marker_3 = new Object(new Sphere(QVector3D(0, -1, 1), 0.2), new Material());
    objects.append(vert_marker_3);
    */
    //------------- testsphere --------------
    /*
    Object* sphere1 = new Object(new Sphere(QVector3D(0, -4, 0), 3), new Material());
    objects.append(sphere1);

    Object* sphereGlass = new Object(new Sphere(QVector3D(-0.4, -0.1, 0), 1), new Material(QVector3D(20, 20, 20), QVector3D(50, 50, 50), 100, 0.4, false, 1.3));
    objects.append(sphereGlass);

    Object* sphere3 = new Object(new Sphere(QVector3D(-2, 0, 3), 0.3), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
    objects.append(sphere3);

    Object* sphere4 = new Object(new Sphere(QVector3D(-1.3, 0, 3), 0.3), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
    objects.append(sphere4);

    Object* sphere5 = new Object(new Sphere(QVector3D(-0.6, 0, 3), 0.3), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
    objects.append(sphere5);

    Object* sphere6 = new Object(new Sphere(QVector3D(0.1, 0, 3), 0.3), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
    objects.append(sphere6);

    Object* sphereOnTheRight = new Object(new Sphere(QVector3D(3, 0.3, 0), 1.5), new Material(QVector3D(50, 50, 150), QVector3D(50, 50, 50), 100, 0.1, false, 1.33));
    objects.append(sphereOnTheRight);

    //Object* sphere8 = new Object(new Sphere(QVector3D(0, 0, 0), 20), new Material(QVector3D(50, 50, 150), QVector3D(50, 50, 50), 100, 0, false, 1));
    //objects.append(sphere8);
    */
    //------------- testlight ---------------
    /*
    //"testsun" light from the left
    Light* light2 = new Light(QVector3D(-3, 2, -3), QVector3D(250, 250, 220), 9);
    lights.append(light2);

    //"testsky" light from the right
    Light* light = new Light(QVector3D(3, 3, -2), QVector3D(93, 156, 220), 6);
    lights.append(light);

    //Object* sphere5 = new Object(new Sphere(QVector3D(3, 1, -0.6), 0.5), new Material(QVector3D(150, 150, 150), QVector3D(50, 50, 50), 1000, 0.3));
    //objects.append(sphere5);

    /*****************************************************************************************************************/
    /*
    //Snowman scene
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
    /*****************************************************************************************************************/
    /*
    //test with many objects
    Object* objArray[20][20];
    for(int q = 0; q < 20; q++){
        for(int p = 0; p < 20; p++){
            objArray[q][p] = new Object(new Sphere(QVector3D(-2, (-4 + p), (-3 + q)), 0.35), new Material(QVector3D(50, 50, 50), QVector3D(50, 50, 50), 100, 0, false, 1));
            objects.append(objArray[q][p]);
        }
    }
    LOG("objArray built")

    /*****************************************************************************************************************/
    //Cornell Box Scene
    //light
    Light* light2 = new Light(QVector3D(0.8, 1, 1), QVector3D(250, 250, 220), 1);
    lights.append(light2);

    //materials
    Material* white_wall = new Material(QVector3D(200, 200, 200), QVector3D(10, 10, 10), 150, 0, false, 1);
    Material* green_wall = new Material(QVector3D(20, 200, 20), QVector3D(10, 10, 10), 30, 0, false, 1);
    Material* red_wall = new Material(QVector3D(200, 20, 20), QVector3D(10, 10, 10), 30, 0, false, 1);
    Material* sphere_glossy_mat = new Material(QVector3D(80, 80, 190), QVector3D(40, 40, 40), 200, 0.2, false, 1);
    Material* sphere_glass_mat = new Material(QVector3D(190, 80, 80), QVector3D(40, 40, 40), 500, 0, true, 1.51);
    Material* cube = new Material();
    Material* mirror = new Material(QVector3D(150, 150, 150), QVector3D(40, 40, 40), 800, 0.5, false, 1);

    //triangle borders
    //left wall
    Object* leftwall_top = new Object(new Triangle(QVector3D(-2, 2, 0), QVector3D(-2, -2, 0), QVector3D(-2, 2, 4)), red_wall);
    objects.append(leftwall_top);
    Object* leftwall_bottom = new Object(new Triangle(QVector3D(-2, -2, 0), QVector3D(-2, -2, 4), QVector3D(-2, 2, 4)), red_wall);
    objects.append(leftwall_bottom);
    //right wall
    Object* rightwall_top = new Object(new Triangle(QVector3D(2, 2, 0), QVector3D(2, -2, 0), QVector3D(2, 2, 4)), green_wall);
    objects.append(rightwall_top);
    Object* rightwall_bottom = new Object(new Triangle(QVector3D(2, -2, 0), QVector3D(2, -2, 4), QVector3D(2, 2, 4)), green_wall);
    objects.append(rightwall_bottom);
    //bottom
    Object* bottom_1 = new Object(new Triangle(QVector3D(-2, -2, 0), QVector3D(2, -2, 0), QVector3D(-2, -2, 4)), mirror);
    objects.append(bottom_1);
    Object* bottom_2 = new Object(new Triangle(QVector3D(2, -2, 0), QVector3D(2, -2, 4), QVector3D(-2, -2, 4)), mirror);
    objects.append(bottom_2);
    //top
    Object* top_1 = new Object(new Triangle(QVector3D(-2, 2, 0), QVector3D(2, 2, 0), QVector3D(-2, 2, 4)), white_wall);
    objects.append(top_1);
    Object* top_2 = new Object(new Triangle(QVector3D(2, 2, 0), QVector3D(2, 2, 4), QVector3D(-2, 2, 4)), white_wall);
    objects.append(top_2);
    //rear
    Object* rear_1 = new Object(new Triangle(QVector3D(-2, 2, 4), QVector3D(-2, -2, 4), QVector3D(2, 2, 4)), white_wall);
    objects.append(rear_1);
    Object* rear_2 = new Object(new Triangle(QVector3D(-2, -2, 4), QVector3D(2, -2, 4), QVector3D(2, 2, 4)), white_wall);
    objects.append(rear_2);

    //objects in the box
    //sphere
    Object* sphere1 = new Object(new Sphere(QVector3D(1, -1.5, 1), 0.5), sphere_glass_mat);
    objects.append(sphere1);
    Object* sphere2 = new Object(new Sphere(QVector3D(-0.9, -1, 2.5), 1), sphere_glossy_mat);
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

QVector<Light*>& World::getLights(){
    return lights;
}

QVector3D World::getBgColor(){
    return BgColor;
}

double World::getIoR(){
    return IoR;
}
