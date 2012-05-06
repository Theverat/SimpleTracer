#ifndef LIGHT_H
#define LIGHT_H

#include <QVector3D>

class Light
{
public:
    Light(QVector3D newPosition, QVector3D newColor, double newIntensity);

    QVector3D getPosition();
    QVector3D getColor();
    double getIntensity();

private:
    QVector3D position;
    QVector3D color;    //not a QColor because it's easier
                        //to calculate with vectors, e.g. when multiplying colors
    double intensity; //brightness of the lightsource
};

#endif // LIGHT_H
