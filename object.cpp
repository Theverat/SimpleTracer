#include "object.h"

Object::Object(Geometry *newMesh, Material *newMat)
{
    Mesh = newMesh;
    Mat = newMat;
}

Geometry* Object::getMesh(){
    return Mesh;
}

Material* Object::getMat(){
    return Mat;
}
