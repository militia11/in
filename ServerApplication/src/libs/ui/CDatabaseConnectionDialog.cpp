#include "CDatabaseConnectionDialog.h"
#include "ui_CDatabaseConnectionDialog.h"

CDatabaseConnectionDialog::CDatabaseConnectionDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CDatabaseConnectionDialog)
{
	ui->setupUi(this);
}

CDatabaseConnectionDialog::~CDatabaseConnectionDialog()
{
	delete ui;
}
