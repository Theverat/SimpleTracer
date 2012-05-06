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
#include "object.h"

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

    //testobjects:
    Object *object; //remove later
    Object *plane; //remove later

    Camera *camera;

    //render functions (like Render_DiffuseShading, Render_GlossyShading etc.)
    QColor Render_Normal(Geometry::IntersectionInfo Info, Ray ray);
    QColor Render_DiffuseColor();
};

#endif // RAYTRACER_H
