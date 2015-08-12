#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *aParent) :
  QMainWindow(aParent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  on_mPushButtonRun_clicked();
  connect(mServer, SIGNAL(SendData(QByteArray)), this,
         SLOT(DisplayData(QByteArray))) ;
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::DisplayData(QByteArray aData)
{
    ui->mTextEdit->setText(aData);
}

void MainWindow::on_mPushButtonRun_clicked()
{
  mServer = new CServer(this);
  mServer->Run();
// później dołożyć tu ma byc nie w konsturktorze !!!!!!!!!
//   connect(mServer, SIGNAL(SendData(QByteArray)), this,
//            SLOT(DisplayData(QByteArray))) ;
}
