#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "plane.h"

class Triangle// : public Plane
{
public:
    Triangle(QVector3D A, QVector3D B, QVector3D C);

    Geometry::IntersectionInfo getIntersectionInfo(Ray ray);

    QVector3D getNormal(QVector3D PointOnSurface);

private:
    QVector3D A;
    QVector3D B;
    QVector3D C;
};

#endif // TRIANGLE_H
