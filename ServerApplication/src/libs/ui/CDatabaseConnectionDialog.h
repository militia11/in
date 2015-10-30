#ifndef CDATABASECONNECTIONDIALOG_H
#define CDATABASECONNECTIONDIALOG_H

#include <QDialog>

#include "libs/dao/CRepository.h"

extern CRepository gRepository;

namespace Ui {
class CDatabaseConnectionDialog;
}

class CDatabaseConnectionDialog : public QDialog {
    Q_OBJECT

  public:
    /**
     * @brief CDatabaseConnectionDialog constructor
     */
    explicit CDatabaseConnectionDialog(QWidget *aParent = 0);

    /**
     * @brief CDatabaseConnectionDialog destructor
     */
    ~CDatabaseConnectionDialog();

    QString GetHost() const;
    QString GetDriver() const;
    QString GetDatabaseName() const;
    QString GetUser() const;
    QString GetPassword() const;

  private slots:
    /**
     * @brief on_mButtonBoxOkCancel_accepted slot call when form is accepted
     */
    void on_mButtonBoxOkCancel_accepted();

    /**
     * @brief on_mButtonBoxOkCancel_rejected slot when form is rejected
     */
    void on_mButtonBoxOkCancel_rejected();

  protected:
    /**
    	 * @brief Update database settings from configuration file
       *				to form labels
     */
    void UpdateSettings();

    /**
       * @brief Save database settings to configuration file
     */
    void SaveSettings();

    /**
       * @brief Update class members to actual form labels
     */
    void UpdateMembers();

    QString mHost;
    QString mUser;
    QString mDatabaseName;
    QString mPassword;
    QString mDriver;
    Ui::CDatabaseConnectionDialog *ui;
};

#endif // CDATABASECONNECTIONDIALOG_H
