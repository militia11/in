#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <iostream>
#include <QBuffer>
#include <QDebug>
#include <QFile>
#include <QImage>
#include <QImageWriter>
#include <QMessageBox>
#include <QStandardPaths>
#include <QTimer>

#include "src/libs/dao/CRepository.h"

extern CRepository gRepository;

CMainWindow::CMainWindow(QWidget *aParent) :
  QMainWindow(aParent),
  ui(new Ui::CMainWindow) {
  ui->setupUi(this);
  populatePicturesList();
}

CMainWindow::~CMainWindow() {
  delete mClient;
  mClient = nullptr;

  delete ui;
  ui = nullptr;
}

void CMainWindow::ShowStatus(QString aMessage)
{	ui->mStatus->setText (aMessage);
}

void CMainWindow::on_mPushButtonSendPhoto_clicked() {
  // wyslij dane pliku
  //QImage vImageToSend = QImage(":/sample_photo.jpg", "JPG");
  qDebug() << "standardLocations() PicturesLocation" <<
		   QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
  QStringList vPicturesLocation = QStandardPaths::standardLocations(
									QStandardPaths::PicturesLocation);

  QString vPath = vPicturesLocation.at(0);
  QDir vDir(vPath);
  QStringList vAllFiles =  vDir.entryList(QDir::Files);
  foreach (QString location, vAllFiles) {
	qDebug() << "file:" << location;
  }

  QString name("/");
  name.append(ui->textEdit->toPlainText());
  //    vPath += "/a.jpg";
  vPath += name;
  vPath += ".jpg";
  qDebug() << "Koncowy path:" << vPath;
  QImage vImageToSend(vPath);

  QBuffer vBuffer;

  QImageWriter vWriter(&vBuffer, "JPG");
  vWriter.write(vImageToSend);

  QByteArray vData = vBuffer.data();
  qDebug() << "Czy udało się wysłać dane: ";

  if (mClient->WriteData(vData)) {
	ui->label->setText("udalo");
  } else {
	ui->label->setText("NIE udalo");
  }
}

void CMainWindow::ShowStatus(QString aMessage) {
  ui->mStatus->setText (aMessage);
}

void CMainWindow::on_mPushButtonConnect_clicked() {
  mClient = new CClient(new QTcpSocket);
  connect(mClient, SIGNAL(SetStatus(QString)), SLOT(ShowStatus(QString)));
  QString vIpAddress = "192.168.8.100"; // ui->textEdit->toPlainText();

  try {
	qDebug() << "Czy udało się połączyć z hostem: " <<
			 mClient->ConnectToHost(vIpAddress) << "\n";
  } catch (QAbstractSocket::SocketError vError) {
	ShowSocketException(vError);
  }
}

void CMainWindow::on_mPushButtonArchivePhoto_clicked() {
  mClient->UpdateServerPhotos();
}

void CMainWindow::populatePicturesList() {
  gRepository.PopulateRepository();
  QStringList vPhotosNames = gRepository.GetImagesNames();

  for (int i = 0; i < vPhotosNames.length(); i++) {
	ui->mPhotos->addItem(QString::number(i + 1) + ": " + vPhotosNames[i]);
  }
}

void CMainWindow::ShowSocketException(QAbstractSocket::SocketError aError) {
  switch (aError) {
	case QAbstractSocket::SocketTimeoutError:
	  qDebug() <<
			   "SocketTimeoutError: Socket is in closing,"
			   "listening or bound state";
	  break;

	case  QAbstractSocket::UnknownSocketError:
	  qDebug() <<
			   "UnknownSocketError: The socket has started establishing"
			   "a connection or the socket is not connected. Connecting"
			   "or unconnected state";
	  break;

	case QAbstractSocket::HostNotFoundError:
	  qDebug() <<
			   "HostNotFoundError: The socket is performing a host name lookup."
			   "Socket in HostLookupState";
	  break;

	case QAbstractSocket::NetworkError:
	  qDebug() << "network error;";

	default:
	  qDebug() << "default error;";
	  break;
  }
}

void CMainWindow::on_mArchivizeInServer_clicked() {
  int vPhotoNumber = ui->mPhotos->currentRow();
  mClient->CheckPhoto(vPhotoNumber);
}

void CMainWindow::on_mPhotos_clicked(const QModelIndex &index) {
  int vPhotoNumber = index.row();
  QString vPath = gRepository.GetImagePath (vPhotoNumber);
  QImage vImage(vPath);
  ui->mPhotoLabel->setPixmap (QPixmap::fromImage(vImage));
}

void CMainWindow::on_mPhotos_doubleClicked(const QModelIndex &index) {
  int vPhotoNumber = index.row();
  mClient->CheckPhoto(vPhotoNumber);
}
