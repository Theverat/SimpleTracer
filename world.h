#ifndef WORLD_H
#define WORLD_H

#include <QColor>
#include <QVector>

#include "camera.h"
#include "object.h"
#include "light.h"

class Object;
class Light;

class World
{
public:
    World(Camera *newCamera);

    Camera* getCamera();
    void setCamera(Camera* newCam);

    QVector<Object*>& getObjects();
    QVector<Light*>& getLights();

private:
    QColor BgColor;

    QVector<Object*> objects;
    QVector<Light*> lights;

    Camera* cam;
};

#endif // WORLD_H
