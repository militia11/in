/********************************************************************************
** Form generated from reading UI file 'CDatabaseConnectionDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDATABASECONNECTIONDIALOG_H
#define UI_CDATABASECONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CDatabaseConnectionDialog
{
public:
    QDialogButtonBox *mButtonBoxOkCancel;
    QLabel *mLabelError;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelDriver;
    QLabel *labelUser;
    QLabel *labelHost;
    QLabel *labelPass;
    QLabel *labelDB;
    QLineEdit *mLineEditHost;
    QLineEdit *mLineEditUser;
    QLineEdit *mLineEditPassword;
    QLineEdit *mLineEditDatabase;
    QComboBox *mComboBoxDriver;

    void setupUi(QDialog *CDatabaseConnectionDialog)
    {
        if (CDatabaseConnectionDialog->objectName().isEmpty())
            CDatabaseConnectionDialog->setObjectName(QStringLiteral("CDatabaseConnectionDialog"));
        CDatabaseConnectionDialog->resize(477, 341);
        mButtonBoxOkCancel = new QDialogButtonBox(CDatabaseConnectionDialog);
        mButtonBoxOkCancel->setObjectName(QStringLiteral("mButtonBoxOkCancel"));
        mButtonBoxOkCancel->setGeometry(QRect(100, 280, 341, 32));
        mButtonBoxOkCancel->setOrientation(Qt::Horizontal);
        mButtonBoxOkCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        mLabelError = new QLabel(CDatabaseConnectionDialog);
        mLabelError->setObjectName(QStringLiteral("mLabelError"));
        mLabelError->setGeometry(QRect(20, 20, 421, 31));
        mLabelError->setStyleSheet(QStringLiteral("background-color : red; color : white; "));
        mLabelError->setAlignment(Qt::AlignCenter);
        formLayoutWidget = new QWidget(CDatabaseConnectionDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 70, 421, 201));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelDriver = new QLabel(formLayoutWidget);
        labelDriver->setObjectName(QStringLiteral("labelDriver"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelDriver);

        labelUser = new QLabel(formLayoutWidget);
        labelUser->setObjectName(QStringLiteral("labelUser"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelUser);

        labelHost = new QLabel(formLayoutWidget);
        labelHost->setObjectName(QStringLiteral("labelHost"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelHost);

        labelPass = new QLabel(formLayoutWidget);
        labelPass->setObjectName(QStringLiteral("labelPass"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelPass);

        labelDB = new QLabel(formLayoutWidget);
        labelDB->setObjectName(QStringLiteral("labelDB"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelDB);

        mLineEditHost = new QLineEdit(formLayoutWidget);
        mLineEditHost->setObjectName(QStringLiteral("mLineEditHost"));

        formLayout->setWidget(1, QFormLayout::FieldRole, mLineEditHost);

        mLineEditUser = new QLineEdit(formLayoutWidget);
        mLineEditUser->setObjectName(QStringLiteral("mLineEditUser"));

        formLayout->setWidget(2, QFormLayout::FieldRole, mLineEditUser);

        mLineEditPassword = new QLineEdit(formLayoutWidget);
        mLineEditPassword->setObjectName(QStringLiteral("mLineEditPassword"));
        mLineEditPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, mLineEditPassword);

        mLineEditDatabase = new QLineEdit(formLayoutWidget);
        mLineEditDatabase->setObjectName(QStringLiteral("mLineEditDatabase"));

        formLayout->setWidget(4, QFormLayout::FieldRole, mLineEditDatabase);

        mComboBoxDriver = new QComboBox(formLayoutWidget);
        mComboBoxDriver->setObjectName(QStringLiteral("mComboBoxDriver"));

        formLayout->setWidget(0, QFormLayout::FieldRole, mComboBoxDriver);


        retranslateUi(CDatabaseConnectionDialog);

        QMetaObject::connectSlotsByName(CDatabaseConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *CDatabaseConnectionDialog)
    {
        CDatabaseConnectionDialog->setWindowTitle(QApplication::translate("CDatabaseConnectionDialog", "Po\305\202\304\205czenie z baz\304\205 danych", 0));
        mLabelError->setText(QApplication::translate("CDatabaseConnectionDialog", "Dabase connection problem. Check settings.", 0));
        labelDriver->setText(QApplication::translate("CDatabaseConnectionDialog", "Driver:                             ", 0));
        labelUser->setText(QApplication::translate("CDatabaseConnectionDialog", "User:", 0));
        labelHost->setText(QApplication::translate("CDatabaseConnectionDialog", "Host name:                               ", 0));
        labelPass->setText(QApplication::translate("CDatabaseConnectionDialog", "Password:", 0));
        labelDB->setText(QApplication::translate("CDatabaseConnectionDialog", "Database:", 0));
    } // retranslateUi

};

namespace Ui {
    class CDatabaseConnectionDialog: public Ui_CDatabaseConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDATABASECONNECTIONDIALOG_H
