#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
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

    //connect camera move buttons
    connect(ui->up, SIGNAL(clicked()), this, SLOT(moveCamUp()));
    connect(ui->right, SIGNAL(clicked()), this, SLOT(moveCamRight()));
    connect(ui->down, SIGNAL(clicked()), this, SLOT(moveCamDown()));
    connect(ui->left, SIGNAL(clicked()), this, SLOT(moveCamLeft()));
    connect(ui->backwards, SIGNAL(clicked()), this, SLOT(moveCamBack()));
    connect(ui->forwards, SIGNAL(clicked()), this, SLOT(moveCamForw()));
    connect(ui->focalLengthSlider, SIGNAL(valueChanged(int)), this, SLOT(changeFocalLength(int)));
    connect(ui->up_2, SIGNAL(clicked()), this, SLOT(rotCamUp()));
    connect(ui->right_2, SIGNAL(clicked()), this, SLOT(rotCamRight()));
    connect(ui->down_2, SIGNAL(clicked()), this, SLOT(rotCamDown()));
    connect(ui->left_2, SIGNAL(clicked()), this, SLOT(rotCamLeft()));

    //get start time
    t.start();

    //connect timer
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateStatusBar()));

    //connect world backgroundcolor change button
    connect(ui->pushButton_BgColor, SIGNAL(clicked()), this, SLOT(changeWorldBgColor()));
    QGraphicsScene* BgColorDisplayScene = new QGraphicsScene(this);
    ui->graphicsView_BgColorDisplay->setScene(BgColorDisplayScene);
    ui->graphicsView_BgColorDisplay->scene()->setBackgroundBrush(QBrush(QColor(Qt::black)));

    //the scene that holds the rendered image
    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(QImage("Icon/ST-Background.png")));

    render = false;
    cameraChanged = false;
    spp = 0;
    cam = new Camera(QVector3D(0, 0, -5), QVector3D(0, 0, 1), imgwidth, imgheight, focalLength);

    imgwidth = ui->spinBox_imgres_x->value();
    imgheight = ui->spinBox_imgres_y->value();
    focalLength = ui->doubleSpinBox_focal_length->value();
}

MainWindow::~MainWindow()
{
    StartStopRender();
    delete ui;
}

void MainWindow::StartStopRender(){
    if(render){
        render = !render;
        ui->pushButton->setText("Start Render");
        tracer->stop();
        timer->stop();
    } else {
        render = !render;
        ui->pushButton->setText("Stop Render");
        Render();
    }
}

/*
void MainWindow::Render(){

    //read values from the gui settings
    imgwidth = ui->spinBox_imgres_x->value();
    imgheight = ui->spinBox_imgres_y->value();
    focalLength = ui->doubleSpinBox_focal_length->value();

    //"old" camera position and roation
    //worldloader.setWorld(new World(new Camera(QVector3D(0, 0, -5), QVector3D(0, 0, 1), imgwidth, imgheight, focalLength), BgColor, 1.0));
    //"new" camera position and roation
    worldloader.setWorld(new World(new Camera(QVector3D(0, 0, -5), QVector3D(0, 0, 10), imgwidth, imgheight, focalLength), BgColor, 1.0));

    //create the Integrator instance
    tracer = new Integrator(imgwidth, imgheight, depth, worldloader.getWorld());

    ui->graphicsView->scene()->setSceneRect(0, 0, imgwidth, imgheight);

    //values for the status bar messages
    QTime t;
    t.start();
    QTime elapsedTime = QTime(0, 0);
    int spp = 0;

    //start the render with the chosen Integrator

    //Integrator: Raytracer
    if(ui->radioButton_Raytracer->isChecked()){
        LOG("Integrator: Raytracer")

        ui->graphicsView->scene()->clear();
        ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(tracer->RayTrace()));

        //calculate the time the render is already running
        int ms = t.elapsed();
        int s  = ms / 1000;    ms %= 1000;
        int m  = s  / 60;      s  %= 60;
        int h  = m  / 60;      m  %= 60;
        elapsedTime = QTime(h, m, s);

        //statusbar update after the render is finished
        ui->statusBar->showMessage("elapsed Time: " + elapsedTime.toString());

        render = true;
        StartStopRender();
    }

    //Integrator: Pathtracer
    if(ui->radioButton_Pathtracer->isChecked()){
        LOG("Integrator: Pathtracer")

        int i = 1;
        while(render)
        {
            ui->graphicsView->scene()->clear();
            ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(tracer->PathTrace()));

            //calculate the time the render is already running
            int ms = t.elapsed();
            int s  = ms / 1000;    ms %= 1000;
            int m  = s  / 60;      s  %= 60;
            int h  = m  / 60;      m  %= 60;
            elapsedTime = QTime(h, m, s);

            //calculate the samples per pixel
            spp++;

            //statusbar update after each pass
            ui->statusBar->showMessage("elapsed Time: " + elapsedTime.toString() + " | Samples per Pixel: " + QString::number(spp));
            std::cout << "Samples per Pixel: " << spp << std::endl;

            QCoreApplication::processEvents();

            if(cameraChanged){
                worldloader.getWorld()->setCamera(cam);
                cameraChanged = false;
                tracer = new Integrator(imgwidth, imgheight, depth, worldloader.getWorld());
                spp = 0;
                t.start();
            }
        }
    }

}
*/

