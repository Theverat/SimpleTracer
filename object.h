#ifndef OBJECT_H
#define OBJECT_H

#include "geometry.h"
#include "sphere.h"
#include "material.h"
#include "plane.h"

class Object
{
public:
    Object(Sphere *newSphere, Material *newMat);
    Object(Plane *newPlane, Material *newMat);

    Sphere* getSphere();
    Plane* getPlane();
    Material* getMat();

private:
    Material *Mat;
    Plane *Shape_Plane;
    Sphere *Shape_Sphere;
};

#endif // OBJECT_H
