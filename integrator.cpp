#include "integrator.h"

Integrator::Integrator(int width, int height, int depth, World* newWorld, QString integrator){
    this->width = width;
    this->height= height;
    this->depth = depth;
    this->world = newWorld;
    this->integrator = integrator;

    this->isRendering = false;

    PT = new Pathtracer(this->width,this->height,this->depth, this->world);

    RT = new RayTracer(this->width,this->height,this->depth, this->world);

    std::cout << "Integrator: Thread with ID " << currentThreadId() << " created" << std::endl;
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
    std::cout << "Raytracing is currently disabled" << std::endl;
    //isRendering = true;

    //RenderOutput = RT->render();

    //emit passFinished(RT->render());
    //isRendering = false;
}

void Integrator::PathTrace(){
    isRendering = true;
    std::cout << "Integrator: Thread with ID " << currentThreadId() << " started" << std::endl;

    while(isRendering == true){
        //RenderOutput = PT->render();
        emit passFinished(PT->render());
    }
    isRendering = false;
}

Integrator::~Integrator()
{
    RT->~RayTracer();
    PT->~Pathtracer();
}

