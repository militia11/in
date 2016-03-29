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
    /**
     * @brief CAboutProgramDialog constructor
     *
     * @param parent
     */
    explicit CAboutProgramDialog(QWidget *parent = 0);

    /**
     * @brief CAboutProgramDialog constructor
     */
    ~CAboutProgramDialog();

  private slots:
    /**
     * @brief on_buttonBox_accepted
     */
    void on_buttonBox_accepted();

  private:
    /**
     * @brief ui
     */
    Ui::CAboutProgramDialog *ui;
};

#endif // CABOUTPROGRAMDIALOG_H
