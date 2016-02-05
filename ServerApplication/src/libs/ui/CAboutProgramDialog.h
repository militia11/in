#ifndef CABOUTPROGRAMDIALOG_H
#define CABOUTPROGRAMDIALOG_H

#include <QDialog>

namespace Ui {
class CAboutProgramDialog;
}

class CAboutProgramDialog : public QDialog
{
    Q_OBJECT

  public:
    explicit CAboutProgramDialog(QWidget *parent = 0);
    ~CAboutProgramDialog();

  private slots:
    void on_buttonBox_accepted();

  private:
    Ui::CAboutProgramDialog *ui;
};

#endif // CABOUTPROGRAMDIALOG_H
