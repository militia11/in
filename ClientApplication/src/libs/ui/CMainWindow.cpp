#include "CMainWindow.h"
#include "ui_CMainWindow.h"

#include <iostream>
#include <QFile>
#include <QImage>
#include <QImageWriter>
#include <QMessageBox>
#include <QTimer>

CMainWindow::CMainWindow(QWidget *aParent) :
		QMainWindow(aParent),
		ui(new Ui::CMainWindow) {
		ui->setupUi(this);
}

CMainWindow::~CMainWindow() {
		delete ui;
		ui = 0;
}

void CMainWindow::on_mPushButtonSendPhoto_clicked() {
        QImage vImage = QImage(":/sample_photo.jpeg", "JPEG");
		QBuffer vBuffer;

		QImageWriter vWriter(&vBuffer, "JPEG");
		vWriter.write(vImage);

		QByteArray vData = vBuffer.data();

		int v = CalculateFileDataChecksum(vData);
		qDebug() << "suma->" << v;

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
        QImage vImage = QImage (":/sample_photo.jpeg", "JPEG");
		ui->mLabelPhoto->setPixmap(QPixmap::fromImage(vImage));
}

uint8_t CMainWindow::CalculateFileDataChecksum(QByteArray aData) {
		uint8_t vSum = 0;

		for (int i = 0; i < aData.length(); ++i) {
				vSum += aData[i];
		}

		return vSum;
}
