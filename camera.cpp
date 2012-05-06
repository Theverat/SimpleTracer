#include "camera.h"

Camera::Camera(QVector3D newOrig,  int W, int H){
    Origin = newOrig;
    imgwidth = W;
    imgheigth = H;
}


Ray Camera::shootRay(int x, int y){

    double HitOfRay_X = (-(double)imgwidth / 200) + ((double)x/100);
    double HitOfRay_Y = ((double)imgheigth / 200) - ((double)y/100);

    QVector3D pos = QVector3D(HitOfRay_X, HitOfRay_Y, 5);
    pos.normalize();

    return Ray(Origin, pos);
}

int Camera::getImgWidth(){
    return imgwidth;
}

int Camera::getImgHeigth(){
    return imgheigth;
}
