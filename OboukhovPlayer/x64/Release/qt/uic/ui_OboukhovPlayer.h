/********************************************************************************
** Form generated from reading UI file 'OboukhovPlayer.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OBOUKHOVPLAYER_H
#define UI_OBOUKHOVPLAYER_H

#include <QtCore/QVariant>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OboukhovPlayerClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *mainLayout;
    QVideoWidget *videoWidget;
    QHBoxLayout *controlsLayout;
    QPushButton *openButton;
    QPushButton *playButton;
    QPushButton *stopButton;
    QSlider *positionSlider;
    QLabel *timeLabel;
    QSlider *volumeSlider;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *OboukhovPlayerClass)
    {
        if (OboukhovPlayerClass->objectName().isEmpty())
            OboukhovPlayerClass->setObjectName("OboukhovPlayerClass");
        OboukhovPlayerClass->resize(900, 600);
        centralWidget = new QWidget(OboukhovPlayerClass);
        centralWidget->setObjectName("centralWidget");
        mainLayout = new QVBoxLayout(centralWidget);
        mainLayout->setObjectName("mainLayout");
        videoWidget = new QVideoWidget(centralWidget);
        videoWidget->setObjectName("videoWidget");

        mainLayout->addWidget(videoWidget);

        controlsLayout = new QHBoxLayout();
        controlsLayout->setObjectName("controlsLayout");
        openButton = new QPushButton(centralWidget);
        openButton->setObjectName("openButton");

        controlsLayout->addWidget(openButton);

        playButton = new QPushButton(centralWidget);
        playButton->setObjectName("playButton");

        controlsLayout->addWidget(playButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName("stopButton");

        controlsLayout->addWidget(stopButton);

        positionSlider = new QSlider(centralWidget);
        positionSlider->setObjectName("positionSlider");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(4);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(positionSlider->sizePolicy().hasHeightForWidth());
        positionSlider->setSizePolicy(sizePolicy);
        positionSlider->setMinimumSize(QSize(200, 0));
        positionSlider->setOrientation(Qt::Orientation::Horizontal);

        controlsLayout->addWidget(positionSlider);

        timeLabel = new QLabel(centralWidget);
        timeLabel->setObjectName("timeLabel");

        controlsLayout->addWidget(timeLabel);

        volumeSlider = new QSlider(centralWidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(50);
        volumeSlider->setOrientation(Qt::Orientation::Horizontal);

        controlsLayout->addWidget(volumeSlider);


        mainLayout->addLayout(controlsLayout);

        OboukhovPlayerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(OboukhovPlayerClass);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 900, 21));
        OboukhovPlayerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(OboukhovPlayerClass);
        statusBar->setObjectName("statusBar");
        OboukhovPlayerClass->setStatusBar(statusBar);

        retranslateUi(OboukhovPlayerClass);

        QMetaObject::connectSlotsByName(OboukhovPlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *OboukhovPlayerClass)
    {
        OboukhovPlayerClass->setWindowTitle(QCoreApplication::translate("OboukhovPlayerClass", "OboukhovPlayer", nullptr));
        openButton->setText(QCoreApplication::translate("OboukhovPlayerClass", "Open", nullptr));
        timeLabel->setText(QCoreApplication::translate("OboukhovPlayerClass", "00:00 / 00:00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OboukhovPlayerClass: public Ui_OboukhovPlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OBOUKHOVPLAYER_H
