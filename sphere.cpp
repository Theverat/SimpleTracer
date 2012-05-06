#include "sphere.h"

Sphere::Sphere(QVector3D newMidpoint, double newRadius)
{
    Midpoint = newMidpoint;
    Radius = newRadius;
}

/* Just a test
Geometry::IntersectionInfo Sphere::getIntersectionInfo(Ray ray){
    Geometry::IntersectionInfo results;
    results.hit = false;
    results.distance = -1;

    results.distance = (Midpoint - ray.getOrigin()).length();

    return results;
}
*/

Geometry::IntersectionInfo Sphere::getIntersectionInfo(Ray ray){

    Geometry::IntersectionInfo results;

    //A=1, so no need to calculate
    double B = 2*(ray.getDirection().x() * (ray.getOrigin().x() - Midpoint.x()) + ray.getDirection().y() * (ray.getOrigin().y() - Midpoint.y())  + ray.getDirection().z() * (ray.getOrigin().z() - Midpoint.z()));
    double C = pow(ray.getOrigin().x() - Midpoint.x(),2) + pow(ray.getOrigin().y() - Midpoint.y(),2) + pow(ray.getOrigin().z() - Midpoint.z(),2) - pow(Radius,2);
    double disc = pow(B,2) - 4*C;
    if(disc > 0)
    {
        results.hit = true;
        double t1 = (-B - sqrt(disc))/2;
        double t2 = (-B + sqrt(disc))/2;
        results.distance = min(t1, t2);
        if(results.distance<0)
        {
            results.distance = max(t1, t2);
        }
    }

    return results;
}


QVector3D Sphere::getNormal(QVector3D PointOnSurface){
    return QVector3D(PointOnSurface - Midpoint);
}

double Sphere::max(double a, double b){
    return a>b?a:b;
}

double Sphere::min(double a, double b){
    return a<b?a:b;
}
