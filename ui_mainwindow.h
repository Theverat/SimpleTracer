/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sun May 20 18:38:13 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Scene_File;
    QAction *actionSave_rendered_Image;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QFrame *line_3;
    QLabel *label_5;
    QSpinBox *updateInteval_SpinBox;
    QSpacerItem *horizontalSpacer;
    QGraphicsView *graphicsView;
    QTabWidget *tabWidget;
    QWidget *CamTab;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout_2;
    QPushButton *left_2;
    QPushButton *down_2;
    QLabel *label_4;
    QSlider *focalLengthSlider;
    QLabel *label;
    QPushButton *up;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QLabel *label_2;
    QPushButton *backwards;
    QPushButton *forwards;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_3;
    QLabel *focalLengthDisplay;
    QPushButton *up_2;
    QPushButton *right_2;
    QSpacerItem *verticalSpacer_3;
    QWidget *RenderTab;
    QWidget *gridLayoutWidget;
    QGridLayout *ThreadGridLayout;
    QRadioButton *radioButton_manual;
    QRadioButton *radioButton_autoDetect;
    QLabel *label_6;
    QSpinBox *spinBox_threadCount;
    QLabel *displayThreadCount_label;
    QWidget *ImageWorldTab;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_4;
    QRadioButton *radioButton_Raytracer;
    QRadioButton *radioButton_Pathtracer;
    QLabel *label_Integrator;
    QFrame *line_5;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView_BgColorDisplay;
    QFrame *line_2;
    QLabel *label_Depth;
    QSpinBox *DepthBox;
    QLabel *label_ImgRes;
    QLabel *label_Focal_Length;
    QSpinBox *spinBox_imgres_y;
    QLabel *label_world;
    QDoubleSpinBox *doubleSpinBox_focal_length;
    QLabel *label_BgColor;
    QLabel *label_Camera;
    QSpacerItem *verticalSpacer;
    QSpinBox *spinBox_imgres_x;
    QSpacerItem *verticalSpacer_2;
    QFrame *line;
    QPushButton *pushButton_BgColor;
    QWidget *SceneFileTab;
    QTextBrowser *SceneFileTextBrowser;
    QWidget *LogTab;
    QTextBrowser *LogTextBrowser;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(969, 665);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icon/ST-Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionOpen_Scene_File = new QAction(MainWindow);
        actionOpen_Scene_File->setObjectName(QString::fromUtf8("actionOpen_Scene_File"));
        actionSave_rendered_Image = new QAction(MainWindow);
        actionSave_rendered_Image->setObjectName(QString::fromUtf8("actionSave_rendered_Image"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_3);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        updateInteval_SpinBox = new QSpinBox(centralWidget);
        updateInteval_SpinBox->setObjectName(QString::fromUtf8("updateInteval_SpinBox"));
        updateInteval_SpinBox->setMinimum(3);
        updateInteval_SpinBox->setMaximum(99999999);
        updateInteval_SpinBox->setValue(10);

        horizontalLayout->addWidget(updateInteval_SpinBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_3->addLayout(horizontalLayout, 1, 0, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        QBrush brush(QColor(159, 159, 159, 255));
        brush.setStyle(Qt::SolidPattern);
        graphicsView->setBackgroundBrush(brush);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

        gridLayout_3->addWidget(graphicsView, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(370, 0));
        tabWidget->setMaximumSize(QSize(370, 16777215));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        CamTab = new QWidget();
        CamTab->setObjectName(QString::fromUtf8("CamTab"));
        verticalLayout_2 = new QVBoxLayout(CamTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        left_2 = new QPushButton(CamTab);
        left_2->setObjectName(QString::fromUtf8("left_2"));
        left_2->setMaximumSize(QSize(40, 40));

        gridLayout_2->addWidget(left_2, 11, 0, 1, 1);

        down_2 = new QPushButton(CamTab);
        down_2->setObjectName(QString::fromUtf8("down_2"));
        down_2->setMaximumSize(QSize(40, 40));

        gridLayout_2->addWidget(down_2, 12, 1, 1, 1);

        label_4 = new QLabel(CamTab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 9, 0, 1, 3);

        focalLengthSlider = new QSlider(CamTab);
        focalLengthSlider->setObjectName(QString::fromUtf8("focalLengthSlider"));
        focalLengthSlider->setMinimum(1);
        focalLengthSlider->setMaximum(200);
        focalLengthSlider->setValue(23);
        focalLengthSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(focalLengthSlider, 8, 0, 1, 3);

        label = new QLabel(CamTab);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 3);

        up = new QPushButton(CamTab);
        up->setObjectName(QString::fromUtf8("up"));
        up->setMaximumSize(QSize(40, 40));

        gridLayout_2->addWidget(up, 1, 1, 1, 1);

        left = new QPushButton(CamTab);
        left->setObjectName(QString::fromUtf8("left"));
        left->setMaximumSize(QSize(40, 40));

        gridLayout_2->addWidget(left, 2, 0, 1, 1);

        right = new QPushButton(CamTab);
        right->setObjectName(QString::fromUtf8("right"));
        right->setMaximumSize(QSize(40, 40));

        gridLayout_2->addWidget(right, 2, 2, 1, 1);

        down = new QPushButton(CamTab);
        down->setObjectName(QString::fromUtf8("down"));
        down->setMaximumSize(QSize(40, 40));

        gridLayout_2->addWidget(down, 3, 1, 1, 1);

        label_2 = new QLabel(CamTab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 4, 1, 1, 1);

        backwards = new QPushButton(CamTab);
        backwards->setObjectName(QString::fromUtf8("backwards"));
        backwards->setMaximumSize(QSize(80, 40));

        gridLayout_2->addWidget(backwards, 5, 0, 1, 2);

        forwards = new QPushButton(CamTab);
        forwards->setObjectName(QString::fromUtf8("forwards"));
        forwards->setMaximumSize(QSize(80, 40));

        gridLayout_2->addWidget(forwards, 6, 0, 1, 2);

        label_3 = new QLabel(CamTab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 7, 0, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        focalLengthDisplay = new QLabel(CamTab);
        focalLengthDisplay->setObjectName(QString::fromUtf8("focalLengthDisplay"));

        gridLayout_2->addWidget(focalLengthDisplay, 7, 2, 1, 1);

        up_2 = new QPushButton(CamTab);
        up_2->setObjectName(QString::fromUtf8("up_2"));
        up_2->setMaximumSize(QSize(40, 40));

        gridLayout_2->addWidget(up_2, 10, 1, 1, 1);

        right_2 = new QPushButton(CamTab);
        right_2->setObjectName(QString::fromUtf8("right_2"));
        right_2->setMaximumSize(QSize(40, 40));

        gridLayout_2->addWidget(right_2, 11, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_3, 13, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);

        tabWidget->addTab(CamTab, QString());
        RenderTab = new QWidget();
        RenderTab->setObjectName(QString::fromUtf8("RenderTab"));
        gridLayoutWidget = new QWidget(RenderTab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 321, 61));
        ThreadGridLayout = new QGridLayout(gridLayoutWidget);
        ThreadGridLayout->setSpacing(6);
        ThreadGridLayout->setContentsMargins(11, 11, 11, 11);
        ThreadGridLayout->setObjectName(QString::fromUtf8("ThreadGridLayout"));
        ThreadGridLayout->setContentsMargins(0, 0, 0, 0);
        radioButton_manual = new QRadioButton(gridLayoutWidget);
        radioButton_manual->setObjectName(QString::fromUtf8("radioButton_manual"));
        radioButton_manual->setChecked(false);

        ThreadGridLayout->addWidget(radioButton_manual, 1, 1, 1, 1);

        radioButton_autoDetect = new QRadioButton(gridLayoutWidget);
        radioButton_autoDetect->setObjectName(QString::fromUtf8("radioButton_autoDetect"));
        radioButton_autoDetect->setChecked(true);

        ThreadGridLayout->addWidget(radioButton_autoDetect, 0, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        ThreadGridLayout->addWidget(label_6, 0, 0, 1, 1);

        spinBox_threadCount = new QSpinBox(gridLayoutWidget);
        spinBox_threadCount->setObjectName(QString::fromUtf8("spinBox_threadCount"));
        spinBox_threadCount->setEnabled(false);
        spinBox_threadCount->setMinimum(1);
        spinBox_threadCount->setMaximum(1024);
        spinBox_threadCount->setValue(1);

        ThreadGridLayout->addWidget(spinBox_threadCount, 1, 2, 1, 1);

        displayThreadCount_label = new QLabel(gridLayoutWidget);
        displayThreadCount_label->setObjectName(QString::fromUtf8("displayThreadCount_label"));

        ThreadGridLayout->addWidget(displayThreadCount_label, 0, 2, 1, 1);

        tabWidget->addTab(RenderTab, QString());
        ImageWorldTab = new QWidget();
        ImageWorldTab->setObjectName(QString::fromUtf8("ImageWorldTab"));
        verticalLayout_4 = new QVBoxLayout(ImageWorldTab);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        scrollArea = new QScrollArea(ImageWorldTab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 346, 547));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        radioButton_Raytracer = new QRadioButton(scrollAreaWidgetContents);
        radioButton_Raytracer->setObjectName(QString::fromUtf8("radioButton_Raytracer"));
        radioButton_Raytracer->setChecked(false);

        gridLayout_4->addWidget(radioButton_Raytracer, 0, 1, 1, 1);

        radioButton_Pathtracer = new QRadioButton(scrollAreaWidgetContents);
        radioButton_Pathtracer->setObjectName(QString::fromUtf8("radioButton_Pathtracer"));
        radioButton_Pathtracer->setChecked(true);

        gridLayout_4->addWidget(radioButton_Pathtracer, 1, 1, 1, 1);

        label_Integrator = new QLabel(scrollAreaWidgetContents);
        label_Integrator->setObjectName(QString::fromUtf8("label_Integrator"));

        gridLayout_4->addWidget(label_Integrator, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_4);

        line_5 = new QFrame(scrollAreaWidgetContents);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_5);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView_BgColorDisplay = new QGraphicsView(scrollAreaWidgetContents);
        graphicsView_BgColorDisplay->setObjectName(QString::fromUtf8("graphicsView_BgColorDisplay"));
        graphicsView_BgColorDisplay->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView_BgColorDisplay->sizePolicy().hasHeightForWidth());
        graphicsView_BgColorDisplay->setSizePolicy(sizePolicy);
        graphicsView_BgColorDisplay->setMinimumSize(QSize(50, 30));
        graphicsView_BgColorDisplay->setMaximumSize(QSize(50, 30));

        gridLayout->addWidget(graphicsView_BgColorDisplay, 11, 2, 1, 1);

        line_2 = new QFrame(scrollAreaWidgetContents);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 4, 0, 1, 3);

        label_Depth = new QLabel(scrollAreaWidgetContents);
        label_Depth->setObjectName(QString::fromUtf8("label_Depth"));

        gridLayout->addWidget(label_Depth, 3, 0, 1, 1);

        DepthBox = new QSpinBox(scrollAreaWidgetContents);
        DepthBox->setObjectName(QString::fromUtf8("DepthBox"));
        DepthBox->setMaximum(512);
        DepthBox->setValue(8);

        gridLayout->addWidget(DepthBox, 3, 1, 1, 1);

        label_ImgRes = new QLabel(scrollAreaWidgetContents);
        label_ImgRes->setObjectName(QString::fromUtf8("label_ImgRes"));

        gridLayout->addWidget(label_ImgRes, 6, 0, 1, 1);

        label_Focal_Length = new QLabel(scrollAreaWidgetContents);
        label_Focal_Length->setObjectName(QString::fromUtf8("label_Focal_Length"));

        gridLayout->addWidget(label_Focal_Length, 8, 0, 1, 1);

        spinBox_imgres_y = new QSpinBox(scrollAreaWidgetContents);
        spinBox_imgres_y->setObjectName(QString::fromUtf8("spinBox_imgres_y"));
        spinBox_imgres_y->setMaximum(100000);
        spinBox_imgres_y->setValue(512);

        gridLayout->addWidget(spinBox_imgres_y, 7, 1, 1, 1);

        label_world = new QLabel(scrollAreaWidgetContents);
        label_world->setObjectName(QString::fromUtf8("label_world"));

        gridLayout->addWidget(label_world, 10, 0, 1, 1);

        doubleSpinBox_focal_length = new QDoubleSpinBox(scrollAreaWidgetContents);
        doubleSpinBox_focal_length->setObjectName(QString::fromUtf8("doubleSpinBox_focal_length"));
        doubleSpinBox_focal_length->setDecimals(1);
        doubleSpinBox_focal_length->setMinimum(1);
        doubleSpinBox_focal_length->setMaximum(10000);
        doubleSpinBox_focal_length->setValue(23);

        gridLayout->addWidget(doubleSpinBox_focal_length, 8, 1, 1, 1);

        label_BgColor = new QLabel(scrollAreaWidgetContents);
        label_BgColor->setObjectName(QString::fromUtf8("label_BgColor"));

        gridLayout->addWidget(label_BgColor, 11, 0, 1, 1);

        label_Camera = new QLabel(scrollAreaWidgetContents);
        label_Camera->setObjectName(QString::fromUtf8("label_Camera"));

        gridLayout->addWidget(label_Camera, 5, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 12, 0, 1, 1);

        spinBox_imgres_x = new QSpinBox(scrollAreaWidgetContents);
        spinBox_imgres_x->setObjectName(QString::fromUtf8("spinBox_imgres_x"));
        spinBox_imgres_x->setMaximum(100000);
        spinBox_imgres_x->setValue(512);

        gridLayout->addWidget(spinBox_imgres_x, 6, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 12, 1, 1, 1);

        line = new QFrame(scrollAreaWidgetContents);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 9, 0, 1, 4);

        pushButton_BgColor = new QPushButton(scrollAreaWidgetContents);
        pushButton_BgColor->setObjectName(QString::fromUtf8("pushButton_BgColor"));
        pushButton_BgColor->setEnabled(true);
        pushButton_BgColor->setAutoFillBackground(false);
        pushButton_BgColor->setFlat(false);

        gridLayout->addWidget(pushButton_BgColor, 11, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(scrollArea);

        tabWidget->addTab(ImageWorldTab, QString());
        SceneFileTab = new QWidget();
        SceneFileTab->setObjectName(QString::fromUtf8("SceneFileTab"));
        SceneFileTextBrowser = new QTextBrowser(SceneFileTab);
        SceneFileTextBrowser->setObjectName(QString::fromUtf8("SceneFileTextBrowser"));
        SceneFileTextBrowser->setGeometry(QRect(10, 10, 321, 661));
        tabWidget->addTab(SceneFileTab, QString());
        LogTab = new QWidget();
        LogTab->setObjectName(QString::fromUtf8("LogTab"));
        LogTextBrowser = new QTextBrowser(LogTab);
        LogTextBrowser->setObjectName(QString::fromUtf8("LogTextBrowser"));
        LogTextBrowser->setGeometry(QRect(10, 10, 321, 661));
        tabWidget->addTab(LogTab, QString());

        horizontalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 969, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_Scene_File);
        menuFile->addAction(actionSave_rendered_Image);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SimpleTracer", 0, QApplication::UnicodeUTF8));
        actionOpen_Scene_File->setText(QApplication::translate("MainWindow", "Open Scene File", 0, QApplication::UnicodeUTF8));
        actionSave_rendered_Image->setText(QApplication::translate("MainWindow", "Save rendered Image", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Start Render", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "update interval (sec.)", 0, QApplication::UnicodeUTF8));
        left_2->setText(QApplication::translate("MainWindow", "left", 0, QApplication::UnicodeUTF8));
        down_2->setText(QApplication::translate("MainWindow", "down", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Rotate Camera:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Move Camera:", 0, QApplication::UnicodeUTF8));
        up->setText(QApplication::translate("MainWindow", "up", 0, QApplication::UnicodeUTF8));
        left->setText(QApplication::translate("MainWindow", "left", 0, QApplication::UnicodeUTF8));
        right->setText(QApplication::translate("MainWindow", "right", 0, QApplication::UnicodeUTF8));
        down->setText(QApplication::translate("MainWindow", "down", 0, QApplication::UnicodeUTF8));
        label_2->setText(QString());
        backwards->setText(QApplication::translate("MainWindow", "backwards", 0, QApplication::UnicodeUTF8));
        forwards->setText(QApplication::translate("MainWindow", "forwards", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Focal Length:", 0, QApplication::UnicodeUTF8));
        focalLengthDisplay->setText(QApplication::translate("MainWindow", "23", 0, QApplication::UnicodeUTF8));
        up_2->setText(QApplication::translate("MainWindow", "up", 0, QApplication::UnicodeUTF8));
        right_2->setText(QApplication::translate("MainWindow", "right", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(CamTab), QApplication::translate("MainWindow", "Camera", 0, QApplication::UnicodeUTF8));
        radioButton_manual->setText(QApplication::translate("MainWindow", "manual:", 0, QApplication::UnicodeUTF8));
        radioButton_autoDetect->setText(QApplication::translate("MainWindow", "auto detect:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Threads:", 0, QApplication::UnicodeUTF8));
        displayThreadCount_label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(RenderTab), QApplication::translate("MainWindow", "Render", 0, QApplication::UnicodeUTF8));
        radioButton_Raytracer->setText(QApplication::translate("MainWindow", "Raytracer", 0, QApplication::UnicodeUTF8));
        radioButton_Pathtracer->setText(QApplication::translate("MainWindow", "Pathtracer", 0, QApplication::UnicodeUTF8));
        label_Integrator->setText(QApplication::translate("MainWindow", "Integrator:", 0, QApplication::UnicodeUTF8));
        label_Depth->setText(QApplication::translate("MainWindow", "Depth: ", 0, QApplication::UnicodeUTF8));
        label_ImgRes->setText(QApplication::translate("MainWindow", "Image Resolution:", 0, QApplication::UnicodeUTF8));
        label_Focal_Length->setText(QApplication::translate("MainWindow", "Focal Length:", 0, QApplication::UnicodeUTF8));
        label_world->setText(QApplication::translate("MainWindow", "World:", 0, QApplication::UnicodeUTF8));
        label_BgColor->setText(QApplication::translate("MainWindow", "Background Color:", 0, QApplication::UnicodeUTF8));
        label_Camera->setText(QApplication::translate("MainWindow", "Camera:", 0, QApplication::UnicodeUTF8));
        pushButton_BgColor->setText(QApplication::translate("MainWindow", "Choose Color", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(ImageWorldTab), QApplication::translate("MainWindow", "Image/World", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(SceneFileTab), QApplication::translate("MainWindow", "Scene File", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(LogTab), QApplication::translate("MainWindow", "Log", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
