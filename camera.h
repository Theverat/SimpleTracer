#ifndef CAMERA_H
#define CAMERA_H

#include "ray.h"
#include <iostream>

class Camera
{
public:
    Camera(QVector3D newOrig, QVector3D newDir, int W, int H, float newFocal_Length);

    Ray shootRay(int x, int y);

    int getImgWidth();
    int getImgHeigth();
    float getFarClip();

private:
    QVector3D Origin;
    QVector3D Direction;

    int imgwidth;
    int imgheigth;

    float Focal_Length;
    float far_clipping;
};

#endif // CAMERA_H
