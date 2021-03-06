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

    void setSeed(long);

public slots:
    void stop();

signals:
    void passFinished(QVector<QVector <renderPixel> >);

private:
    int width;
    int height;
    int depth;
    long seed;
    bool isRendering;
    World* world;
    QString integrator;
    QVector< QVector<renderPixel> > RenderOutput;

    Pathtracer *PT;
    RayTracer *RT;
};

#endif // INTEGRATOR_H
