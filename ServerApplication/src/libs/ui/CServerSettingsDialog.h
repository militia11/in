#ifndef CSERVERSETTINGSDIALOG_H
#define CSERVERSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class CServerSettingsDialog;
}

class CServerSettingsDialog : public QDialog
{
	Q_OBJECT

public:
	/**
	 * @brief CServerSettingsDialog constructor.
	 */
	explicit CServerSettingsDialog(QWidget *aParent = 0);

	/**
	 * @brief CServerSettingsDialog destructor.
	 */
	~CServerSettingsDialog();

private slots:
	void on_mPushButtonResetDefault_clicked();

	void on_mButtonBoxOkCancel_accepted();

	void on_mButtonBoxOkCancel_rejected();

private:
	Ui::CServerSettingsDialog *ui;
};

#endif // CSERVERSETTINGSDIALOG_H
