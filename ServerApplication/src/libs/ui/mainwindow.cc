#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  mUi(new Ui::MainWindow)
{
  mUi->setupUi(this);
  on_pushButton_clicked();
  connect(mServer, SIGNAL(SendData(QByteArray)), this,
         SLOT(DisplayData(QByteArray))) ;
}

MainWindow::~MainWindow()
{
    delete mUi;
}

void MainWindow::DisplayData(QByteArray aData)
{
    mUi->textEdit->setText(aData);
}

void MainWindow::on_pushButton_clicked()
{
   mServer = new CServer(this);
   mServer->Run();
// później dołożyć tu ma byc nie w konsturktorze !!!!!!!!!
//   connect(mServer, SIGNAL(SendData(QByteArray)), this,
//            SLOT(DisplayData(QByteArray))) ;
}
