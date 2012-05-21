#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    depth(8)
{
    qRegisterMetaType<QVector<QVector<renderPixel> > >("QVector<QVector<renderPixel> >");

    ui->setupUi(this);

    //connect render buttons
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(StartStopRender()));
    connect(ui->DepthBox, SIGNAL(valueChanged(int)), this, SLOT(DepthChanged(int)));
    connect(ui->updateInteval_SpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeUpdateInterval(int)));

    //connect thread settings buttons
    connect(ui->radioButton_autoDetect, SIGNAL(toggled(bool)), ui->spinBox_threadCount, SLOT(setDisabled(bool)));
    connect(ui->radioButton_manual, SIGNAL(toggled(bool)), this, SLOT(changeThreadCount(bool)));
    connect(ui->spinBox_threadCount, SIGNAL(valueChanged(int)), this, SLOT(changeThreadCount(int)));

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

    //connect timers
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateStatusBar()));

    imageUpdateTimer = new QTimer(this);
    connect(imageUpdateTimer, SIGNAL(timeout()), this, SLOT(updateRender()));

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

    film = new Film(imgwidth, imgheight);

    //set up the threads
    if(ui->radioButton_autoDetect->isChecked()){
        cpuCoreCount = QThread::idealThreadCount();
        std::cout << "detected number of cpu cores: " << cpuCoreCount << std::endl;
        ui->displayThreadCount_label->setText(QString::number(cpuCoreCount));
    }
    else if(ui->radioButton_manual->isChecked()){
        cpuCoreCount = ui->spinBox_threadCount->value();
        std::cout << "number of threads set to " << cpuCoreCount << std::endl;
    }
    else{
        std::cerr << std::endl << "no thread count chosen! Setting it to 1 thread." << std::endl;
        cpuCoreCount = 1;
    }

    //set update interval
    updateInterval = ui->updateInteval_SpinBox->value();
}

MainWindow::~MainWindow()
{
    if(render){
        //stop the rendering process
        render = !render;

        for(int i = 0; i < cpuCoreCount; i++){
            threadList.at(i)->stop();
            wait();
        }
        timer->stop();
        imageUpdateTimer->stop();
        wait();
    }

    delete ui;
}

void MainWindow::StartStopRender(){
    if(render){
        //stop the rendering process
        render = !render;
        ui->pushButton->setText("Start Render");

        for(int i = 0; i < cpuCoreCount; i++){
            threadList.at(i)->stop();
            wait();
        }
        timer->stop();
        imageUpdateTimer->stop();
        wait();

    } else {
        //get start time
        t.start();
        //start the rendering process
        render = !render;
        ui->pushButton->setText("Stop Render");
        Render();
    }
}

void MainWindow::Render(){

    //read values from the gui settings
    imgwidth = ui->spinBox_imgres_x->value();
    LOG("imgwith == " << imgwidth)
    imgheight = ui->spinBox_imgres_y->value();
    LOG("imgheight == " << imgheight)
    delete film;
    film = new Film(imgwidth, imgheight);
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
        std::cerr << "the raytracing integrator is not yet ported to the new QThreads multithreading system!" << std::endl;

        //create the Integrator instances
        for(int i = 0; i < cpuCoreCount; i++){
            threadList.append(new Integrator(imgwidth, imgheight, depth, worldloader.getWorld(), "raytracer"));
        }

        //QObject::connect(tracer, SIGNAL(passFinished(QImage, float)), this, SLOT(updateRender(QImage, float)));

        timer->start(1000);
        //tracer->start();
    }

    //Integrator: Pathtracer
    if(ui->radioButton_Pathtracer->isChecked()){
        LOG("Integrator: Pathtracer")

        //create the Integrator instances
        for(int i = 0; i < cpuCoreCount; i++){
            threadList.append(new Integrator(imgwidth, imgheight, depth, worldloader.getWorld(), "pathtracer"));
        }

        for(int i = 0; i < cpuCoreCount; i++){
            QObject::connect(threadList.at(i), SIGNAL(passFinished(QVector<QVector <renderPixel> >)), film, SLOT(addSamples(QVector<QVector <renderPixel> >)));
        }

        timer->start(1000);
        imageUpdateTimer->start(updateInterval * 1000);

        //start the render threads
        for(int i = 0; i < cpuCoreCount; i++){
            threadList.at(i)->setSeed(i+1);
            threadList.at(i)->start();
        }
    }
}

void MainWindow::updateStatusBar(){
    //calculate the time the render is already running
    int ms = t.elapsed();
    int s  = ms / 1000;    ms %= 1000;
    int m  = s  / 60;      s  %= 60;
    int h  = m  / 60;      m  %= 60;
    QTime elapsedTime = QTime(h, m, s);

    spp = film->getSamplesPerPixel();
    ui->statusBar->showMessage("elapsed Time: " + elapsedTime.toString() + " | Samples per Pixel: " + QString::number(spp));
}

void MainWindow::updateRender(){
    ui->graphicsView->scene()->clear();
    ui->graphicsView->scene()->addPixmap(QPixmap::fromImage(film->getImage()));
}

void MainWindow::changeUpdateInterval(int value){
    updateInterval = value;
    imageUpdateTimer->stop();
    imageUpdateTimer->start(value * 1000);
}

void MainWindow::DepthChanged(int newDepth){
    depth = newDepth;
}

void MainWindow::changeThreadCount(int value){
    cpuCoreCount = value;
}

void MainWindow::changeThreadCount(bool toggled){
    if(toggled)
        cpuCoreCount = ui->spinBox_threadCount->value();
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
