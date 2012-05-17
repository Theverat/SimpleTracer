#include "rgbiimage.h"

RgbiImage::RgbiImage(long width, long height)
{
    renderImage = new QImage(width, height, QImage::Format_ARGB32);
    this->width = width;
    this->height= height;

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

QColor RgbiImage::getPixel(long x, long y,double factor)
{
    QColor Color;
    Color.setRed((int)(RgbiImg[y][x].r*factor*255.0));
    Color.setGreen((int)(RgbiImg[y][x].g*factor*255.0));
    Color.setBlue((int)(RgbiImg[y][x].b*factor*255.0));
    Color.setAlpha(255);
    return Color;
}

QImage RgbiImage::tonemap()
{
    double greatestValue;
    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            if(RgbiImg[y][x].r > greatestValue)
            {
                greatestValue = RgbiImg[y][x].r;
            }
            if(RgbiImg[y][x].g > greatestValue)
            {
                greatestValue = RgbiImg[y][x].g;
            }
            if(RgbiImg[y][x].b > greatestValue)
            {
                greatestValue = RgbiImg[y][x].b;
            }
        }
    }

    double factor = 1.0/greatestValue;

    for(int x = 0; x < width; x++)
    {
        for(int y = 0; y < height; y++)
        {
            renderImage->setPixel(x, y, this->getPixel(x,y,factor).rgba());
        }
    }

    return *renderImage;

}
