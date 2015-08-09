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
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private slots:
  void DisplayData(QByteArray aData);

  void on_pushButton_clicked();

private:
    Ui::MainWindow *mUi;
    CServer *mServer;
};

#endif // MAINWINDOW_H
