/********************************************************************************
** Form generated from reading UI file 'trialexp1.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIALEXP1_H
#define UI_TRIALEXP1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *captureFormatLineEdit_2;
    QLineEdit *captureNameLineEdit_2;
    QLabel *captureFormatLabel_2;
    QLabel *captureNameLabel_2;
    QLineEdit *leftSlitLimLineEdit_2;
    QLabel *slitThicknessLabel_2;
    QLineEdit *slitThicknessLineEdit_2;
    QLabel *leftSlitLimLabel_2;
    QLineEdit *rightSlitLimLineEdit_2;
    QLabel *rightSlitLimLabel_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *noImagesLabel_2;
    QLineEdit *noImagesLineEdit_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *waitTimeLabel_2;
    QLineEdit *waitTimeLineEdit_2;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *heightLabel_2;
    QLineEdit *heightLineEdit_2;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *widthLabel_2;
    QLineEdit *widthLineEdit_2;
    QLabel *label;
    QPushButton *startButton;
    QWidget *tab_2;
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
    QLabel *frameRateLabel;
    QLineEdit *frameRateLineEdit;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(512, 340);
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, -10, 531, 371));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        captureFormatLineEdit_2 = new QLineEdit(tab);
        captureFormatLineEdit_2->setObjectName(QStringLiteral("captureFormatLineEdit_2"));
        captureFormatLineEdit_2->setGeometry(QRect(400, 70, 101, 27));
        captureNameLineEdit_2 = new QLineEdit(tab);
        captureNameLineEdit_2->setObjectName(QStringLiteral("captureNameLineEdit_2"));
        captureNameLineEdit_2->setGeometry(QRect(400, 40, 101, 27));
        captureFormatLabel_2 = new QLabel(tab);
        captureFormatLabel_2->setObjectName(QStringLiteral("captureFormatLabel_2"));
        captureFormatLabel_2->setGeometry(QRect(280, 70, 112, 27));
        captureNameLabel_2 = new QLabel(tab);
        captureNameLabel_2->setObjectName(QStringLiteral("captureNameLabel_2"));
        captureNameLabel_2->setGeometry(QRect(280, 40, 102, 27));
        leftSlitLimLineEdit_2 = new QLineEdit(tab);
        leftSlitLimLineEdit_2->setObjectName(QStringLiteral("leftSlitLimLineEdit_2"));
        leftSlitLimLineEdit_2->setGeometry(QRect(400, 100, 101, 27));
        slitThicknessLabel_2 = new QLabel(tab);
        slitThicknessLabel_2->setObjectName(QStringLiteral("slitThicknessLabel_2"));
        slitThicknessLabel_2->setGeometry(QRect(280, 160, 92, 27));
        slitThicknessLineEdit_2 = new QLineEdit(tab);
        slitThicknessLineEdit_2->setObjectName(QStringLiteral("slitThicknessLineEdit_2"));
        slitThicknessLineEdit_2->setGeometry(QRect(400, 160, 101, 27));
        leftSlitLimLabel_2 = new QLabel(tab);
        leftSlitLimLabel_2->setObjectName(QStringLiteral("leftSlitLimLabel_2"));
        leftSlitLimLabel_2->setGeometry(QRect(290, 100, 78, 27));
        rightSlitLimLineEdit_2 = new QLineEdit(tab);
        rightSlitLimLineEdit_2->setObjectName(QStringLiteral("rightSlitLimLineEdit_2"));
        rightSlitLimLineEdit_2->setGeometry(QRect(400, 130, 101, 27));
        rightSlitLimLabel_2 = new QLabel(tab);
        rightSlitLimLabel_2->setObjectName(QStringLiteral("rightSlitLimLabel_2"));
        rightSlitLimLabel_2->setGeometry(QRect(280, 130, 87, 27));
        horizontalLayoutWidget = new QWidget(tab);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 40, 201, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        noImagesLabel_2 = new QLabel(horizontalLayoutWidget);
        noImagesLabel_2->setObjectName(QStringLiteral("noImagesLabel_2"));

        horizontalLayout->addWidget(noImagesLabel_2);

        noImagesLineEdit_2 = new QLineEdit(horizontalLayoutWidget);
        noImagesLineEdit_2->setObjectName(QStringLiteral("noImagesLineEdit_2"));

        horizontalLayout->addWidget(noImagesLineEdit_2);

        horizontalLayoutWidget_2 = new QWidget(tab);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 80, 201, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        waitTimeLabel_2 = new QLabel(horizontalLayoutWidget_2);
        waitTimeLabel_2->setObjectName(QStringLiteral("waitTimeLabel_2"));

        horizontalLayout_2->addWidget(waitTimeLabel_2);

        waitTimeLineEdit_2 = new QLineEdit(horizontalLayoutWidget_2);
        waitTimeLineEdit_2->setObjectName(QStringLiteral("waitTimeLineEdit_2"));

        horizontalLayout_2->addWidget(waitTimeLineEdit_2);

        horizontalLayoutWidget_3 = new QWidget(tab);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 120, 201, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        heightLabel_2 = new QLabel(horizontalLayoutWidget_3);
        heightLabel_2->setObjectName(QStringLiteral("heightLabel_2"));

        horizontalLayout_3->addWidget(heightLabel_2);

        heightLineEdit_2 = new QLineEdit(horizontalLayoutWidget_3);
        heightLineEdit_2->setObjectName(QStringLiteral("heightLineEdit_2"));

        horizontalLayout_3->addWidget(heightLineEdit_2);

        horizontalLayoutWidget_4 = new QWidget(tab);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 160, 201, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        widthLabel_2 = new QLabel(horizontalLayoutWidget_4);
        widthLabel_2->setObjectName(QStringLiteral("widthLabel_2"));

        horizontalLayout_4->addWidget(widthLabel_2);

        widthLineEdit_2 = new QLineEdit(horizontalLayoutWidget_4);
        widthLineEdit_2->setObjectName(QStringLiteral("widthLineEdit_2"));

        horizontalLayout_4->addWidget(widthLineEdit_2);

        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 230, 241, 41));
        startButton = new QPushButton(tab);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(70, 210, 121, 27));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        formLayoutWidget_2 = new QWidget(tab_2);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(20, 10, 211, 201));
        formLayout = new QFormLayout(formLayoutWidget_2);
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

        frameRateLabel = new QLabel(formLayoutWidget_2);
        frameRateLabel->setObjectName(QStringLiteral("frameRateLabel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, frameRateLabel);

        frameRateLineEdit = new QLineEdit(formLayoutWidget_2);
        frameRateLineEdit->setObjectName(QStringLiteral("frameRateLineEdit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, frameRateLineEdit);

        tabWidget->addTab(tab_2, QString());

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0));
        captureFormatLabel_2->setText(QApplication::translate("Dialog", "Capture Format:", 0));
        captureNameLabel_2->setText(QApplication::translate("Dialog", "Capture Name:", 0));
        slitThicknessLabel_2->setText(QApplication::translate("Dialog", "Slit Thickness", 0));
        leftSlitLimLabel_2->setText(QApplication::translate("Dialog", "LeftSlitLim:", 0));
        rightSlitLimLabel_2->setText(QApplication::translate("Dialog", "RightSlitLim:", 0));
        noImagesLabel_2->setText(QApplication::translate("Dialog", "Images:", 0));
        waitTimeLabel_2->setText(QApplication::translate("Dialog", "Wait Time:", 0));
        heightLabel_2->setText(QApplication::translate("Dialog", "Height:", 0));
        widthLabel_2->setText(QApplication::translate("Dialog", "Width:", 0));
        label->setText(QApplication::translate("Dialog", "             Press any key to exit.", 0));
        startButton->setText(QApplication::translate("Dialog", "Start Capture", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "General Settings", 0));
        brightnessLabel->setText(QApplication::translate("Dialog", "Brightness", 0));
        autoExposureLabel->setText(QApplication::translate("Dialog", "Auto Exposure", 0));
        sharpnessLabel->setText(QApplication::translate("Dialog", "Sharpness", 0));
        shutterLabel->setText(QApplication::translate("Dialog", "Shutter", 0));
        gainLabel->setText(QApplication::translate("Dialog", "Gain", 0));
        frameRateLabel->setText(QApplication::translate("Dialog", "Frame Rate", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "Advanced Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIALEXP1_H
