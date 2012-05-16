#include "camera.h"

Camera::Camera(QVector3D newOrig,  QVector3D newDir, int W, int H, float newFocal_Length):
    far_clip(9999999999999)
{
    CamOrigin = newOrig;
    CamDirection = newDir.normalized();
    imgwidth = W;
    imgheigth = H;
    focal_length = newFocal_Length/10;
    aspect_ratio = (float)imgwidth/imgheigth;
}

/*
Ray Camera::shootRay(int x, int y){

    //Original, static
    double HitOfRay_X = (-(double)imgwidth)/2 + ((double)x);
    double HitOfRay_Y = ((double)imgheigth)/2 - ((double)y);

    QVector3D rayDir = QVector3D(HitOfRay_X, HitOfRay_Y, Focal_Length);
    rayDir.normalize();

    return Ray(Origin, rayDir);
}
*/

//new camera transform code
Ray Camera::shootRay(int current_x, int current_y){

    float x = (float)current_x/(imgwidth - 1);
    float y = (float)current_y/(imgheigth - 1);

    x = (x*2)-1;
    //flip y to get +y up, -y down
    y = 1-y;
    y = (y*2)-1;

    QMatrix4x4 cam_transf;
    x *= aspect_ratio;

    QVector3D viewportdir(x, y, -focal_length);
    viewportdir.normalize();

    cam_transf.lookAt(CamOrigin, CamOrigin + CamDirection, QVector3D(0,1,0));
    bool invertible;
    QVector3D rayDir = cam_transf.inverted(&invertible).mapVector(viewportdir);

    return Ray(CamOrigin, rayDir);
}

int Camera::getImgWidth(){
    return imgwidth;
}

int Camera::getImgHeigth(){
    return imgheigth;
}

float Camera::getFarClip(){
    return far_clip;
}
