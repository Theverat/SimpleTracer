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

    //testobjects (now in world.cpp)
    //Object *object; //remove later
    //Object *plane; //remove later

    World *world;
    Camera *camera;

    //render functions (like Render_DiffuseShading, Render_GlossyShading etc.)
    QVector3D Render_Normal(double distance, Ray ray, Object *obj);
    QVector3D Render_DiffuseColor(Object *obj);
};

#endif // RAYTRACER_H
