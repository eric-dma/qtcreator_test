#include "widget.h"
#include "ui_widget.h"
#include <QCameraInfo>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QMediaRecorder>
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QList<QCameraInfo> cameras = QCameraInfo::availableCameras();
    if(cameras.count() > 0) {
        foreach(const QCameraInfo &cameraInfo, cameras) {
            qDebug() << cameraInfo.description();
        }
        camera = new QCamera(cameras.at(0));
    }
    viewfinder = new QCameraViewfinder(this);
    camera->setViewfinder(viewfinder);
    viewfinder->resize(600,350);
    imageCapture = new QCameraImageCapture(camera);
    camera->start();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    camera->setCaptureMode(QCamera::CaptureStillImage);
    QString fileName = QFileDialog::getSaveFileName();
    camera->searchAndLock();
    imageCapture->capture(fileName);
    camera->unlock();
}

void Widget::on_pushButton_2_clicked()
{
    recorder = new QMediaRecorder(camera);
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);
    recorder->setAudioSettings(audioSettings);

    QString fileName = QFileDialog::getSaveFileName();
    recorder->setOutputLocation(QUrl::fromLocalFile(fileName));
    recorder->record();

}
