#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include <iostream>

class Camera
{
public:
    Camera(QVector3D newOrig, int W, int H);

    Ray shootRay(int x, int y);

    int getImgWidth();
    int getImgHeigth();

private:
    QVector3D Origin;

    int imgwidth;
    int imgheigth;
};

#endif // CAMERA_H
