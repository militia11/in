#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>

#include "libs/controllers/CServer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {

		Q_OBJECT

  public:

		/**
		* @brief MainWindow constructor.
		*/
    explicit MainWindow(QWidget *aParent = 0);

		/**
		* @brief MainWindow desstructor.
		*/
    ~MainWindow();



  signals:

  private slots:
		void DisplayData(QByteArray aData);
		void ClientConnected();
		void ClientCreated();
		void ShowStatus(const char *aMessageStatus, int aTimeMsc);
		void RunServer();
		void StopServer(); // stop listening
		void ServerSettings();
		void DatabaseConnectionSettings();
		void ChangeActionServerStatus();

		///	@todo
		/**
		* @brief Close Application event communicate with user and question if
		* we really sure to close application.
		*/
		void closeEvent(QCloseEvent *aEvent);

	private:
		inline void ConnectServerSignals();
		inline void ConnectActionsSignals();

		Ui::MainWindow *ui;
    CServer *mServer;
};

#endif // MAINWINDOW_H
