#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

#include "libs/controllers/CClient.h"
#include "libs/controllers/IClient.h"

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
    void on_mPushButtonArchivePhoto_clicked();

  private:
    Ui::CMainWindow *ui;
		IClient *vClient;
};

#endif // CMAINWINDOW_H
