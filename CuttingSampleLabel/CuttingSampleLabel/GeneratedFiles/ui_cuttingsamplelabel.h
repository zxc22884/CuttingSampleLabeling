/********************************************************************************
** Form generated from reading UI file 'cuttingsamplelabel.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTTINGSAMPLELABEL_H
#define UI_CUTTINGSAMPLELABEL_H

#include <MyGraphicView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CuttingSampleLabelClass
{
public:
    QAction *_actionOpenFile;
    QAction *_actionExit;
    QAction *_actionSave;
    QAction *_actionLabel;
    QAction *_actionDraw;
    QAction *_actionNextImage;
    QAction *_actionPreviousImage;
    QAction *_actionOpenFolder;
    QWidget *centralWidget;
    QLabel *label;
    MyGraphicView *graphicsView;
    QGroupBox *groupLabelType;
    QRadioButton *radioSpotLabelBt;
    QRadioButton *radioMetalLabelBt;
    QRadioButton *radioOilLabelBt;
    QRadioButton *radioOthersLabelBt;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTool;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CuttingSampleLabelClass)
    {
        if (CuttingSampleLabelClass->objectName().isEmpty())
            CuttingSampleLabelClass->setObjectName(QStringLiteral("CuttingSampleLabelClass"));
        CuttingSampleLabelClass->resize(1280, 720);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CuttingSampleLabelClass->sizePolicy().hasHeightForWidth());
        CuttingSampleLabelClass->setSizePolicy(sizePolicy);
        CuttingSampleLabelClass->setMinimumSize(QSize(1280, 720));
        CuttingSampleLabelClass->setMaximumSize(QSize(1280, 720));
        CuttingSampleLabelClass->setMouseTracking(false);
        _actionOpenFile = new QAction(CuttingSampleLabelClass);
        _actionOpenFile->setObjectName(QStringLiteral("_actionOpenFile"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/openFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionOpenFile->setIcon(icon);
        _actionExit = new QAction(CuttingSampleLabelClass);
        _actionExit->setObjectName(QStringLiteral("_actionExit"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionExit->setIcon(icon1);
        _actionSave = new QAction(CuttingSampleLabelClass);
        _actionSave->setObjectName(QStringLiteral("_actionSave"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionSave->setIcon(icon2);
        _actionLabel = new QAction(CuttingSampleLabelClass);
        _actionLabel->setObjectName(QStringLiteral("_actionLabel"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/label.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionLabel->setIcon(icon3);
        _actionDraw = new QAction(CuttingSampleLabelClass);
        _actionDraw->setObjectName(QStringLiteral("_actionDraw"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/draw.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionDraw->setIcon(icon4);
        _actionNextImage = new QAction(CuttingSampleLabelClass);
        _actionNextImage->setObjectName(QStringLiteral("_actionNextImage"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/next.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionNextImage->setIcon(icon5);
        _actionPreviousImage = new QAction(CuttingSampleLabelClass);
        _actionPreviousImage->setObjectName(QStringLiteral("_actionPreviousImage"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionPreviousImage->setIcon(icon6);
        _actionOpenFolder = new QAction(CuttingSampleLabelClass);
        _actionOpenFolder->setObjectName(QStringLiteral("_actionOpenFolder"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/openFolder.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionOpenFolder->setIcon(icon7);
        centralWidget = new QWidget(CuttingSampleLabelClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 610, 391, 21));
        graphicsView = new MyGraphicView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(180, 10, 960, 600));
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        graphicsView->setAlignment(Qt::AlignCenter);
        groupLabelType = new QGroupBox(centralWidget);
        groupLabelType->setObjectName(QStringLiteral("groupLabelType"));
        groupLabelType->setGeometry(QRect(10, 10, 151, 141));
        groupLabelType->setFlat(false);
        radioSpotLabelBt = new QRadioButton(groupLabelType);
        radioSpotLabelBt->setObjectName(QStringLiteral("radioSpotLabelBt"));
        radioSpotLabelBt->setGeometry(QRect(10, 30, 101, 16));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        radioSpotLabelBt->setFont(font);
        radioMetalLabelBt = new QRadioButton(groupLabelType);
        radioMetalLabelBt->setObjectName(QStringLiteral("radioMetalLabelBt"));
        radioMetalLabelBt->setGeometry(QRect(10, 50, 121, 16));
        radioMetalLabelBt->setFont(font);
        radioOilLabelBt = new QRadioButton(groupLabelType);
        radioOilLabelBt->setObjectName(QStringLiteral("radioOilLabelBt"));
        radioOilLabelBt->setGeometry(QRect(10, 70, 111, 16));
        radioOilLabelBt->setFont(font);
        radioOthersLabelBt = new QRadioButton(groupLabelType);
        radioOthersLabelBt->setObjectName(QStringLiteral("radioOthersLabelBt"));
        radioOthersLabelBt->setGeometry(QRect(10, 90, 111, 16));
        radioOthersLabelBt->setFont(font);
        CuttingSampleLabelClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CuttingSampleLabelClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 23));
        QFont font1;
        font1.setPointSize(10);
        menuBar->setFont(font1);
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QFont font2;
        font2.setPointSize(9);
        menuFile->setFont(font2);
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        CuttingSampleLabelClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CuttingSampleLabelClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setIconSize(QSize(32, 32));
        CuttingSampleLabelClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CuttingSampleLabelClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setMouseTracking(false);
        CuttingSampleLabelClass->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuFile->addAction(_actionOpenFile);
        menuFile->addAction(_actionOpenFolder);
        menuFile->addSeparator();
        menuFile->addAction(_actionSave);
        menuFile->addSeparator();
        menuFile->addAction(_actionExit);
        menuTool->addAction(_actionLabel);
        menuTool->addSeparator();
        menuTool->addAction(_actionDraw);
        menuTool->addSeparator();
        menuTool->addAction(_actionNextImage);
        menuTool->addAction(_actionPreviousImage);
        mainToolBar->addSeparator();

        retranslateUi(CuttingSampleLabelClass);

        QMetaObject::connectSlotsByName(CuttingSampleLabelClass);
    } // setupUi

    void retranslateUi(QMainWindow *CuttingSampleLabelClass)
    {
        CuttingSampleLabelClass->setWindowTitle(QApplication::translate("CuttingSampleLabelClass", "CuttingSampleLabel", 0));
        _actionOpenFile->setText(QApplication::translate("CuttingSampleLabelClass", "Open File", 0));
        _actionExit->setText(QApplication::translate("CuttingSampleLabelClass", "Quit", 0));
        _actionSave->setText(QApplication::translate("CuttingSampleLabelClass", "Save", 0));
        _actionLabel->setText(QApplication::translate("CuttingSampleLabelClass", "Label", 0));
        _actionDraw->setText(QApplication::translate("CuttingSampleLabelClass", "Draw", 0));
        _actionNextImage->setText(QApplication::translate("CuttingSampleLabelClass", "Next Image", 0));
        _actionPreviousImage->setText(QApplication::translate("CuttingSampleLabelClass", "Previous Image", 0));
        _actionOpenFolder->setText(QApplication::translate("CuttingSampleLabelClass", "Open Folder", 0));
        label->setText(QApplication::translate("CuttingSampleLabelClass", "<html><head/><body><p>\345\234\213\347\253\213\345\217\260\345\214\227\347\247\221\346\212\200\345\244\247\345\255\270 \350\263\207\350\250\212\345\267\245\347\250\213\347\263\273 1323\345\257\246\351\251\227\345\256\244 \351\231\263\345\275\245\351\234\226\346\225\231\346\216\210\345\234\230\351\232\212 \351\226\213\347\231\274\350\200\205:\345\221\202\345\255\237\347\251\216</p></body></html>", 0));
        groupLabelType->setTitle(QApplication::translate("CuttingSampleLabelClass", "LabelType", 0));
        radioSpotLabelBt->setText(QApplication::translate("CuttingSampleLabelClass", "Spot", 0));
        radioMetalLabelBt->setText(QApplication::translate("CuttingSampleLabelClass", "Metal", 0));
        radioOilLabelBt->setText(QApplication::translate("CuttingSampleLabelClass", "Oil", 0));
        radioOthersLabelBt->setText(QApplication::translate("CuttingSampleLabelClass", "Others", 0));
        menuFile->setTitle(QApplication::translate("CuttingSampleLabelClass", "File", 0));
        menuTool->setTitle(QApplication::translate("CuttingSampleLabelClass", "Tool", 0));
    } // retranslateUi

};

namespace Ui {
    class CuttingSampleLabelClass: public Ui_CuttingSampleLabelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTTINGSAMPLELABEL_H
