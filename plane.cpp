#ifndef PLANE_CPP
#define PLANE_CPP
#include "plane.h"

//######## Something is screwed here!! ###########//
//Edited by inj3ct0r 0705 2256
Plane::Plane(QVector3D newOrigin, QVector3D newVector1, QVector3D newVector2)
{
    Origin = newOrigin;
    Vector1 = newVector1;
    Vector2 = newVector2;

    normal = QVector3D::crossProduct(Vector1, Vector2).normalized();
    /*
    Hier liegt der ( ein? ;) ) Fehler: aus der Merkhilfe hast du dich Gleichung
    n1x1 + n2x2 + n3x3+n0 =0
    hier steht LINKS n0
    wenn du das Ding aus der Parameterform umrechnest, kriegst du aber RECHTS eine Zahl:
    X o n + R1 o n + R2 o n = A o n
    X o n = A o n
    n1x1 + n2x2 + n3x3 = A o n
    => n0 = - A 0 n

    Algebra lässt grüßen =P

    n0 = QVector3D::dotProduct(Origin, normal);
    */
    n0 = - QVector3D::dotProduct(Origin, normal);
}

Geometry::IntersectionInfo Plane::getIntersectionInfo(Ray ray){

    Geometry::IntersectionInfo results;

    if(QVector3D::dotProduct(ray.getDirection(), normal) != 0){
        results.hit = true;

        double lambda = -(ray.getOrigin().x() * normal.x() +
                                 ray.getOrigin().y() * normal.y() +
                                 ray.getOrigin().z() * normal.z() +
                                 n0)
                                /
                                (ray.getDirection().x() * normal.x() +
                                ray.getDirection().y() * normal.y() +
                                ray.getDirection().z() * normal.z());

                //calculate the intersection point of ray and plane
                QVector3D hitpoint = ray.getOrigin() + lambda * ray.getDirection();
                results.distance = (hitpoint - ray.getOrigin()).length();
    }

    return results;
}

QVector3D Plane::getNormal(){
    return normal;
}
#endif
