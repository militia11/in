#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <inttypes.h> //uint_t* and int_t* types

#include <QMainWindow>

#include "libs/controllers/CClient.h"

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow {
		Q_OBJECT

	public:
		explicit CMainWindow(QWidget *aParent = 0);
		~CMainWindow();

	private slots:
		void on_mPushButtonSendPhoto_clicked();
		void on_mPushButtonSendChecksum_clicked();
		void on_mPushButtonConnect_clicked();
		void on_mPushButtonShowPhoto_clicked();

	private:
		uint8_t CalculateFileDataChecksum(QByteArray aData);
		Ui::CMainWindow *ui;
		CClient *vClient;
};

#endif // CMAINWINDOW_H
