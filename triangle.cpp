#ifndef TRIANGLE_CPP
#define TRIANGLE_CPP
#include "triangle.h"
#include "abs.cpp"

Triangle::Triangle(QVector3D newA, QVector3D newB, QVector3D newC) : Plane(newA, newB-newA, newC-newA)
{
    A = newA;
    B = newB;
    C = newC;
    normal = QVector3D::crossProduct((B - A), (C - A)).normalized();
}

/*
//Inj3ct0r's approach
Geometry::IntersectionInfo Triangle::getIntersectionInfo(Ray ray)
{
    Geometry::IntersectionInfo IntersectInfo;
    IntersectInfo = this->Plane::getIntersectionInfo(ray);
    //if there was no intersection with the plane, there will be none with the triangle
    if (!IntersectInfo.hit)
        return IntersectInfo;
    QVector3D P = ray.getOrigin() + ray.getDirection() * IntersectInfo.distance;
    QVector3D n  = QVector3D::crossProduct(A,B);
    QVector3D n1 = QVector3D::crossProduct( (A-P) , (B-P) );
    QVector3D n2 = QVector3D::crossProduct( (B-P) , (C-P) );
    QVector3D n3 = QVector3D::crossProduct( (C-P) , (A-P) );
    n1 = vec_abs(n1);
    n2 = vec_abs(n2);
    n3 = vec_abs(n3);
    n  = vec_abs(n );

    if(! ((n1 + n2 + n3 -n) == QVector3D(0,0,0)) )
    {
        IntersectInfo.hit = false;
    }
    return IntersectInfo;
}
*/

/*
//Theverat's approach
Geometry::IntersectionInfo Triangle::getIntersectionInfo(Ray ray)
{
    Geometry::IntersectionInfo IntersectInfo;
    IntersectInfo = this->Plane::getIntersectionInfo(ray);
    //if there was no intersection with the plane, there will be none with the triangle
    if (!IntersectInfo.hit)
        return IntersectInfo;

    IntersectInfo.hit = true;
    QVector3D hitpoint = ray.getOrigin() + ray.getDirection() * IntersectInfo.distance;
    IntersectInfo.distance = hitpoint.length();

    //open a new scope so we can use the same names for the vectors several times
    //check first edge of the triangle
    {
        QVector3D V_1 = A - hitpoint;
        QVector3D V_2 = B - hitpoint;
        QVector3D normal_of_V = QVector3D::crossProduct(V_1, V_2).normalized();

        if((QVector3D::dotProduct(hitpoint, normal_of_V) + QVector3D::dotProduct(-ray.getOrigin(), normal_of_V)) < 0){
            IntersectInfo.hit = false;
            return IntersectInfo;
        }
    }
    //check second edge of the triangle
    {
        QVector3D V_1 = B - hitpoint;
        QVector3D V_2 = C - hitpoint;
        QVector3D normal_of_V = QVector3D::crossProduct(V_1, V_2).normalized();

        if((QVector3D::dotProduct(hitpoint, normal_of_V) + QVector3D::dotProduct(-ray.getOrigin(), normal_of_V)) < 0){
            IntersectInfo.hit = false;
            return IntersectInfo;
        }
    }
    //check third edge of the triangle
    {
        QVector3D V_1 = C - hitpoint;
        QVector3D V_2 = A - hitpoint;
        QVector3D normal_of_V = QVector3D::crossProduct(V_1, V_2).normalized();

        if((QVector3D::dotProduct(hitpoint, normal_of_V) + QVector3D::dotProduct(-ray.getOrigin(), normal_of_V)) < 0){
            IntersectInfo.hit = false;
            return IntersectInfo;
        }
    }

    return IntersectInfo;
}
*/

//approach from http://www.cs.cornell.edu/courses/cs465/2003fa/homeworks/raytri.pdf
Geometry::IntersectionInfo Triangle::getIntersectionInfo(Ray ray)
{
    Geometry::IntersectionInfo IntersectInfo;
    IntersectInfo = this->Plane::getIntersectionInfo(ray);
    //if there was no intersection with the plane, there will be none with the triangle
    if (!IntersectInfo.hit)
        return IntersectInfo;
    QVector3D hitpoint = ray.getOrigin() + ray.getDirection() * IntersectInfo.distance;

    if(QVector3D::dotProduct(QVector3D::crossProduct((B - A), (hitpoint - A)), normal) < -EPSILON)
        IntersectInfo.hit = false;

    if(QVector3D::dotProduct(QVector3D::crossProduct((C - B), (hitpoint - B)), normal) < -EPSILON)
        IntersectInfo.hit = false;

    if(QVector3D::dotProduct(QVector3D::crossProduct((A - C), (hitpoint - C)), normal) < -EPSILON)
        IntersectInfo.hit = false;

    return IntersectInfo;
}

//getNormal() is defined in plane.cpp
//QVector3D Triangle::getNormal(QVector3D PointOnSurface){
//    return normal;
//}

#endif
