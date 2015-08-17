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
	/**
	 * @brief CDatabaseConnectionDialog constructor.
	 */
	explicit CDatabaseConnectionDialog(QWidget *aParent = 0);

	/**
	 * @brief CDatabaseConnectionDialog destructor.
	 */
	~CDatabaseConnectionDialog();

private:
	Ui::CDatabaseConnectionDialog *ui;
};

#endif // CDATABASECONNECTIONDIALOG_H
