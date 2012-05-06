#ifndef RAY_H
#define RAY_H

#include <QVector3D>

class Ray
{
public:
    Ray(QVector3D newOrig, QVector3D newDir){Direction = newDir; Origin = newOrig;}

    QVector3D getDirection(){return Direction;}
    QVector3D getOrigin(){return Origin;}

    void setDirection(QVector3D newDir){Direction = newDir;}
    void setOrigin(QVector3D newOrig){Origin = newOrig;}

private:
    QVector3D Direction;
    QVector3D Origin;
};

#endif // RAY_H
