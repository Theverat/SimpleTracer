#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    imgwidth(800),
    imgheight(600),
    depth(8),
    tracer(0)
{
    ui->setupUi(this);

    //connect render buttons
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(StartStopRender()));
    connect(ui->DepthBox, SIGNAL(valueChanged(int)), this, SLOT(DepthChanged(int)));

    //connect load/save actions
    connect(ui->actionOpen_Scene_File, SIGNAL(triggered()), this, SLOT(openSceneFile()));
    connect(ui->actionSave_rendered_Image, SIGNAL(triggered()), this, SLOT(saveImageFile()));

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    render = false;
    tracer = new Integrator(imgwidth, imgheight, depth);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartStopRender(){
    if(render){
        render = !render;
        ui->pushButton->setText("Start Render");
        ui->DepthBox->setDisabled(false);
    } else {
        render = !render;
        ui->pushButton->setText("Stop Render");
        ui->DepthBox->setDisabled(true);
        startRender();
    }
}

void MainWindow::startRender(){
    Render();
}

void MainWindow::Render(){
    ui->graphicsView->scene()->setSceneRect(0, 0, imgwidth, imgheight);

    while(render)
    {
        ui->graphicsView->scene()->clear();
        ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(tracer->PathTrace()));
        QCoreApplication::processEvents();
    }
}

//void MainWindow::updateLine(QImage* line){
//    ui->graphicsView->scene()->clear();
//    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*line));
//}

void MainWindow::updateRender(QImage *render){
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(*render));
}

void MainWindow::DepthChanged(int newDepth){
    depth = newDepth;
}

void MainWindow::openSceneFile(){
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open SimpleTracer scenefile"),
                                                    ".",
                                                    tr("SimpleTracer scenefiles (*.sts)"));
    if(!filename.isEmpty())
        loadSceneFile(filename);
}

bool MainWindow::loadSceneFile(const QString &fileName){
    QFile file(fileName);
    QString line;

    if(file.open(QIODevice::ReadOnly | QIODevice::Text)){
        std::cout << "file opened" << std::endl;

        QTextStream textStream(&file);

        while(!textStream.atEnd()){
            line = textStream.readLine(0);

            //parse line, parser function will get called here

            ui->SceneFileTextBrowser->append(line);
        }

        file.close();
        std::cout << "file closed" << std::endl;
    }
}

void MainWindow::saveImageFile(){
    QImage img(imgwidth, imgheight, QImage::Format_ARGB32_Premultiplied);
    QPainter p(&img);
    ui->graphicsView->scene()->render(&p);
    p.end();
    img.save(QFileDialog::getSaveFileName(this,
                                          tr("Save LDR Image"),
                                          ".",
                                          tr("All image files")));
}
