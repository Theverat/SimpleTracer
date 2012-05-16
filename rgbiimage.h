#ifndef RGBIIMAGE_H
#define RGBIIMAGE_H

#include <QVector>
#include <QVector3D>

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
    QVector3D getPixel(long x, long y);

private:
    QVector< QVector<renderPixel> > RgbiImg;
};

#endif // RGBIIMAGE_H
