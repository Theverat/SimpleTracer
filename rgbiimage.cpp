#include "rgbiimage.h"

RgbiImage::RgbiImage(long width, long height)
{
    for(int y = 0; y < height; y++)
    {
        QVector<renderPixel> Row;
        for(int x = 0; x < width; x++)
        {
            renderPixel currPix;
            currPix.r = 0.0;
            currPix.g = 0.0;
            currPix.b = 0.0;
            currPix.i = 0;
            Row.push_back(currPix);
        }
        RgbiImg.push_back(Row);
    }
}

void RgbiImage::setPixel(long x, long y, QVector3D color)
{
    RgbiImg[y][x].i++;
    RgbiImg[y][x].r = (RgbiImg[y][x].r*RgbiImg[y][x].i + color.x()) / (RgbiImg[y][x].i);
    RgbiImg[y][x].g = (RgbiImg[y][x].g*RgbiImg[y][x].i + color.y()) / (RgbiImg[y][x].i);
    RgbiImg[y][x].b = (RgbiImg[y][x].b*RgbiImg[y][x].i + color.z()) / (RgbiImg[y][x].i);
}

QVector3D RgbiImage::getPixel(long x, long y)
{
    QVector3D Color;
    Color.setX(RgbiImg[y][x].r);
    Color.setY(RgbiImg[y][x].g);
    Color.setZ(RgbiImg[y][x].b);
    return Color;
}
