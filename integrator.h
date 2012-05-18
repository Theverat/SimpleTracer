#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <QThread>

#include "QImage"
#include "raytracer.h"
#include "pathtracer.h"

class Integrator : public QThread
{
    Q_OBJECT
public:
    Integrator(int width,int height,int depth, World *newWorld, QString integrator);
    void RayTrace();
    void PathTrace();
    virtual ~Integrator();

    void run();

public slots:
    void stop();

signals:
    void passFinished(QImage);
    void passFinished(QImage, float);

private:
    int width;
    int height;
    int depth;
    bool isRendering;
    float spp;
    World* world;
    QString integrator;
    QImage renderOutput;

    Pathtracer *PT;
    RayTracer *RT;
};

#endif // INTEGRATOR_H
