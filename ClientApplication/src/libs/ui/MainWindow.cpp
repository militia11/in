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

CMainWindow::CMainWindow(QWidget *aParent) :
  QMainWindow(aParent),
  ui(new Ui::CMainWindow) {
  ui->setupUi(this);
  qApp->setStyleSheet("QPushButton {color : #FFFF00; background-color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,"
                      "stop: 0 cyan,stop: 0.5 #0066FF, stop: 1 cyan); } "
                      "QPushButton:focus:pressed{ background-color: red; }QPushButton:focus{ "
                      "background-color:#00FF72; } QPushButton:hover{border-color:#00FF72; "
                      "background-color: qradialgradient(cx: 0.5, cy: 0.5, radius: 2, fx: 0.5, fy: 1, stop: 0 #182DFF, stop: 0.2 #00FF72, stop: 0.4 #182DFF); min-width: 10px; }");
}

CMainWindow::~CMainWindow() {
  delete vClient;
  vClient = nullptr;

  delete ui;
  ui = nullptr;
}

void CMainWindow::on_mPushButtonSendPhoto_clicked() {
  // WYSLIJ DANE PLIKU:
  //    Q_INIT_RESOURCE(client_resources);  // Use resources from different project
  ///@todo
  QImage vImageToSend = QImage(":/sample_photo.jpg", "JPG");
  QBuffer vBuffer;

  QImageWriter vWriter(&vBuffer, "JPG");
  vWriter.write(vImageToSend);

  QByteArray vData = vBuffer.data();
  qDebug() << "Czy udało się wysłać dane: " << vClient->WriteData(vData);
}

void CMainWindow::on_mPushButtonSendChecksum_clicked() {
  // wyslij checksum
  QByteArray vMessageData(">>336<");
  qDebug() << "sumaFile->" << vMessageData;
  qDebug() << "Czy udało się wysłać sume: " << vClient->WriteMessage(
             vMessageData);
}

void CMainWindow::on_mPushButtonConnect_clicked() {
  // POŁĄCZ
  vClient = new CClient(new QTcpSocket);
  QString vIpAddress = ui->textEdit->toPlainText();
  try {
   qDebug() << "Czy udało się połączyć z hostem: " <<
            vClient->ConnectToHost("5.172.247.219"); //192.168.56.1
  } catch (QAbstractSocket::SocketError vError) {
   ShowSocketException(vError);
  }
}

void CMainWindow::on_mPushButtonArchivePhoto_clicked() {
  // Archiwizuj zdjęcia
  vClient->UpdateServerPhotos();
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
      ui->label->setText("def error");
      break;
  }
}

void CMainWindow::on_pushButton_clicked() {
  // pokaz zdjecie z tel
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

  vPath += "/a.jpg";
  qDebug() << "Koncowy path:" << vPath;
  QImage image(vPath);
  ui->label->setPixmap(QPixmap::fromImage(image));
}
/*

QAbstractSocket::UnconnectedState  0 The socket is not connected.
QAbstractSocket::HostLookupState  1 The socket is performing a host name lookup.
QAbstractSocket::ConnectingState  2 The socket has started establishing a connection.
QAbstractSocket::ConnectedState 3 A connection is established.
QAbstractSocket::BoundState 4 The socket is bound to an address and port.
QAbstractSocket::ClosingState 6 The socket is about to close (data may still be waiting to be written).
QAbstractSocket::ListeningState 5 For internal use only.
*/

