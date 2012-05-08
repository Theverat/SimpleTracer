#include "material.h"

Material::Material()
{
    //initialise all variables with default values
    Color_Diffuse = QVector3D(50, 50, 50);
    Color_Specular = QVector3D(50, 50, 50);
    exponent = 20;
    reflectionAmount = 0;
    transparent = false;
}

Material::Material(QVector3D newColor_Diffuse, QVector3D newColor_Specular, float newExponent, float newReflectionAmount, bool newTransparency, double newIoR){
    Color_Diffuse = newColor_Diffuse;
    Color_Specular = newColor_Specular;
    exponent = newExponent;
    reflectionAmount = newReflectionAmount;
    transparent = newTransparency;
    IoR = newIoR;
}

QVector3D Material::getDiffuseColor(){
    return Color_Diffuse;
}

QVector3D Material::getSpecularColor(){
    return Color_Specular;
}

float Material::getExponent(){
    return exponent;
}

float Material::getReflectionAmount(){
    return reflectionAmount;
}

bool Material::getTransparency(){
    return transparent;
}

double Material::getIoR(){
    return IoR;
}
