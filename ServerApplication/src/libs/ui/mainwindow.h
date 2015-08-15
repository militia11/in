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
    explicit MainWindow(QWidget *aParent = 0);
    ~MainWindow();

		void CloseEvent(QCloseEvent *aEvent);

  signals:

  private slots:
    void DisplayData(QByteArray aData);
    void ClientConnected();
		void ClientCreated();
		void ShowStatus(const char* aMessageStatus, int aTimeMsc);
		void RunServer();


  private:
    Ui::MainWindow *ui;
    CServer *mServer;
};

#endif // MAINWINDOW_H
