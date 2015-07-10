/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_3;
    QLabel *noImagesLabel;
    QLineEdit *noImagesLineEdit;
    QLabel *heightLabel;
    QLineEdit *heightLineEdit;
    QLabel *widthLabel;
    QLineEdit *widthLineEdit;
    QLabel *leftSlitLimLabel;
    QLineEdit *leftSlitLimLineEdit;
    QLabel *rightSlitLimLabel;
    QLineEdit *rightSlitLimLineEdit;
    QLabel *slitThicknessLabel;
    QLineEdit *slitThicknessLineEdit;
    QLabel *waitTimeLabel;
    QLineEdit *waitTimeLineEdit;
    QLabel *captureNameLabel;
    QLineEdit *captureNameLineEdit;
    QLabel *captureFormatLabel;
    QLineEdit *captureFormatLineEdit;
    QWidget *tab_6;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout;
    QLabel *brightnessLabel;
    QLineEdit *brightnessLineEdit;
    QLabel *autoExposureLabel;
    QLineEdit *autoExposureLineEdit;
    QLabel *sharpnessLabel;
    QLineEdit *sharpnessLineEdit;
    QLabel *shutterLabel;
    QLineEdit *shutterLineEdit;
    QLabel *gainLabel;
    QLineEdit *gainLineEdit;
    QLineEdit *frameRateLineEdit;
    QPushButton *startButton;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(569, 415);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 341, 341));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        formLayoutWidget = new QWidget(tab_5);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 0, 311, 293));
        formLayout_3 = new QFormLayout(formLayoutWidget);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        noImagesLabel = new QLabel(formLayoutWidget);
        noImagesLabel->setObjectName(QStringLiteral("noImagesLabel"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, noImagesLabel);

        noImagesLineEdit = new QLineEdit(formLayoutWidget);
        noImagesLineEdit->setObjectName(QStringLiteral("noImagesLineEdit"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, noImagesLineEdit);

        heightLabel = new QLabel(formLayoutWidget);
        heightLabel->setObjectName(QStringLiteral("heightLabel"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, heightLabel);

        heightLineEdit = new QLineEdit(formLayoutWidget);
        heightLineEdit->setObjectName(QStringLiteral("heightLineEdit"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, heightLineEdit);

        widthLabel = new QLabel(formLayoutWidget);
        widthLabel->setObjectName(QStringLiteral("widthLabel"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, widthLabel);

        widthLineEdit = new QLineEdit(formLayoutWidget);
        widthLineEdit->setObjectName(QStringLiteral("widthLineEdit"));

        formLayout_3->setWidget(2, QFormLayout::FieldRole, widthLineEdit);

        leftSlitLimLabel = new QLabel(formLayoutWidget);
        leftSlitLimLabel->setObjectName(QStringLiteral("leftSlitLimLabel"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, leftSlitLimLabel);

        leftSlitLimLineEdit = new QLineEdit(formLayoutWidget);
        leftSlitLimLineEdit->setObjectName(QStringLiteral("leftSlitLimLineEdit"));

        formLayout_3->setWidget(3, QFormLayout::FieldRole, leftSlitLimLineEdit);

        rightSlitLimLabel = new QLabel(formLayoutWidget);
        rightSlitLimLabel->setObjectName(QStringLiteral("rightSlitLimLabel"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, rightSlitLimLabel);

        rightSlitLimLineEdit = new QLineEdit(formLayoutWidget);
        rightSlitLimLineEdit->setObjectName(QStringLiteral("rightSlitLimLineEdit"));

        formLayout_3->setWidget(4, QFormLayout::FieldRole, rightSlitLimLineEdit);

        slitThicknessLabel = new QLabel(formLayoutWidget);
        slitThicknessLabel->setObjectName(QStringLiteral("slitThicknessLabel"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, slitThicknessLabel);

        slitThicknessLineEdit = new QLineEdit(formLayoutWidget);
        slitThicknessLineEdit->setObjectName(QStringLiteral("slitThicknessLineEdit"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, slitThicknessLineEdit);

        waitTimeLabel = new QLabel(formLayoutWidget);
        waitTimeLabel->setObjectName(QStringLiteral("waitTimeLabel"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, waitTimeLabel);

        waitTimeLineEdit = new QLineEdit(formLayoutWidget);
        waitTimeLineEdit->setObjectName(QStringLiteral("waitTimeLineEdit"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, waitTimeLineEdit);

        captureNameLabel = new QLabel(formLayoutWidget);
        captureNameLabel->setObjectName(QStringLiteral("captureNameLabel"));

        formLayout_3->setWidget(7, QFormLayout::LabelRole, captureNameLabel);

        captureNameLineEdit = new QLineEdit(formLayoutWidget);
        captureNameLineEdit->setObjectName(QStringLiteral("captureNameLineEdit"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, captureNameLineEdit);

        captureFormatLabel = new QLabel(formLayoutWidget);
        captureFormatLabel->setObjectName(QStringLiteral("captureFormatLabel"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, captureFormatLabel);

        captureFormatLineEdit = new QLineEdit(formLayoutWidget);
        captureFormatLineEdit->setObjectName(QStringLiteral("captureFormatLineEdit"));

        formLayout_3->setWidget(8, QFormLayout::FieldRole, captureFormatLineEdit);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        formLayoutWidget_2 = new QWidget(tab_6);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(20, 10, 311, 211));
        formLayout = new QFormLayout(formLayoutWidget_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        brightnessLabel = new QLabel(formLayoutWidget_2);
        brightnessLabel->setObjectName(QStringLiteral("brightnessLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, brightnessLabel);

        brightnessLineEdit = new QLineEdit(formLayoutWidget_2);
        brightnessLineEdit->setObjectName(QStringLiteral("brightnessLineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, brightnessLineEdit);

        autoExposureLabel = new QLabel(formLayoutWidget_2);
        autoExposureLabel->setObjectName(QStringLiteral("autoExposureLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, autoExposureLabel);

        autoExposureLineEdit = new QLineEdit(formLayoutWidget_2);
        autoExposureLineEdit->setObjectName(QStringLiteral("autoExposureLineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, autoExposureLineEdit);

        sharpnessLabel = new QLabel(formLayoutWidget_2);
        sharpnessLabel->setObjectName(QStringLiteral("sharpnessLabel"));

        formLayout->setWidget(2, QFormLayout::LabelRole, sharpnessLabel);

        sharpnessLineEdit = new QLineEdit(formLayoutWidget_2);
        sharpnessLineEdit->setObjectName(QStringLiteral("sharpnessLineEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, sharpnessLineEdit);

        shutterLabel = new QLabel(formLayoutWidget_2);
        shutterLabel->setObjectName(QStringLiteral("shutterLabel"));

        formLayout->setWidget(3, QFormLayout::LabelRole, shutterLabel);

        shutterLineEdit = new QLineEdit(formLayoutWidget_2);
        shutterLineEdit->setObjectName(QStringLiteral("shutterLineEdit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, shutterLineEdit);

        gainLabel = new QLabel(formLayoutWidget_2);
        gainLabel->setObjectName(QStringLiteral("gainLabel"));

        formLayout->setWidget(4, QFormLayout::LabelRole, gainLabel);

        gainLineEdit = new QLineEdit(formLayoutWidget_2);
        gainLineEdit->setObjectName(QStringLiteral("gainLineEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, gainLineEdit);

        frameRateLineEdit = new QLineEdit(formLayoutWidget_2);
        frameRateLineEdit->setObjectName(QStringLiteral("frameRateLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, frameRateLineEdit);

        tabWidget->addTab(tab_6, QString());
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(400, 230, 121, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(340, 260, 241, 41));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 569, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        noImagesLabel->setText(QApplication::translate("MainWindow", "Images:", 0));
        heightLabel->setText(QApplication::translate("MainWindow", "Height:", 0));
        widthLabel->setText(QApplication::translate("MainWindow", "Width:", 0));
        leftSlitLimLabel->setText(QApplication::translate("MainWindow", "LeftSlitLim:", 0));
        rightSlitLimLabel->setText(QApplication::translate("MainWindow", "RightSlitLim:", 0));
        slitThicknessLabel->setText(QApplication::translate("MainWindow", "Slit Thickness", 0));
        waitTimeLabel->setText(QApplication::translate("MainWindow", "Wait Time:", 0));
        captureNameLabel->setText(QApplication::translate("MainWindow", "Capture Name:", 0));
        captureFormatLabel->setText(QApplication::translate("MainWindow", "Capture Format:", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "General", 0));
        brightnessLabel->setText(QApplication::translate("MainWindow", "Brightness", 0));
        autoExposureLabel->setText(QApplication::translate("MainWindow", "Auto Exposure", 0));
        sharpnessLabel->setText(QApplication::translate("MainWindow", "Sharpness", 0));
        shutterLabel->setText(QApplication::translate("MainWindow", "Shutter", 0));
        gainLabel->setText(QApplication::translate("MainWindow", "Gain", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Advanced", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start Capture", 0));
        label->setText(QApplication::translate("MainWindow", "             Press any key to exit.", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
