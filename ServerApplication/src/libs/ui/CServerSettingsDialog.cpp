#include "CServerSettingsDialog.h"
#include "ui_CServerSettingsDialog.h"

#include <QSettings>
#include <QMessageBox>

CServerSettingsDialog::CServerSettingsDialog(QWidget *aParent) :
    QDialog(aParent),
    ui(new Ui::CServerSettingsDialog) {
    ui->setupUi(this);

    UpdateServerSettings();
}

CServerSettingsDialog::~CServerSettingsDialog() {
    delete ui;
}

void CServerSettingsDialog::on_mPushButtonResetDefault_clicked() {

    QString vMessage = "Czy na pewno przywrócić ustawienia domyślne?";
    int vAnswer = QMessageBox::question(this, "Uwaga", vMessage,
                                        QMessageBox::Yes | QMessageBox::No);

    if (vAnswer == QMessageBox::Yes) {
        const int vDefaultPortNum = 1234;
        ui->mSpinBoxPortNum->setValue(vDefaultPortNum);

        QSettings vQSetting;
        vQSetting.beginGroup("server");
        vQSetting.setValue("port", vDefaultPortNum);
        vQSetting.endGroup();
    }
}

void CServerSettingsDialog::on_mButtonBoxOkCancel_accepted() {
    QSettings vQSetting;
    vQSetting.beginGroup("server");
    int vPortNum = ui->mSpinBoxPortNum->value();
    vQSetting.setValue("port", QString::number(vPortNum));
    vQSetting.endGroup();
}

void CServerSettingsDialog::on_mButtonBoxOkCancel_rejected() {
    reject();
}

void CServerSettingsDialog::UpdateServerSettings() {
    QSettings vSettings;
    vSettings.beginGroup("server");
    QString vHostNum = vSettings.value("port").toString();
    ui->mSpinBoxPortNum->setValue(vHostNum.toInt());
    vSettings.endGroup();
}
