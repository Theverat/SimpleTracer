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

    double n0;

protected:
    QVector3D normal; //surface normal, gets computed at constructor call
};

#endif // PLANE_H
