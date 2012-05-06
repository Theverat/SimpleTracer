#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    imgwidth(800),
    imgheight(600),
    tracer(0)
{
    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(startRender()));

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startRender(){
    std::cout << "startRender() function starts" << std::endl;

    ui->graphicsView->scene()->setSceneRect(0, 0, imgwidth, imgheight);

    tracer = new RayTracer(imgwidth, imgheight);
    QObject::connect(tracer, SIGNAL(returnImage(QImage*)), this, SLOT(updateRender(QImage*)));

    tracer->raytrace();
}

void MainWindow::updateRender(QImage *render){
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*render));
}
