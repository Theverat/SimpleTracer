#include "light.h"

Light::Light(QVector3D newPosition, QVector3D newColor, double newIntensity)
{
    position = newPosition;
    color = newColor;
    intensity = newIntensity;
}

QVector3D Light::getPosition(){
    return position;
}

QVector3D Light::getColor(){
    return color;
}

double Light::getIntensity(){
    return intensity;
}
