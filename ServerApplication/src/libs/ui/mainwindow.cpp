#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CDatabaseConnectionDialog.h"
#include "CServerSettingsDialog.h"

MainWindow::MainWindow(QWidget *aParent) :
    QMainWindow(aParent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
		//RunServer();  // na koniec usunąć

		ConnectActionsSignals();
		ui->ActionStopServer->setEnabled(false);
		ui->ActionStopServer->setChecked(true);

		ShowStatus("Wyłączone nasłuchiwanie serwera", 2400);
}

MainWindow::~MainWindow() {
		delete mServer;
		delete ui;
}

void MainWindow::CloseEvent(QCloseEvent *aEvent) {
		int aa = 10;

		if (aa == 0) {
				aEvent->ignore();
		} else {
				aEvent->accept();
		}
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

		ConnectServerSignals();

		mServer->Run();

		ui->ActionStopServer->setChecked(false);
		ui->ActionRunServer->setEnabled(false);
		ui->ActionStopServer->setEnabled(true);
}

void MainWindow::StopServer() {
		mServer->StopListening();

		ui->ActionRunServer->setChecked(false);
		ui->ActionStopServer->setEnabled(false);
		ui->ActionRunServer->setEnabled(true);
}

void MainWindow::ServerSettings() {
		CServerSettingsDialog dialog;

		if (dialog.exec() == true ) {
				// TAK JAK ACCEPTED DZIAŁA
		}
}

void MainWindow::DatabaseConnectionSettings() {
		CDatabaseConnectionDialog dialog;

		if (dialog.exec() == true ) {
				// TAK JAK ACCEPTED DZIAŁA
		}
}

void MainWindow::ChangeActionServerStatus() {
		bool vStatus = ui->ActionRunServer->isChecked();

		ui->ActionRunServer->setEnabled(vStatus);
		ui->ActionStopServer->setEnabled(!vStatus);

		ui->ActionRunServer->setChecked(!vStatus);
		ui->ActionStopServer->setChecked(vStatus);
}

void MainWindow::ConnectServerSignals() {
		connect(mServer, SIGNAL(MessageStatus(const char *, int)),
						this, SLOT(ShowStatus(const char *, int)));

		connect(mServer, SIGNAL(newConnection()), this,
						SLOT(ClientConnected()));

		connect(mServer, SIGNAL(CreateClient()), this,
						SLOT(ClientCreated()));

		connect(mServer, SIGNAL(ChangeServerStatus()), this,
						SLOT(ChangeActionServerStatus()));
}

void MainWindow::ConnectActionsSignals() {
		connect(ui->ActionRunServer, SIGNAL(triggered()),
						this, SLOT(RunServer()));

		connect(ui->ActionStopServer, SIGNAL(triggered()),
						this, SLOT(StopServer()));

		connect(ui->ActionServerSettings, SIGNAL(triggered()),
						this, SLOT(ServerSettings()));

		connect(ui->ActionDataBaseConnection, SIGNAL(triggered()),
						this, SLOT(DatabaseConnectionSettings()));

		//		connect(ui->ActionCloseEvent, SIGNAL(triggered()),
		//						this, SLOT(CloseEvent(QCloseEvent*)));
}
