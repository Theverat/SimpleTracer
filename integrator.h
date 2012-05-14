#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "QImage"
#include "raytracer.h"
#include "pathtracer.h"

class Integrator
{
public:
    Integrator(int width,int height,int depth);
    QImage RayTrace();
    QImage PathTrace();

private:
    int width;
    int height;
    int depth;
};

#endif // INTEGRATOR_H
