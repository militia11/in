#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libs/controllers/CServer.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
  explicit MainWindow(QWidget *aParent = 0);
  ~MainWindow();
private slots:
  void DisplayData(QByteArray aData);
  void ONmPushButtonRunClicked();

private:
  Ui::MainWindow *ui;
  CServer *mServer;
};

#endif // MAINWINDOW_H
