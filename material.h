#ifndef MATERIAL_H
#define MATERIAL_H

#include <QVector3D>

class Material
{
public:
    //overloaded constructor
    Material();
    Material(QVector3D newColor_Diffuse);

    QVector3D getDiffuseColor();

private:
    QVector3D Color_Diffuse;
};

#endif // MATERIAL_H
