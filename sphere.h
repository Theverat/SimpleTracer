#ifndef SPHERE_H
#define SPHERE_H

#include "geometry.h"
#include <math.h>

class Sphere : public Geometry
{
public:
    Sphere(QVector3D newMidpoint, double newRadius);

    Geometry::IntersectionInfo getIntersectionInfo(Ray ray);

    QVector3D getNormal(QVector3D PointOnSurface);

private:
    QVector3D Midpoint;
    double Radius;

    double max(double a, double b);
    double min(double a, double b);
};

#endif // SPHERE_H
