#include "camera.h"

Camera::Camera(QVector3D newOrig,  int W, int H):
    far_clipping(9999999999999)
{
    Origin = newOrig;
    imgwidth = W;
    imgheigth = H;
}


Ray Camera::shootRay(int x, int y){

    double HitOfRay_X = (-(double)imgwidth / 200) + ((double)x/100);
    double HitOfRay_Y = ((double)imgheigth / 200) - ((double)y/100);

    QVector3D dir = QVector3D(HitOfRay_X, HitOfRay_Y, 5);
    dir.normalize();

    return Ray(Origin, dir);
}

int Camera::getImgWidth(){
    return imgwidth;
}

int Camera::getImgHeigth(){
    return imgheigth;
}

double Camera::getFarClip(){
    return far_clipping;
}
