/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon 14. May 22:54:19 2012
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
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen_Scene_File;
    QAction *actionSave_rendered_Image;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *RenderTab;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label;
    QSpinBox *DepthBox;
    QSpacerItem *horizontalSpacer;
    QWidget *SceneFileTab;
    QTextBrowser *SceneFileTextBrowser;
    QWidget *LogTab;
    QTextBrowser *LogTextBrowser;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(860, 755);
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
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 841, 711));
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        RenderTab = new QWidget();
        RenderTab->setObjectName(QString::fromUtf8("RenderTab"));
        graphicsView = new QGraphicsView(RenderTab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 811, 611));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        QBrush brush(QColor(0, 0, 50, 255));
        brush.setStyle(Qt::SolidPattern);
        graphicsView->setBackgroundBrush(brush);
        graphicsView->setSceneRect(QRectF(0, 0, 800, 600));
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        graphicsView->setDragMode(QGraphicsView::NoDrag);
        graphicsView->setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);
        horizontalLayoutWidget = new QWidget(RenderTab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 630, 811, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        line = new QFrame(horizontalLayoutWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        DepthBox = new QSpinBox(horizontalLayoutWidget);
        DepthBox->setObjectName(QString::fromUtf8("DepthBox"));
        DepthBox->setMaximum(512);
        DepthBox->setValue(8);

        horizontalLayout->addWidget(DepthBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        tabWidget->addTab(RenderTab, QString());
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
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 860, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);

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
        label->setText(QApplication::translate("MainWindow", "Depth: ", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(RenderTab), QApplication::translate("MainWindow", "Render", 0, QApplication::UnicodeUTF8));
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
