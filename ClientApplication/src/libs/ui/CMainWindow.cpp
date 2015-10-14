#include "CMainWindow.h"
#include "ui_CMainWindow.h"

#include <iostream>
#include <QFile>
#include <QImage>				//?
#include <QImageWriter>
#include <QMessageBox>
#include <QTimer>

CMainWindow::CMainWindow(QWidget *aParent) :
    QMainWindow(aParent),
    ui(new Ui::CMainWindow) {
    ui->setupUi(this);
}

CMainWindow::~CMainWindow() {
    delete vClient;
    vClient = 0;

    delete ui;
    ui = 0;
}

void CMainWindow::on_mPushButtonSendPhoto_clicked() {
    //		Q_INIT_RESOURCE(client_resources);  // Use resources from diffrent project

    QImage vImageToSend = QImage(":/sample_photo.jpg", "JPG");
    QBuffer vBuffer;

    QImageWriter vWriter(&vBuffer, "JPG");
    vWriter.write(vImageToSend);

    QByteArray vData = vBuffer.data();

    qDebug() << "Czy udało się wysłać dane: " << vClient->WriteData(vData);
}

void CMainWindow::on_mPushButtonSendChecksum_clicked() {
    QByteArray vMessageData(">>336<");
    qDebug() << "sumaFile->" << vMessageData;
    qDebug() << "Czy udało się wysłać sume: " << vClient->WriteMessage(
                 vMessageData);
}

void CMainWindow::on_mPushButtonConnect_clicked() {
    vClient = new CClient;
    qDebug() << "Czy udało się połączyć z hostem: " <<
             vClient->ConnectToHost("5.172.247.219"); //192.168.56.1
}

void CMainWindow::on_mPushButtonShowPhoto_clicked() {
    QImage vImage = QImage (":/sample_photo.jpg", "JPG");
    ui->mLabelPhoto->setPixmap(QPixmap::fromImage(vImage));
}

void CMainWindow::on_mPushButtonArchivePhoto_clicked() {
    // algorytm wysyłanie sum i sprawdzanie
    vClient->UpdateServerPhotos();
}
