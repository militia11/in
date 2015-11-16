#include "CDatabaseConnectionDialog.h"
#include "ui_CDatabaseConnectionDialog.h"

CDatabaseConnectionDialog::CDatabaseConnectionDialog(QWidget *aParent) :
    QDialog(aParent),
    ui(new Ui::CDatabaseConnectionDialog) {
    ui->setupUi(this);

    if (gRepository.mLastConnectionError == true) {
        ui->mLabelError->setVisible(true);
    } else {
        ui->mLabelError->setVisible(false);
    }

    QStringList mDriverList;
    mDriverList << "MySql" << "SQLite";
    ui->mComboBoxDriver->addItems(mDriverList);
    ui->mComboBoxDriver->setCurrentText("");

    CSettings vSettings;
    gRepository.SetSettings(vSettings.GetDriver(),
                            vSettings.GetConnectionString());
    UpdateSettings();
}

CDatabaseConnectionDialog::~CDatabaseConnectionDialog() {
    delete ui;
}

void CDatabaseConnectionDialog::on_mButtonBoxOkCancel_accepted() {
    UpdateMembers();
    SaveSettings();

    CSettings vSettings;
    gRepository.SetSettings(vSettings.GetDriver(),
                            vSettings.GetConnectionString());
    accept();
}

void CDatabaseConnectionDialog::on_mButtonBoxOkCancel_rejected() {
    reject();
}

void CDatabaseConnectionDialog::UpdateSettings() {
    QSettings vQSettings;
    vQSettings.beginGroup("database");
    QString vDriver = vQSettings.value("driver").toString();

    ui->mLineEditDatabase->setText(vQSettings.value("databaseName").toString());
    ui->mComboBoxDriver->setCurrentText(vDriver);

    if (vDriver == "mysql") {
        ui->mLineEditHost->setText(vQSettings.value("host").toString());
        ui->mLineEditUser->setText(vQSettings.value("user").toString());
        ui->mLineEditPassword->setText(vQSettings.value("password").toString());
        ui->mComboBoxDriver->setCurrentIndex(0);
    } else {
        ui->mComboBoxDriver->setCurrentIndex(1);
    }
}

void CDatabaseConnectionDialog::SaveSettings() {
    QSettings vQSettings;
    vQSettings.beginGroup("database");
    vQSettings.setValue("host", mHost);
    vQSettings.setValue("user", mUser);
    vQSettings.setValue("databaseName", mDatabaseName);
    vQSettings.setValue("password", mPassword);

    if (ui->mComboBoxDriver->currentIndex() == 0) {
        mDriver = "mysql";
        vQSettings.setValue("driver", mDriver);
    } else {
        mDriver = "sqlite3";
        vQSettings.setValue("driver", mDriver);
    }

    vQSettings.endGroup();
}

void CDatabaseConnectionDialog::UpdateMembers() {
    mHost = ui->mLineEditHost->text();
    mUser = ui->mLineEditUser->text();
    mDatabaseName = ui->mLineEditDatabase->text();
    mPassword = ui->mLineEditPassword->text();
}
QString CDatabaseConnectionDialog::GetHost() const {
    return mHost;
}

QString CDatabaseConnectionDialog::GetDriver() const {
    return mDriver;
}

QString CDatabaseConnectionDialog::GetDatabaseName() const {
    return mDatabaseName;
}

QString CDatabaseConnectionDialog::GetUser() const {
    return mUser;
}

QString CDatabaseConnectionDialog::GetPassword() const {
    return mPassword;
}
