#include "integrator.h"

Integrator::Integrator(int width, int height, int depth, World* newWorld, QString integrator){
    this->width = width;
    this->height= height;
    this->depth = depth;
    this->world = newWorld;
    this->integrator = integrator;

    this->isRendering = false;
    this->spp = 0;

    PT = new Pathtracer(this->width,this->height,this->depth, this->world);

    RT = new RayTracer(this->width,this->height,this->depth, this->world);
}

void Integrator::run(){
    if(integrator == "pathtracer")
        PathTrace();
    else if(integrator == "raytracer")
        RayTrace();
    else
        std::cerr << "Integrator::run(): no known integrator" << std::endl;
}

void Integrator::stop(){
    isRendering = false;
    wait();
}

void Integrator::RayTrace(){
    isRendering = true;

    renderOutput = RT->render();

    emit passFinished(renderOutput);
    isRendering = false;
}

void Integrator::PathTrace(){
    isRendering = true;

    while(isRendering == true){
        renderOutput = PT->render();
        spp += 1;
        emit passFinished(renderOutput, spp);
    }
    isRendering = false;
}

Integrator::~Integrator()
{
    RT->~RayTracer();
    PT->~Pathtracer();
}

