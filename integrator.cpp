#include "integrator.h"

Integrator::Integrator(int width,int height, int depth){
    this->width = width;
    this->height= height;
    this->depth = depth;


}


QImage Integrator::RayTrace(){
    QImage renderOutput;
    RayTracer *tracer;

    tracer = new RayTracer(this->width,this->height,this->depth);
    renderOutput = tracer->render();
    tracer->~RayTracer();


    return renderOutput;
}

QImage Integrator::PathTrace(){
    QImage renderOutput;
    Pathtracer *tracer;

    tracer = new Pathtracer(this->width,this->height,this->depth);
    renderOutput = tracer->render();
    tracer->~Pathtracer();


    return renderOutput;
}
