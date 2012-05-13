#ifndef MATERIAL_H
#define MATERIAL_H

#include <QVector3D>

class Material
{
public:
    //overloaded constructor
    Material();
    Material(QVector3D newColor_Diffuse, QVector3D newColor_Specular, float newExponent, float newReflectionAmount, bool clayDiffuse, double newIoR, double Emit);

    QVector3D getDiffuseColor();
    QVector3D getSpecularColor();
    float getExponent();
    float getReflectionAmount();
    bool getTransparency();
    double getIoR();
    double getEmit();

private:
    QVector3D Color_Diffuse;
    QVector3D Color_Specular;
    float exponent;
    float reflectionAmount;
    bool transparent;
    double IoR;
    double Emit;
};

#endif // MATERIAL_H
