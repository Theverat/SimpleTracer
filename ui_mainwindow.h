/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Tue 15. May 21:28:27 2012
**      by: Qt User Interface Compiler version 4.8.0
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
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *RenderTab;
    QVBoxLayout *verticalLayout_2;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QWidget *RenderSettingsTab;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSpinBox *spinBox_imgres_x;
    QSpacerItem *verticalSpacer;
    QRadioButton *radioButton_Pathtracer;
    QLabel *label_Integrator;
    QRadioButton *radioButton_Raytracer;
    QLabel *label_Depth;
    QSpacerItem *verticalSpacer_2;
    QSpinBox *DepthBox;
    QLabel *label;
    QSpinBox *spinBox_imgres_y;
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
        MainWindow->resize(383, 386);
        QIcon icon;
        icon.addFile(QString::fromUtf8("Icon/SimpleTracer-Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionOpen_Scene_File = new QAction(MainWindow);
        actionOpen_Scene_File->setObjectName(QString::fromUtf8("actionOpen_Scene_File"));
        actionSave_rendered_Image = new QAction(MainWindow);
        actionSave_rendered_Image->setObjectName(QString::fromUtf8("actionSave_rendered_Image"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        RenderTab = new QWidget();
        RenderTab->setObjectName(QString::fromUtf8("RenderTab"));
        verticalLayout_2 = new QVBoxLayout(RenderTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        graphicsView = new QGraphicsView(RenderTab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        QBrush brush(QColor(0, 0, 50, 255));
        brush.setStyle(Qt::SolidPattern);
        graphicsView->setBackgroundBrush(brush);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        graphicsView->setDragMode(QGraphicsView::NoDrag);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

        verticalLayout_2->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(RenderTab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout);

        tabWidget->addTab(RenderTab, QString());
        RenderSettingsTab = new QWidget();
        RenderSettingsTab->setObjectName(QString::fromUtf8("RenderSettingsTab"));
        scrollArea = new QScrollArea(RenderSettingsTab);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 821, 661));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 819, 659));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 281, 641));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        spinBox_imgres_x = new QSpinBox(gridLayoutWidget);
        spinBox_imgres_x->setObjectName(QString::fromUtf8("spinBox_imgres_x"));
        spinBox_imgres_x->setMaximum(100000);
        spinBox_imgres_x->setValue(800);

        gridLayout->addWidget(spinBox_imgres_x, 3, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 5, 0, 1, 1);

        radioButton_Pathtracer = new QRadioButton(gridLayoutWidget);
        radioButton_Pathtracer->setObjectName(QString::fromUtf8("radioButton_Pathtracer"));
        radioButton_Pathtracer->setChecked(true);

        gridLayout->addWidget(radioButton_Pathtracer, 1, 1, 1, 1);

        label_Integrator = new QLabel(gridLayoutWidget);
        label_Integrator->setObjectName(QString::fromUtf8("label_Integrator"));

        gridLayout->addWidget(label_Integrator, 0, 0, 1, 1);

        radioButton_Raytracer = new QRadioButton(gridLayoutWidget);
        radioButton_Raytracer->setObjectName(QString::fromUtf8("radioButton_Raytracer"));

        gridLayout->addWidget(radioButton_Raytracer, 0, 1, 1, 1);

        label_Depth = new QLabel(gridLayoutWidget);
        label_Depth->setObjectName(QString::fromUtf8("label_Depth"));

        gridLayout->addWidget(label_Depth, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 5, 1, 1, 1);

        DepthBox = new QSpinBox(gridLayoutWidget);
        DepthBox->setObjectName(QString::fromUtf8("DepthBox"));
        DepthBox->setMaximum(512);
        DepthBox->setValue(8);

        gridLayout->addWidget(DepthBox, 2, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 3, 0, 1, 1);

        spinBox_imgres_y = new QSpinBox(gridLayoutWidget);
        spinBox_imgres_y->setObjectName(QString::fromUtf8("spinBox_imgres_y"));
        spinBox_imgres_y->setMaximum(100000);
        spinBox_imgres_y->setValue(600);

        gridLayout->addWidget(spinBox_imgres_y, 4, 1, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        tabWidget->addTab(RenderSettingsTab, QString());
        SceneFileTab = new QWidget();
        SceneFileTab->setObjectName(QString::fromUtf8("SceneFileTab"));
        SceneFileTextBrowser = new QTextBrowser(SceneFileTab);
        SceneFileTextBrowser->setObjectName(QString::fromUtf8("SceneFileTextBrowser"));
        SceneFileTextBrowser->setGeometry(QRect(10, 10, 821, 661));
        tabWidget->addTab(SceneFileTab, QString());
        LogTab = new QWidget();
        LogTab->setObjectName(QString::fromUtf8("LogTab"));
        LogTextBrowser = new QTextBrowser(LogTab);
        LogTextBrowser->setObjectName(QString::fromUtf8("LogTextBrowser"));
        LogTextBrowser->setGeometry(QRect(10, 10, 821, 661));
        tabWidget->addTab(LogTab, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 383, 31));
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

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "SimpleTracer", 0, QApplication::UnicodeUTF8));
        actionOpen_Scene_File->setText(QApplication::translate("MainWindow", "Open Scene File", 0, QApplication::UnicodeUTF8));
        actionSave_rendered_Image->setText(QApplication::translate("MainWindow", "Save rendered Image", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Start Render", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(RenderTab), QApplication::translate("MainWindow", "Render", 0, QApplication::UnicodeUTF8));
        radioButton_Pathtracer->setText(QApplication::translate("MainWindow", "Pathtracer", 0, QApplication::UnicodeUTF8));
        label_Integrator->setText(QApplication::translate("MainWindow", "Integrator:", 0, QApplication::UnicodeUTF8));
        radioButton_Raytracer->setText(QApplication::translate("MainWindow", "Raytracer", 0, QApplication::UnicodeUTF8));
        label_Depth->setText(QApplication::translate("MainWindow", "Depth: ", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Image Resolution", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(RenderSettingsTab), QApplication::translate("MainWindow", "Render Settings", 0, QApplication::UnicodeUTF8));
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
