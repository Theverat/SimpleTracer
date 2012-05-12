#ifndef ABS
#define ABS
#include <QVector3D>
#include <math.h>

QVector3D vec_abs (QVector3D in)
{
   QVector3D ret;
   ret.setX(fabs(in.x()));
   ret.setY(fabs(in.y()));
   ret.setZ(fabs(in.z()));
   return ret;
}

#endif
