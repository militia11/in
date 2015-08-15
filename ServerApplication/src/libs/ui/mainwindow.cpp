#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CServerSettingsDialog.h"

MainWindow::MainWindow(QWidget *aParent) :
    QMainWindow(aParent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
	//	RunServer(false);  // na koniec usunąć

		connect(ui->ActionRunServer, SIGNAL(triggered()),
						this, SLOT(RunServer()));
		connect(ui->ActionStopServer, SIGNAL(triggered()),
						this, SLOT(StopServer()));

		connect(ui->ActionServerSettings, SIGNAL(triggered()),
						this, SLOT(ServerSettings()));

	//	 pauseAccepting() and resumeAccepting().
//		connect(ui->ActionCloseEvent, SIGNAL(triggered()),
//						this, SLOT(CloseEvent(QCloseEvent*)));
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::CloseEvent(QCloseEvent *aEvent)
{
	int aa = 10;
	if(aa==0){
		aEvent->ignore();
	}
	else
		aEvent->accept();
}

void MainWindow::DisplayData(QByteArray aData) {
    ui->mListWidget->insertItem(0, aData);
    ui->mTextEdit->setText(aData);
}

void MainWindow::ClientConnected() {
    connect(mServer->GetClient(), SIGNAL(ReadData(QByteArray)), this,
						SLOT(DisplayData(QByteArray))) ;
}

void MainWindow::ClientCreated() {
		connect(mServer->GetClient(), SIGNAL(MessageStatus(const char *, int)),
						this, SLOT(ShowStatus(const char *, int)));
}

void MainWindow::ShowStatus(const char *aMessageStatus, int aTimeMsc) {
		ui->mStatusbar->showMessage(aMessageStatus, aTimeMsc);
}

void MainWindow::RunServer() {

		mServer = new CServer(this);

		connect(mServer, SIGNAL(MessageStatus(const char *, int)),
						this, SLOT(ShowStatus(const char *, int)));

		connect(mServer, SIGNAL(newConnection()), this,
						SLOT(ClientConnected()));

		connect(mServer, SIGNAL(CreateClient()), this,
						SLOT(ClientCreated()));

		mServer->Run();

		ui->ActionStopServer->setChecked(false);
}

void MainWindow::StopServer()
{
		mServer->StopListening();

		ui->ActionRunServer->setChecked(false);
}

void MainWindow::ServerSettings()
{
	CServerSettingsDialog dialog;
	if(dialog.exec() == true ) {
		qDebug() << " srv settings"; // TAK JAK ACCEPTED DZIAŁA
	}
}
