#ifndef WORLDLOADER_H
#define WORLDLOADER_H

#include "predefs.h"
#include "world.h"

class Worldloader
{
public:
    Worldloader();
    Worldloader(World* newWorld);

    World *getWorld();
    void setWorld(World* newWorld);
private:
    World* world;
};

#endif // WORLDLOADER_H
