#include "CMainwindow.h"
#include "ui_mainwindow.h"

#include <stdexcept>
#include <QBuffer>
#include <QImage>
#include <QImageReader>
#include <QMessageBox>

#include "CAboutProgramDialog.h"
#include "CDatabaseConnectionDialog.h"
#include "CServerSettingsDialog.h"
#include "src/libs/controllers/CReceiverFactoryImplementation.h"

extern CRepository gRepository;

CMainWindow::CMainWindow(QWidget *aParent) :
    QMainWindow(aParent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ConnectActionsSignals();

    ui->ActionStopServer->setEnabled(false);
    ui->ActionStopServer->setChecked(true);

    ShowStatus("Wyłączone nasłuchiwanie serwera", 2400);

    //Q_INIT_RESOURCE(server_resources);  // Use resources from diffrent project

   //QImage vAddedImage {QImage(":/logo_1.png", "PNG")};
   // ui->mImageLabel->setPixmap(QPixmap::fromImage(vAddedImage));
}

CMainWindow::~CMainWindow() {
    delete mServer;
    mServer = nullptr;

    delete ui;
    ui = nullptr;
}

bool CMainWindow::ConnectToDatabaseAgain() {
    gRepository.Disconnect();
    gRepository.Connect();
    return UpdateDatabaseOrConnection();
}

void CMainWindow::closeEvent(QCloseEvent *aEvent) {
    QString vMessage {"Wszystkie niezapisane zmiany zostaną utracone."
                       "Czy na pewno chcesz zamknąć program?"};
    int vAnswerButton {QMessageBox::warning( this, "WARNING", vMessage ,
                        QMessageBox::Yes | QMessageBox::No)};

    if (vAnswerButton == QMessageBox::Yes) {
        aEvent->accept();
    } else {
        aEvent->ignore();
    }
}

bool CMainWindow::UpdateDatabaseOrConnection() {
    if (IsDatabase()) {
            gRepository.PopulateDatabase();
            return true;
    } else {
            DatabaseConnectionSettings();
            return false;
    }
}

void CMainWindow::TryRunServer() {
    try {
            mServer->Run();
    } catch (std::runtime_error vError) {
            ServerListeningProblem(vError.what());
    }
}

bool CMainWindow::IsDatabase() {
    return gRepository.GetDatabase() != nullptr;
}

void CMainWindow::ServerListeningProblem(const char *aError) {
    ui->mStatusbar->showMessage(aError, 2400);
    qDebug() << QString::fromStdString(aError);
}
void CMainWindow::DisplayData(QByteArray aData) {
    QBuffer vBuffer(&aData);
    vBuffer.open( QIODevice::ReadOnly );
    QImageReader vReader(&vBuffer, "JPG");
    QImage vImage {vReader.read()};

    ui->mImageLabel->setPixmap(
            QPixmap::fromImage(vImage));
    ui->mListWidget->insertItem(0, aData);
    ui->mTextEdit->setText(aData);
}

void CMainWindow::ClientConnected() {
    connect(mServer->GetReceiver(), SIGNAL(ReadData(QByteArray)), this,
                    SLOT(DisplayData(QByteArray))) ;
}

void CMainWindow::ReceiverCreated() {
    connect(mServer->GetReceiver(), SIGNAL(MessageStatus(const char *, int)),
                    this, SLOT(ShowStatus(const char *, int)));
}

void CMainWindow::ShowStatus(const char *aMessageStatus, int aTimeMsc) {
    ui->mStatusbar->showMessage(aMessageStatus, aTimeMsc);
}

void CMainWindow::RunServer() {
    mServer = new CServer(new CReceiverFactoryImplementation);
    ConnectServerSignals();
    TryRunServer();

    ui->ActionStopServer->setChecked(false);
    ui->ActionRunServer->setEnabled(false);
    ui->ActionStopServer->setEnabled(true);
}

void CMainWindow::StopServer() {
    mServer->StopListening();

    ui->ActionRunServer->setChecked(false);
    ui->ActionStopServer->setEnabled(false);
    ui->ActionRunServer->setEnabled(true);
}

void CMainWindow::ServerSettings() {
    CServerSettingsDialog vDialog;
    vDialog.exec();
}

void CMainWindow::AboutProgram() {
    CAboutProgramDialog vDialog;
    vDialog.exec();
}

void CMainWindow::DatabaseConnectionSettings() {
    CDatabaseConnectionDialog vDialog;
    vDialog.exec();

    ConnectToDatabaseAgain();
}

void CMainWindow::ChangeActionServerStatus() {
    bool vStatus {ui->ActionRunServer->isChecked()};

    ui->ActionRunServer->setEnabled(!vStatus);
    ui->ActionStopServer->setEnabled(vStatus);

    ui->ActionRunServer->setChecked(vStatus);
    ui->ActionStopServer->setChecked(!vStatus);
}

void CMainWindow::ConnectServerSignals() {
    connect(mServer, SIGNAL(MessageStatus(const char *, int)), this,
                    SLOT(ShowStatus(const char *, int)));

    connect(mServer, SIGNAL(newConnection()), this,
                    SLOT(ClientConnected()));

    connect(mServer, SIGNAL(ConnectClient()), this,
                    SLOT(ReceiverCreated()));

    connect(mServer, SIGNAL(ChangeServerStatus()), this,
                    SLOT(ChangeActionServerStatus()));
}

void CMainWindow::ConnectActionsSignals() {
    connect(ui->ActionRunServer, SIGNAL(triggered()), this,
                    SLOT(RunServer()));

    connect(ui->ActionStopServer, SIGNAL(triggered()), this,
                    SLOT(StopServer()));

    connect(ui->ActionServerSettings, SIGNAL(triggered()), this,
                    SLOT(ServerSettings()));

    connect(ui->ActionDataBaseConnection, SIGNAL(triggered()), this,
                    SLOT(DatabaseConnectionSettings()));

    connect(ui->ActionInfo, SIGNAL(triggered()), this, SLOT(AboutProgram()));
}
