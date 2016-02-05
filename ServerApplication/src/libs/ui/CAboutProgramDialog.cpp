#include "CAboutProgramDialog.h"
#include "ui_CAboutProgramDialog.h"

CAboutProgramDialog::CAboutProgramDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CAboutProgramDialog) {
  ui->setupUi(this);
}

CAboutProgramDialog::~CAboutProgramDialog() {
  delete ui;
}

void CAboutProgramDialog::on_buttonBox_accepted() {
  accept();
}
