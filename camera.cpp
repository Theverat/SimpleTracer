#include "camera.h"

Camera::Camera(QVector3D newOrig,  QVector3D newDir, int W, int H, float newFocal_Length):
    far_clipping(9999999999999)
{
    Origin = newOrig;
    Direction = newDir.normalized();
    imgwidth = W;
    imgheigth = H;
    Focal_Length = newFocal_Length * 10.0;
}


Ray Camera::shootRay(int x, int y){

    //Original, static
    double HitOfRay_X = (-(double)imgwidth)/2 + ((double)x);
    double HitOfRay_Y = ((double)imgheigth)/2 - ((double)y);

    QVector3D rayDir = QVector3D(HitOfRay_X, HitOfRay_Y, Focal_Length);
    rayDir.normalize();

    return Ray(Origin, rayDir);
}

int Camera::getImgWidth(){
    return imgwidth;
}

int Camera::getImgHeigth(){
    return imgheigth;
}

float Camera::getFarClip(){
    return far_clipping;
}
