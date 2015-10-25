#ifndef CSERVERSETTINGSDIALOG_H
#define CSERVERSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class CServerSettingsDialog;
}

class CServerSettingsDialog : public QDialog {
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

  protected slots:

    /**
     * @brief on_mPushButtonResetDefault_clicked slot call when
    	 *				mPushButtonResetDefault clicked.
     */
    void on_mPushButtonResetDefault_clicked();

    /**
    	 * @brief on_mPushButtonResetDefault_clicked slot call
    	 *				when form is accepted.
     */
    void on_mButtonBoxOkCancel_accepted();

    /**
    	 * @brief on_mButtonBoxOkCancel_rejected slot call when
    	 *				form is rejected.
     */
    void on_mButtonBoxOkCancel_rejected();

  private:
    ///@todo
    void UpdateServerSettings();

    Ui::CServerSettingsDialog *ui;
};

#endif // CSERVERSETTINGSDIALOG_H
