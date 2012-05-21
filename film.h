#ifndef FILM_H
#define FILM_H

#include <QMutex>
#include <QMutexLocker>
#include <QThread>

#include "predefs.h"
#include "rgbiimage.h"

class Film : public QThread
{
    Q_OBJECT

public:
    Film(int width, int height);
    ~Film();

    QImage getImage();
    float getSamplesPerPixel();

public slots:
    void addSamples(QVector<QVector<renderPixel> >);

private:
    RgbiImage* RenderedImage;
    float spp;
    QMutex lock;
};

#endif // FILM_H
