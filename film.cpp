#include "film.h"

Film::Film(int width, int height)
{
    this->RenderedImage = new RgbiImage(width, height);
    spp = 0;
}

QImage Film::getImage(){
    return RenderedImage->tonemap();
}

void Film::addSamples(QVector<QVector <renderPixel> > inputImage){

    QMutexLocker locker(&lock);
    for(int y = 0; y < RenderedImage->getHeight(); y++){
        for(int x = 0; x < RenderedImage->getWidth(); x++){
            QVector3D Color = QVector3D(inputImage[x][y].r, inputImage[x][y].g, inputImage[x][y].b);
            RenderedImage->setPixel(x, y, Color);
        }
    }
    spp++;
    std::cout << "pass finished - spp: " << spp << std::endl;
}

float Film::getSamplesPerPixel(){
    return spp;
}

Film::~Film(){
    delete RenderedImage;
}
