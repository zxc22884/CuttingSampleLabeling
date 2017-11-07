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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QAction *_actionPreviousState;
    QWidget *centralWidget;
    QLabel *label;
    MyGraphicView *graphicsView;
    QGroupBox *groupLabelType;
    QPushButton *_okPushButton;
    QLineEdit *_lineEdit;
    QLabel *_radioAddLabel;
    QGroupBox *groupColorType;
    QPushButton *_redButton;
    QPushButton *_blueButton;
    QPushButton *_greenButton;
    QPushButton *_yellowButton;
    QPushButton *_whiteButton;
    QPushButton *_blackButton;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuTool;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CuttingSampleLabelClass)
    {
        if (CuttingSampleLabelClass->objectName().isEmpty())
            CuttingSampleLabelClass->setObjectName(QStringLiteral("CuttingSampleLabelClass"));
        CuttingSampleLabelClass->resize(1280, 680);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CuttingSampleLabelClass->sizePolicy().hasHeightForWidth());
        CuttingSampleLabelClass->setSizePolicy(sizePolicy);
        CuttingSampleLabelClass->setMinimumSize(QSize(1280, 680));
        CuttingSampleLabelClass->setMaximumSize(QSize(1280, 680));
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
        _actionPreviousState = new QAction(CuttingSampleLabelClass);
        _actionPreviousState->setObjectName(QStringLiteral("_actionPreviousState"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/CuttingSampleLabel/Icon/previousState.png"), QSize(), QIcon::Normal, QIcon::Off);
        _actionPreviousState->setIcon(icon8);
        centralWidget = new QWidget(CuttingSampleLabelClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(460, 560, 391, 21));
        graphicsView = new MyGraphicView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(180, 10, 960, 540));
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        graphicsView->setAlignment(Qt::AlignCenter);
        groupLabelType = new QGroupBox(centralWidget);
        groupLabelType->setObjectName(QStringLiteral("groupLabelType"));
        groupLabelType->setGeometry(QRect(10, 10, 151, 361));
        groupLabelType->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupLabelType->setFlat(false);
        _okPushButton = new QPushButton(centralWidget);
        _okPushButton->setObjectName(QStringLiteral("_okPushButton"));
        _okPushButton->setGeometry(QRect(1170, 80, 75, 23));
        _lineEdit = new QLineEdit(centralWidget);
        _lineEdit->setObjectName(QStringLiteral("_lineEdit"));
        _lineEdit->setEnabled(true);
        _lineEdit->setGeometry(QRect(1150, 50, 113, 20));
        _radioAddLabel = new QLabel(centralWidget);
        _radioAddLabel->setObjectName(QStringLiteral("_radioAddLabel"));
        _radioAddLabel->setGeometry(QRect(1160, 20, 101, 20));
        groupColorType = new QGroupBox(centralWidget);
        groupColorType->setObjectName(QStringLiteral("groupColorType"));
        groupColorType->setGeometry(QRect(10, 390, 151, 141));
        groupColorType->setAutoFillBackground(true);
        _redButton = new QPushButton(groupColorType);
        _redButton->setObjectName(QStringLiteral("_redButton"));
        _redButton->setGeometry(QRect(20, 20, 41, 31));
        QPalette palette;
        QBrush brush(QColor(255, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        _redButton->setPalette(palette);
        _redButton->setAutoFillBackground(true);
        _blueButton = new QPushButton(groupColorType);
        _blueButton->setObjectName(QStringLiteral("_blueButton"));
        _blueButton->setGeometry(QRect(80, 20, 41, 31));
        QPalette palette1;
        QBrush brush2(QColor(0, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        _blueButton->setPalette(palette1);
        _blueButton->setAutoFillBackground(true);
        _greenButton = new QPushButton(groupColorType);
        _greenButton->setObjectName(QStringLiteral("_greenButton"));
        _greenButton->setGeometry(QRect(20, 60, 41, 31));
        QPalette palette2;
        QBrush brush3(QColor(0, 0, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        _greenButton->setPalette(palette2);
        _greenButton->setAutoFillBackground(true);
        _yellowButton = new QPushButton(groupColorType);
        _yellowButton->setObjectName(QStringLiteral("_yellowButton"));
        _yellowButton->setGeometry(QRect(80, 60, 41, 31));
        QPalette palette3;
        QBrush brush4(QColor(255, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush4);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        _yellowButton->setPalette(palette3);
        _whiteButton = new QPushButton(groupColorType);
        _whiteButton->setObjectName(QStringLiteral("_whiteButton"));
        _whiteButton->setGeometry(QRect(80, 100, 41, 31));
        QPalette palette4;
        QBrush brush5(QColor(255, 255, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush5);
        QBrush brush6(QColor(0, 0, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush5);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        _whiteButton->setPalette(palette4);
        _whiteButton->setAutoFillBackground(true);
        _blackButton = new QPushButton(groupColorType);
        _blackButton->setObjectName(QStringLiteral("_blackButton"));
        _blackButton->setGeometry(QRect(20, 100, 41, 31));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush5);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        _blackButton->setPalette(palette5);
        _blackButton->setAutoFillBackground(true);
        CuttingSampleLabelClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CuttingSampleLabelClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 23));
        QFont font;
        font.setPointSize(10);
        menuBar->setFont(font);
        menuBar->setNativeMenuBar(false);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QFont font1;
        font1.setPointSize(9);
        menuFile->setFont(font1);
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
        menuTool->addAction(_actionNextImage);
        menuTool->addAction(_actionPreviousImage);
        menuTool->addSeparator();
        menuTool->addAction(_actionPreviousState);
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
        _actionLabel->setText(QApplication::translate("CuttingSampleLabelClass", "Add Label", 0));
        _actionDraw->setText(QApplication::translate("CuttingSampleLabelClass", "Draw", 0));
        _actionNextImage->setText(QApplication::translate("CuttingSampleLabelClass", "Next Image", 0));
        _actionPreviousImage->setText(QApplication::translate("CuttingSampleLabelClass", "Previous Image", 0));
        _actionOpenFolder->setText(QApplication::translate("CuttingSampleLabelClass", "Open Folder", 0));
        _actionPreviousState->setText(QApplication::translate("CuttingSampleLabelClass", "Previous State", 0));
        label->setText(QApplication::translate("CuttingSampleLabelClass", "<html><head/><body><p>\345\234\213\347\253\213\345\217\260\345\214\227\347\247\221\346\212\200\345\244\247\345\255\270 \350\263\207\350\250\212\345\267\245\347\250\213\347\263\273 1323\345\257\246\351\251\227\345\256\244 \351\231\263\345\275\245\351\234\226\346\225\231\346\216\210\345\234\230\351\232\212 \351\226\213\347\231\274\350\200\205:\345\221\202\345\255\237\347\251\216</p></body></html>", 0));
        groupLabelType->setTitle(QApplication::translate("CuttingSampleLabelClass", "LabelType", 0));
        _okPushButton->setText(QApplication::translate("CuttingSampleLabelClass", "OK", 0));
        _radioAddLabel->setText(QApplication::translate("CuttingSampleLabelClass", "Add Labeling Type", 0));
        groupColorType->setTitle(QApplication::translate("CuttingSampleLabelClass", "Rectangle and Text Color", 0));
        _redButton->setText(QApplication::translate("CuttingSampleLabelClass", "Red", 0));
        _blueButton->setText(QApplication::translate("CuttingSampleLabelClass", "Blue", 0));
        _greenButton->setText(QApplication::translate("CuttingSampleLabelClass", "Green", 0));
        _yellowButton->setText(QApplication::translate("CuttingSampleLabelClass", "Yellow", 0));
        _whiteButton->setText(QApplication::translate("CuttingSampleLabelClass", "White", 0));
        _blackButton->setText(QApplication::translate("CuttingSampleLabelClass", "Black", 0));
        menuFile->setTitle(QApplication::translate("CuttingSampleLabelClass", "File", 0));
        menuTool->setTitle(QApplication::translate("CuttingSampleLabelClass", "Tool", 0));
    } // retranslateUi

};

namespace Ui {
    class CuttingSampleLabelClass: public Ui_CuttingSampleLabelClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTTINGSAMPLELABEL_H
