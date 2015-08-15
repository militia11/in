#include "CServerSettingsDialog.h"
#include "ui_CServerSettingsDialog.h"

CServerSettingsDialog::CServerSettingsDialog(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::CServerSettingsDialog) {
		ui->setupUi(this);
		ui->mSpinBoxPortNum->setValue(1234); /// @todo from QSettings
}

CServerSettingsDialog::~CServerSettingsDialog() {
		delete ui;
}

void CServerSettingsDialog::on_mPushButtonResetDefault_clicked() {

}

void CServerSettingsDialog::on_mButtonBoxOkCancel_accepted() {

}

void CServerSettingsDialog::on_mButtonBoxOkCancel_rejected() {
		reject();
}
