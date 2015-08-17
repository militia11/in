/********************************************************************************
** Form generated from reading UI file 'CServerSettingsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSERVERSETTINGSDIALOG_H
#define UI_CSERVERSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CServerSettingsDialog
{
public:
    QDialogButtonBox *mButtonBoxOkCancel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *mLabelPortNum;
    QSpinBox *mSpinBoxPortNum;
    QPushButton *mPushButtonResetDefault;
    QLabel *label;

    void setupUi(QDialog *CServerSettingsDialog)
    {
        if (CServerSettingsDialog->objectName().isEmpty())
            CServerSettingsDialog->setObjectName(QStringLiteral("CServerSettingsDialog"));
        CServerSettingsDialog->resize(275, 263);
        mButtonBoxOkCancel = new QDialogButtonBox(CServerSettingsDialog);
        mButtonBoxOkCancel->setObjectName(QStringLiteral("mButtonBoxOkCancel"));
        mButtonBoxOkCancel->setGeometry(QRect(-80, 210, 341, 32));
        mButtonBoxOkCancel->setOrientation(Qt::Horizontal);
        mButtonBoxOkCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(CServerSettingsDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 40, 241, 161));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        mLabelPortNum = new QLabel(formLayoutWidget);
        mLabelPortNum->setObjectName(QStringLiteral("mLabelPortNum"));

        formLayout->setWidget(0, QFormLayout::LabelRole, mLabelPortNum);

        mSpinBoxPortNum = new QSpinBox(formLayoutWidget);
        mSpinBoxPortNum->setObjectName(QStringLiteral("mSpinBoxPortNum"));
        mSpinBoxPortNum->setMaximum(9999);

        formLayout->setWidget(0, QFormLayout::FieldRole, mSpinBoxPortNum);

        mPushButtonResetDefault = new QPushButton(formLayoutWidget);
        mPushButtonResetDefault->setObjectName(QStringLiteral("mPushButtonResetDefault"));

        formLayout->setWidget(1, QFormLayout::SpanningRole, mPushButtonResetDefault);

        label = new QLabel(CServerSettingsDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 10, 281, 20));

        retranslateUi(CServerSettingsDialog);
        QObject::connect(mButtonBoxOkCancel, SIGNAL(accepted()), CServerSettingsDialog, SLOT(accept()));
        QObject::connect(mButtonBoxOkCancel, SIGNAL(rejected()), CServerSettingsDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CServerSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *CServerSettingsDialog)
    {
        CServerSettingsDialog->setWindowTitle(QApplication::translate("CServerSettingsDialog", "Ustawienia serwera", 0));
        mLabelPortNum->setText(QApplication::translate("CServerSettingsDialog", "Numer portu:         ", 0));
        mPushButtonResetDefault->setText(QApplication::translate("CServerSettingsDialog", "Przywr\303\263\304\207 ustawienia domy\305\233lne", 0));
        label->setText(QApplication::translate("CServerSettingsDialog", "moze ostrzegawczy jak w pracy wb schro", 0));
    } // retranslateUi

};

namespace Ui {
    class CServerSettingsDialog: public Ui_CServerSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSERVERSETTINGSDIALOG_H
