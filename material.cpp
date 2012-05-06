#include "material.h"

Material::Material()
{
    //initialise all variables with default values
    Color_Diffuse = QColor(100, 0, 0);
}

Material::Material(QColor newColor_Diffuse){
    Color_Diffuse = newColor_Diffuse;
}

QColor Material::getDiffuseColor(){
    return Color_Diffuse;
}
