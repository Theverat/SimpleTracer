#include "plane.h"

//######## Something is screwed here!! ###########//

Plane::Plane(QVector3D newOrigin, QVector3D newVector1, QVector3D newVector2)
{
    Origin = newOrigin;
    Vector1 = newVector1;
    Vector2 = newVector2;

    normal = QVector3D::crossProduct(Vector1, Vector2).normalized();
    n0 = QVector3D::dotProduct(Origin, normal);
}

Geometry::IntersectionInfo Plane::getIntersectionInfo(Ray ray){

    Geometry::IntersectionInfo results;

    if(QVector3D::dotProduct(ray.getDirection(), normal) != 0){
        results.hit = true;

        double lambda = (ray.getOrigin().x() * normal.x() +
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