void MainWindow::Render(){

    if(tracer)
        tracer->stop();

    //read values from the gui settings
    imgwidth = ui->spinBox_imgres_x->value();
    imgheight = ui->spinBox_imgres_y->value();
    if(!cameraChanged)
        focalLength = ui->doubleSpinBox_focal_length->value();

    //"old" camera position and roation
    //worldloader.setWorld(new World(new Camera(QVector3D(0, 0, -5), QVector3D(0, 0, 1), imgwidth, imgheight, focalLength), BgColor, 1.0));
    //"new" camera position and roation
    worldloader.setWorld(new World(new Camera(QVector3D(0, 0, -5), QVector3D(0, 0, 1), imgwidth, imgheight, focalLength), BgColor, 1.0));
    if(cameraChanged){
        worldloader.getWorld()->setCamera(cam);
        cameraChanged = false;
        LOG("new camera set, render restarted")
    }

    ui->graphicsView->scene()->setSceneRect(0, 0, imgwidth, imgheight);

    //start the render with the chosen Integrator

    //Integrator: Raytracer
    if(ui->radioButton_Raytracer->isChecked()){
        LOG("Integrator: Raytracer")

        //create the Integrator instance
        tracer = new Integrator(imgwidth, imgheight, depth, worldloader.getWorld(), "raytracer");
        QObject::connect(tracer, SIGNAL(passFinished(QImage, float)), this, SLOT(updateRender(QImage, float)));
        timer->start(1000);
        tracer->start();
    }

    //Integrator: Pathtracer
    if(ui->radioButton_Pathtracer->isChecked()){
        LOG("Integrator: Pathtracer")

        tracer = new Integrator(imgwidth, imgheight, depth, worldloader.getWorld(), "pathtracer");
        QObject::connect(tracer, SIGNAL(passFinished(QImage, float)), this, SLOT(updateRender(QImage, float)));
        timer->start(1000);
        tracer->start();
    }
}

void MainWindow::updateStatusBar(){
    //calculate the time the render is already running
    int ms = t.elapsed();
    int s  = ms / 1000;    ms %= 1000;
    int m  = s  / 60;      s  %= 60;
    int h  = m  / 60;      m  %= 60;
    QTime elapsedTime = QTime(h, m, s);

    ui->statusBar->showMessage("elapsed Time: " + elapsedTime.toString() + " | Samples per Pixel: " + QString::number(spp));
    std::cout << "Samples per Pixel: " << spp << std::endl;
}

void MainWindow::updateRender(QImage render){
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(render));
}

void MainWindow::updateRender(QImage render, float spp){
    this->spp = spp;
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(render));

    //statusbar update after each pass
    updateStatusBar();
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

void MainWindow::changeWorldBgColor(){
    QColor BgColor_as_QColor;
    QColorDialog mycolordialog;
    BgColor_as_QColor = mycolordialog.getColor();

    BgColor = QVector3D(BgColor_as_QColor.red(), BgColor_as_QColor.green(), BgColor_as_QColor.blue());
    LOG("world's background color set to " << BgColor_as_QColor.red() << " " << BgColor_as_QColor.green() << " " << BgColor_as_QColor.blue());

    ui->graphicsView_BgColorDisplay->scene()->setBackgroundBrush(QBrush(BgColor_as_QColor));
}

