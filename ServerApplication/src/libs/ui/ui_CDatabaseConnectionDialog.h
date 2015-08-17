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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_CDatabaseConnectionDialog
{
public:

    void setupUi(QDialog *CDatabaseConnectionDialog)
    {
        if (CDatabaseConnectionDialog->objectName().isEmpty())
            CDatabaseConnectionDialog->setObjectName(QStringLiteral("CDatabaseConnectionDialog"));
        CDatabaseConnectionDialog->resize(338, 241);

        retranslateUi(CDatabaseConnectionDialog);

        QMetaObject::connectSlotsByName(CDatabaseConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *CDatabaseConnectionDialog)
    {
        CDatabaseConnectionDialog->setWindowTitle(QApplication::translate("CDatabaseConnectionDialog", "Po\305\202\304\205czenie z baz\304\205 danych", 0));
    } // retranslateUi

};

namespace Ui {
    class CDatabaseConnectionDialog: public Ui_CDatabaseConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDATABASECONNECTIONDIALOG_H
