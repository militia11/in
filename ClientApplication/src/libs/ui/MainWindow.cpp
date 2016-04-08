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
  qApp->setStyleSheet("QPushButton {color : #FFFF00; background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
					  "stop: 0 cyan,stop: 0.5 #0066FF, stop: 1 cyan); } "
					  "QPushButton:focus:pressed{ background-color: red; }QPushButton:focus{ "
					  "background-color:#00FF72; } QPushButton:hover{border-color:#00FF72; "
					  "background-color: qradialgradient(cx: 0.5, cy: 0.5, radius: 2, fx: 0.5, fy: 1, stop: 0 #182DFF, stop: 0.2 #00FF72, stop: 0.4 #182DFF); min-width: 10px; }");
  populatePicturesList();
}

CMainWindow::~CMainWindow() {
  delete mClient;
  mClient = nullptr;

  delete ui;
  ui = nullptr;
}

void CMainWindow::duact(int s) {
  if (s == 99) {
	ui->label->setText("IN manage datea");
  } else if (s == 33) {
	ui->label_2->setText("not available!");
  } else if (s == 34) {
	ui->label_2->setText("in sss!");
  } else if (s == 35) {
	ui->label_2->setText("undefined!");
  } else if (s == 100) {
	ui->label_3->setText("write ok");
  } else if (s == 106) {
    ui->label_3->setText("udaoo write d");
  }  else if (s == 107) {
    ui->label_3->setText(" nie udaoo write d");
  }
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

void CMainWindow::on_mPushButtonSendChecksum_clicked() {
  // wyslij checksum
  QByteArray vMessageData(">>336<");
  qDebug() << "sumaFile->" << vMessageData;
  qDebug() << "Czy udało się wysłać sume: " << mClient->WriteMessage(
			 vMessageData);
}

void CMainWindow::on_mPushButtonConnect_clicked() {
  // POŁĄCZ
  mClient = new CClient(new QTcpSocket);
  connect(mClient, SIGNAL(action(int)), SLOT(duact(int)));
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
  // Archiwizuj zdjęcia
  mClient->UpdateServerPhotos();
}

void CMainWindow::populatePicturesList()
{gRepository.PopulateRepository();
	QStringList vPhotosNames = gRepository.GetImagesNames ();
	for(int i = 0; i < vPhotosNames.length(); i++) {
		ui->mPhotos->addItem(QString::number(i+1) + ": " + vPhotosNames[i]);
	}
}

void CMainWindow::ShowSocketException(QAbstractSocket::SocketError aError) {
  switch (aError) {
	case QAbstractSocket::SocketTimeoutError:
	  ui->label->setText("SocketTimeoutError: Socket is in closing, listening or bound state"); ///@todo I TESTY DO TEJ FUNKCJI później status bar zobaczyc na telefonie jak dziala ze zmiana ekranu  i dac
	  qDebug() <<
			   "SocketTimeoutError: Socket is in closing, listening or bound state"; ///@todo I TESTY DO TEJ FUNKCJI później status bar zobaczyc na telefonie jak dziala ze zmiana ekranu  i dac
	  break;

	case  QAbstractSocket::UnknownSocketError:
	  ui->label->setText("UnknownSocketError: The socket has started establishing a connection or the socket is not connected. Connecting or unconnected state");
	  qDebug() <<
			   "UnknownSocketError: The socket has started establishing a connection or the socket is not connected. Connecting or unconnected state";
	  break;

	case QAbstractSocket::HostNotFoundError:
	  ui->label->setText( "HostNotFoundError: The socket is performing a host name lookup. Socket in HostLookupState");
	  qDebug() <<
			   "HostNotFoundError: The socket is performing a host name lookup. Socket in HostLookupState";
	  break;

	case QAbstractSocket::NetworkError:
	  ui->label->setText("network error;");
	  qDebug() << "network error;";

	default:
	  ui->label->setText("default error");
	  break;
  }
}

void CMainWindow::on_mArchivizeInServer_clicked()
{ // ARCHIWIZUJ ZDJecie 1 !!!
	int aPhotoNumber = ui->mPhotos->currentRow();
	mClient->CheckPhoto(aPhotoNumber);
}
