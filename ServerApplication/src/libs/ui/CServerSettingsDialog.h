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
	explicit CServerSettingsDialog(QWidget *parent = 0);
	~CServerSettingsDialog();

private:
	Ui::CServerSettingsDialog *ui;
};

#endif // CSERVERSETTINGSDIALOG_H
