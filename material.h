#ifndef MATERIAL_H
#define MATERIAL_H

#include <QColor>

class Material
{
public:
    //overloaded constructor
    Material();
    Material(QColor newColor_Diffuse);

    QColor getDiffuseColor();

private:
    QColor Color_Diffuse;
};

#endif // MATERIAL_H
