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

    Integrator* tracer;
    Worldloader worldloader;

    void startRender();
    void Render();

    bool loadSceneFile(const QString &fileName);

private slots:

    //void updateLine(QImage*); //slows down the render
    void updateRender(QImage*);
    void StartStopRender();

    void DepthChanged(int);

    void openSceneFile();
    void saveImageFile();

    void changeWorldBgColor();
};

#endif // MAINWINDOW_H
