#include "integrator.h"

Integrator::Integrator(int width,int height, int depth){
    this->width = width;
    this->height= height;
    this->depth = depth;

    PT = new Pathtracer(this->width,this->height,this->depth);

    RT = new RayTracer(this->width,this->height,this->depth);
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
