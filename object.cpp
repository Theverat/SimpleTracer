#include "object.h"

Object::Object(Sphere *newShape, Material *newMat)
{
    Shape = newShape;
    Mat = newMat;
}

Sphere* Object::getShape(){
    return Shape;
}

Material* Object::getMat(){
    return Mat;
}
