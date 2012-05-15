#include "integrator.h"

Integrator::Integrator(int width,int height, int depth, World* newWorld){
    this->width = width;
    this->height= height;
    this->depth = depth;
    this->world = newWorld;

    PT = new Pathtracer(this->width,this->height,this->depth, this->world);

    RT = new RayTracer(this->width,this->height,this->depth, this->world);
}


QImage Integrator::RayTrace(){
    QImage renderOutput;

    renderOutput = RT->render();

    return renderOutput;
}

QImage Integrator::PathTrace(){
    QImage renderOutput;

    renderOutput = PT->render();

    return renderOutput;
}

Integrator::~Integrator()
{
    RT->~RayTracer();
    PT->~Pathtracer();
}
