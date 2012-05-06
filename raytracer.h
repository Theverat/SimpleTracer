#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <QImage>
#include <QColor>
#include <QSharedPointer>
#include <QVector3D>
#include <iostream>
#include <QObject>
#include <QThread>

#include "sphere.h"
#include "camera.h"

class RayTracer : public QThread
{
    Q_OBJECT
public:
    RayTracer(int x, int y);

    void raytrace();
    QColor getColorForPixel(int x, int y);

signals:
    void returnImage(QImage*);

private:
    QSharedPointer<QImage> renderImage;

    Sphere *sphere;
    Camera *camera;
};

#endif // RAYTRACER_H
