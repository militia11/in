#ifndef CDATABASECONNECTIONDIALOG_H
#define CDATABASECONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class CDatabaseConnectionDialog;
}

class CDatabaseConnectionDialog : public QDialog
{
	Q_OBJECT

public:
	explicit CDatabaseConnectionDialog(QWidget *parent = 0);
	~CDatabaseConnectionDialog();

private:
	Ui::CDatabaseConnectionDialog *ui;
};

#endif // CDATABASECONNECTIONDIALOG_H
