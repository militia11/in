#include "CServerSettingsDialog.h"
#include "ui_CServerSettingsDialog.h"

CServerSettingsDialog::CServerSettingsDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CServerSettingsDialog)
{
	ui->setupUi(this);
	ui->mSpinBoxPortNum->setValue(1234); /// @todo from QSettings
}

CServerSettingsDialog::~CServerSettingsDialog()
{
	delete ui;
}