//move camera
void MainWindow::moveCamUp(){
    QVector3D newPos = worldloader.getWorld()->getCamera()->getOrigin();
    newPos.setY(newPos.y() + 0.2);
    delete cam;
    cam = new Camera(newPos, worldloader.getWorld()->getCamera()->getDirection(), imgwidth, imgheight, focalLength);
    cameraChanged = true;
    worldloader.getWorld()->setCamera(cam);
    Render();
}

void MainWindow::moveCamRight(){
    QVector3D newPos = worldloader.getWorld()->getCamera()->getOrigin();
    newPos.setX(newPos.x() - 0.2);
    delete cam;
    cam = new Camera(newPos, worldloader.getWorld()->getCamera()->getDirection(), imgwidth, imgheight, focalLength);
    cameraChanged = true;
    Render();
}

void MainWindow::moveCamDown(){
    QVector3D newPos = worldloader.getWorld()->getCamera()->getOrigin();
    newPos.setY(newPos.y() - 0.2);
    delete cam;
    cam = new Camera(newPos, worldloader.getWorld()->getCamera()->getDirection(), imgwidth, imgheight, focalLength);
    cameraChanged = true;
    Render();
}

void MainWindow::moveCamLeft(){
    QVector3D newPos = worldloader.getWorld()->getCamera()->getOrigin();
    newPos.setX(newPos.x() + 0.2);
    delete cam;
    cam = new Camera(newPos, worldloader.getWorld()->getCamera()->getDirection(), imgwidth, imgheight, focalLength);
    cameraChanged = true;
    Render();
}

void MainWindow::moveCamBack(){
    QVector3D newPos = worldloader.getWorld()->getCamera()->getOrigin();
    newPos.setZ(newPos.z() - 0.2);
    delete cam;
    cam = new Camera(newPos, worldloader.getWorld()->getCamera()->getDirection(), imgwidth, imgheight, focalLength);
    cameraChanged = true;
    Render();
}

void MainWindow::moveCamForw(){
    QVector3D newPos = worldloader.getWorld()->getCamera()->getOrigin();
    newPos.setZ(newPos.z() + 0.2);
    delete cam;
    cam = new Camera(newPos, worldloader.getWorld()->getCamera()->getDirection(), imgwidth, imgheight, focalLength);
    cameraChanged = true;
    Render();
}

//change the camera's focal length
void MainWindow::changeFocalLength(int newFL){
    this->focalLength = newFL;
    ui->focalLengthDisplay->setText(QString::number(this->focalLength));
    delete cam;
    cam = new Camera(worldloader.getWorld()->getCamera()->getOrigin(), worldloader.getWorld()->getCamera()->getDirection(), imgwidth, imgheight, focalLength);
    cameraChanged = true;
    Render();
}

//rotate camera
void MainWindow::rotCamUp(){
    QVector3D newDir = worldloader.getWorld()->getCamera()->getDirection();
    newDir.setY(newDir.y() + 0.05);
    delete cam;
    cam = new Camera(worldloader.getWorld()->getCamera()->getOrigin(), newDir, imgwidth, imgheight, focalLength);
    cameraChanged = true;
    worldloader.getWorld()->setCamera(cam);
    Render();
}

void MainWindow::rotCamRight(){
    QVector3D newDir = worldloader.getWorld()->getCamera()->getDirection();
    newDir.setX(newDir.x() - 0.05);
    delete cam;
    cam = new Camera(worldloader.getWorld()->getCamera()->getOrigin(), newDir, imgwidth, imgheight, focalLength);
    cameraChanged = true;
    worldloader.getWorld()->setCamera(cam);
    Render();
}

void MainWindow::rotCamDown(){
    QVector3D newDir = worldloader.getWorld()->getCamera()->getDirection();
    newDir.setY(newDir.y() - 0.05);
    delete cam;
    cam = new Camera(worldloader.getWorld()->getCamera()->getOrigin(), newDir, imgwidth, imgheight, focalLength);
    cameraChanged = true;
    worldloader.getWorld()->setCamera(cam);
    Render();
}

void MainWindow::rotCamLeft(){
    QVector3D newDir = worldloader.getWorld()->getCamera()->getDirection();
    newDir.setX(newDir.x() + 0.05);
    delete cam;
    cam = new Camera(worldloader.getWorld()->getCamera()->getOrigin(), newDir, imgwidth, imgheight, focalLength);
    cameraChanged = true;
    worldloader.getWorld()->setCamera(cam);
    Render();
}
