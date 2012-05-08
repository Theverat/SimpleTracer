#ifndef PLANE_H
#define PLANE_H

#include "geometry.h"

class Plane : public Geometry
{
public:
    Plane(QVector3D newOrigin, QVector3D newVector1, QVector3D newVector2);

    Geometry::IntersectionInfo getIntersectionInfo(Ray ray);

    QVector3D getNormal(QVector3D PointOnSurface);

private:
    QVector3D Origin;
    QVector3D Vector1;
    QVector3D Vector2;

    QVector3D normal; //surface normal, gets computed at constructor call
    double n0;
};

#endif // PLANE_H
