#ifndef OBJECT_H
#define OBJECT_H

#include "geometry.h"
#include "sphere.h"
#include "material.h"

class Object
{
public:
    Object(Sphere *newShape, Material *newMat);

    Sphere* getShape();
    Material* getMat();

private:
    Sphere *Shape;
    Material *Mat;
};

#endif // OBJECT_H
