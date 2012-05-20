#ifndef RGBIIMAGE_H
#define RGBIIMAGE_H

#include <QVector3D>
#include <QImage>
#include <QColor>

#include <math.h>

struct renderPixel
{
    double r,g,b;
    long long i;
};

class RgbiImage
{
public:
    RgbiImage(long width,long height);
    void setPixel(long x, long y, QVector3D color);
    QImage tonemap();
    QColor getPixel(long x, long y, double factor);
    QVector3D getSample(long x, long y);
    long getWidth();
    long getHeight();

private:
    QVector< QVector<renderPixel> > RgbiImg;
    long width,height;
    QImage *renderImage;
};

#endif // RGBIIMAGE_H
