#include "object.h"

Object::Object(Sphere *newSphere, Material *newMat)
{
    Shape_Sphere = newSphere;
    Mat = newMat;
}

Object::Object(Plane *newPlane, Material *newMat)
{
    Shape_Plane = newPlane;
    Mat = newMat;
}

Sphere* Object::getSphere(){
    return Shape_Sphere;
}

Plane* Object::getPlane(){
    return Shape_Plane;
}

Material* Object::getMat(){
    return Mat;
}
