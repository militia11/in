#include "CServerSettingsDialog.h"
#include "ui_CServerSettingsDialog.h"

CServerSettingsDialog::CServerSettingsDialog(QWidget *aParent) :
		QDialog(aParent),
		ui(new Ui::CServerSettingsDialog) {
		ui->setupUi(this);
		ui->mSpinBoxPortNum->setValue(1234); /// @todo from QSettings
}

CServerSettingsDialog::~CServerSettingsDialog() {
		delete ui;
}

void CServerSettingsDialog::on_mPushButtonResetDefault_clicked() {
///@todo
}

void CServerSettingsDialog::on_mButtonBoxOkCancel_accepted() {
	//int vDefaultPortNumber = 1234;
	/// @todo save to settings
}

void CServerSettingsDialog::on_mButtonBoxOkCancel_rejected() {
		reject();
}
