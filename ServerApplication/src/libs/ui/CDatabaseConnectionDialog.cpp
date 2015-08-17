#include "CDatabaseConnectionDialog.h"
#include "ui_CDatabaseConnectionDialog.h"

CDatabaseConnectionDialog::CDatabaseConnectionDialog(QWidget *aParent) :
		QDialog(aParent),
		ui(new Ui::CDatabaseConnectionDialog) {
		ui->setupUi(this);
}

CDatabaseConnectionDialog::~CDatabaseConnectionDialog() {
		delete ui;
}
