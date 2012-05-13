#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <QGraphicsScene>
#include <QObject>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

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
    bool render;

    RayTracer* tracer;

    bool loadSceneFile(const QString &fileName);

private slots:
    void startRender();
    //void updateLine(QImage*); //slows down the render
    void updateRender(QImage*);

    void DepthChanged(int);

    void openSceneFile();
    void saveImageFile();
    void on_pushButton_2_clicked();
};

#endif // MAINWINDOW_H
