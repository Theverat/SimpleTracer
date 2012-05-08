#ifndef MATERIAL_H
#define MATERIAL_H

#include <QVector3D>

class Material
{
public:
    //overloaded constructor
    Material();
    Material(QVector3D newColor_Diffuse, QVector3D newColor_Specular, float newExponent, float newReflectionAmount, bool newTransparency, double newIoR);

    QVector3D getDiffuseColor();
    QVector3D getSpecularColor();
    float getExponent();
    float getReflectionAmount();
    bool getTransparency();
    double getIoR();

private:
    QVector3D Color_Diffuse;
    QVector3D Color_Specular;
    float exponent;
    float reflectionAmount;
    bool transparent;
    double IoR;
};

#endif // MATERIAL_H
