#include "worldloader.h"

Worldloader::Worldloader(){
    //initialize a standard world
    world = new World(new Camera(QVector3D(0, 0, 0), QVector3D(0, 0, 0), 100, 100, 5), QVector3D(0, 0, 0), 1.0);
}

Worldloader::Worldloader(World *newWorld)
{
    world = newWorld;
}

World* Worldloader::getWorld(){
    return world;
}

void Worldloader::setWorld(World *newWorld){
    world = newWorld;
    LOG("new world set")
}
