#ifndef MATERIAL_H
#define MATERIAL_H

#include <QVector3D>

class Material
{
public:
    //overloaded constructor
    Material();
    Material(QVector3D newColor_Diffuse, QVector3D newColor_Specular);

    QVector3D getDiffuseColor();
    QVector3D getSpecularColor();

private:
    QVector3D Color_Diffuse;
    QVector3D Color_Specular;
};

#endif // MATERIAL_H
