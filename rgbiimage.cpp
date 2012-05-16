#include "rgbiimage.h"

RgbiImage::RgbiImage(long width, long height)
{
    for(int y = 0; y < height; y++)
    {
        QVector<renderPixel> Row;
        for(int x = 0; x < width; x++)
        {
            renderPixel currPix;
            currPix.r = 1.0;
            currPix.g = 1.0;
            currPix.b = 1.0;
            currPix.i = 0;
            Row.push_back(currPix);
        }
        RgbiImg.push_back(Row);
    }
}

void RgbiImage::setPixel(long x, long y, QVector3D color)
{
    RgbiImg[y][x].i++;
    RgbiImg[y][x].r = pow((pow(RgbiImg[y][x].r,2) * (RgbiImg[y][x].i-1)+ color.x()*color.x())/ RgbiImg[y][x].i,1.0/2) ;
    RgbiImg[y][x].g = pow((pow(RgbiImg[y][x].g,2) * (RgbiImg[y][x].i-1)+ color.y()*color.y())/ RgbiImg[y][x].i,1.0/2);
    RgbiImg[y][x].b = pow((pow(RgbiImg[y][x].b,2) * (RgbiImg[y][x].i-1)+ color.z()*color.z())/ RgbiImg[y][x].i,1.0/2);
}

QVector3D RgbiImage::getPixel(long x, long y)
{
    QVector3D Color;
    Color.setX(RgbiImg[y][x].r);
    Color.setY(RgbiImg[y][x].g);
    Color.setZ(RgbiImg[y][x].b);
    return Color;
}
