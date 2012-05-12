#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QVector3D>
#include <iostream>
#include "ray.h"

class Geometry
{
public:

    struct IntersectionInfo{
        IntersectionInfo():hit(false), distance(-1){}
        bool hit;
        double distance;
    };

    virtual IntersectionInfo getIntersectionInfo(Ray ray){}

    virtual QVector3D getNormal(QVector3D PointOnSurface){}
};

#endif // GEOMETRY_H
