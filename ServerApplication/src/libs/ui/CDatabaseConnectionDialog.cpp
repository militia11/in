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
		gRepository.SetSettings(vSettings.GetDriver(), vSettings.GetHost(),
														vSettings.GetDatabaseName(),
														vSettings.GetDatabaseName(), vSettings.GetPassword());
		UpdateSettings();
}

CDatabaseConnectionDialog::~CDatabaseConnectionDialog() {
		delete ui;
}

void CDatabaseConnectionDialog::on_mButtonBoxOkCancel_accepted() {
		UpdateMembers();
		SaveSettings();

		CSettings vSettings;
		gRepository.SetSettings(vSettings.GetDriver(), vSettings.GetHost(),
														vSettings.GetDatabaseName(), vSettings.GetUser(), vSettings.GetPassword());

		accept();
}

void CDatabaseConnectionDialog::on_mButtonBoxOkCancel_rejected() {
		reject();
}

void CDatabaseConnectionDialog::UpdateSettings() {
		QSettings vSettings;
		vSettings.beginGroup("database");
		QString vDriver = vSettings.value("driver").toString();

		ui->mLineEditDatabase->setText(vSettings.value("databaseName").toString());
		ui->mComboBoxDriver->setCurrentText(vDriver);

		if (vDriver == "mysql") {
				ui->mLineEditHost->setText(vSettings.value("host").toString());
				ui->mLineEditUser->setText(vSettings.value("user").toString());
				ui->mLineEditPassword->setText(vSettings.value("password").toString());
				ui->mComboBoxDriver->setCurrentIndex(0);
		} else {
				ui->mComboBoxDriver->setCurrentIndex(1);
		}
}

void CDatabaseConnectionDialog::SaveSettings() {
		QSettings vQSetting;
		vQSetting.beginGroup("database");
		vQSetting.setValue("host", mHost);
		vQSetting.setValue("user", mUser);
		vQSetting.setValue("databaseName", mDatabaseName);
		vQSetting.setValue("password", mPassword);

		if (ui->mComboBoxDriver->currentIndex() == 0) {
				mDriver = "mysql";
				vQSetting.setValue("driver", mDriver);
		} else {
				mDriver = "sqlite3";
				vQSetting.setValue("driver", mDriver);
		}

		vQSetting.endGroup();
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
