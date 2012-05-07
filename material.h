#ifndef MATERIAL_H
#define MATERIAL_H

#include <QVector3D>

class Material
{
public:
    //overloaded constructor
    Material();
    Material(QVector3D newColor_Diffuse, QVector3D newColor_Specular, float newExponent, float newReflectionAmount);

    QVector3D getDiffuseColor();
    QVector3D getSpecularColor();
    float getExponent();
    float getReflectionAmount();

private:
    QVector3D Color_Diffuse;
    QVector3D Color_Specular;
    float exponent;
    float reflectionAmount;
};

#endif // MATERIAL_H
