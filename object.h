#ifndef OBJECT_H
#define OBJECT_H

#include "geometry.h"
#include "sphere.h"
#include "material.h"
#include "plane.h"
#include "triangle.h"

class Object
{
public:
    Object(Geometry *newMesh, Material *newMat);

    Geometry* getMesh();
    Material* getMat();

private:
    Material *Mat;
    Geometry *Mesh;
};

#endif // OBJECT_H
