#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QImage>
#include <QColor>
#include <QSharedPointer>
#include <QVector3D>
#include <iostream>
#include <QObject>
#include <QThread>

#include "predefs.h"

#include "sphere.h"
#include "camera.h"
#include "object.h"
#include "world.h"

class RayTracer : public QThread
{
    Q_OBJECT
public:
    RayTracer(int x, int y);

    void render();
    QColor getColorForPixel(int x, int y);
    QVector3D raytrace(Ray ray);

signals:
    void returnImage(QImage*);

private:
    QSharedPointer<QImage> renderImage;

    World *world;

    QVector3D Render_Normal(double distance, Ray ray, Object *obj);
};

#endif // RAYTRACER_H
