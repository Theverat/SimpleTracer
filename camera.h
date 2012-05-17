#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <QMatrix4x4>

#include "ray.h"


class Camera
{
public:
    Camera(QVector3D newOrig, QVector3D newDir, int W, int H, float newFocal_Length);

    Ray shootRay(int current_x, int current_y);

    int getImgWidth();
    int getImgHeigth();
    float getFarClip();
    QVector3D getOrigin(){return CamOrigin;}
    QVector3D getDirection(){return CamDirection;}

private:
    QMatrix4x4 viewmatrix;

    QVector3D CamOrigin;
    QVector3D CamDirection;

    int imgwidth;
    int imgheigth;
    float focal_length;
    float far_clip;
    float aspect_ratio;
};

#endif // CAMERA_H
