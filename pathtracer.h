#ifndef PATHTRACER_H
#define PATHTRACER_H

#include <QImage>
#include <QColor>
#include <QSharedPointer>
#include <QVector3D>
#include <iostream>
#include <QObject>
#include <QThread>
#include <QTime>

#include "predefs.h"

#include "sphere.h"
#include "camera.h"
#include "object.h"
#include "world.h"
#include "rgbiimage.h"

class Pathtracer
{
public:
    Pathtracer(int x, int y, uint newDepth, World* newWorld);
    QVector< QVector<renderPixel> > render();
    virtual ~Pathtracer();

    long seed;

private:
    QImage *renderImage;
    World *world;
    uint depth;
    //RgbiImage *RenderOut;
    QVector< QVector<renderPixel> > RenderedSamples;

    QColor getColorForPixel(int x, int y);
    QVector3D tracer(Ray ray, uint current_depth);
    QColor clampColor(QVector3D hdr);
};

#endif // PATHTRACER_H
