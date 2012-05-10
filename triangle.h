#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "predefs.h"
#include "plane.h"
#include <QVector3D>

class Triangle : public Plane
{
public:
    Triangle(QVector3D newA, QVector3D newB, QVector3D newC);

    Geometry::IntersectionInfo getIntersectionInfo(Ray ray);

    //QVector3D getNormal(QVector3D PointOnSurface);

private:
    QVector3D A;
    QVector3D B;
    QVector3D C;
    //QVector3D normal; //in plane.cpp (protected)
};

#endif // TRIANGLE_H
