#ifndef ABS
#define ABS
#include <QVector3D>
#include <math.h>
#define vec QVector3D

vec vec_abs (vec in)
{
   vec ret;
   ret.setX(fabs(in.x()));
   ret.setY(fabs(in.y()));
   ret.setZ(fabs(in.z()));
   return ret;
}

#endif
