#include "material.h"

Material::Material()
{
    //initialise all variables with default values
    Color_Diffuse = QVector3D(50, 50, 50);
    Color_Specular = QVector3D(50, 50, 50);
}

Material::Material(QVector3D newColor_Diffuse, QVector3D newColor_Specular){
    Color_Diffuse = newColor_Diffuse;
    Color_Specular = newColor_Specular;
}

QVector3D Material::getDiffuseColor(){
    return Color_Diffuse;
}

QVector3D Material::getSpecularColor(){
    return Color_Specular;
}
