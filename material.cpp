#include "material.h"

Material::Material()
{
    //initialise all variables with default values
    Color_Diffuse = QVector3D(100, 0, 0);
}

Material::Material(QVector3D newColor_Diffuse){
    Color_Diffuse = newColor_Diffuse;
}

QVector3D Material::getDiffuseColor(){
    return Color_Diffuse;
}
