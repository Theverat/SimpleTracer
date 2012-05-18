#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QGraphicsScene>
#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QColorDialog>
#include <QTimer>

#include "integrator.h"
#include "worldloader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;

    int imgwidth;
    int imgheight;
    float focalLength;
    int depth;
    QVector3D BgColor;

    bool render;
    bool cameraChanged;
    float spp;

    Integrator* tracer;
    Worldloader worldloader;
    Camera* cam;
    QTimer *timer;
    QTime t;

    void Render();

    bool loadSceneFile(const QString &fileName);

private slots:
    void updateStatusBar();
    void updateRender(QImage, float spp);
    void updateRender(QImage);
    void StartStopRender();

    void DepthChanged(int);

    void openSceneFile();
    void saveImageFile();

    void changeWorldBgColor();

    //camera change functions
    void moveCamUp();
    void moveCamRight();
    void moveCamDown();
    void moveCamLeft();
    void moveCamBack();
    void moveCamForw();
    void changeFocalLength(int);
    void rotCamUp();
    void rotCamRight();
    void rotCamDown();
    void rotCamLeft();
};

#endif // MAINWINDOW_H
