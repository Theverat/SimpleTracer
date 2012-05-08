#ifndef TRIANGLE_CPP
#define TRIANGLE_CPP
#include "triangle.h"
#include "abs.cpp"

Triangle::Triangle(QVector3D newA, QVector3D newB, QVector3D newC) : Plane(newA, newB-newA, newC-newA)
{
    A = newA;
    B = newB;
    C = newC;
}
Geometry::IntersectionInfo Triangle::getIntersectionInfo(Ray ray)
{
    Geometry::IntersectionInfo IntersectInfo;
    IntersectInfo = this->Plane::getIntersectionInfo(ray);
    if (!IntersectInfo.hit) return IntersectInfo; //wenn nicht mit Ebene geschnitten, dann auch nicht mit Dreieck
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

#endif
