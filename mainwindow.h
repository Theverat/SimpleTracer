#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QGraphicsScene>
#include <QObject>

#include "raytracer.h"

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
    int depth;

    RayTracer* tracer;

private slots:
    void startRender();
    //void updateLine(QImage*); //slows down the render
    void updateRender(QImage*);

    void DepthChanged(int);
};

#endif // MAINWINDOW_H
