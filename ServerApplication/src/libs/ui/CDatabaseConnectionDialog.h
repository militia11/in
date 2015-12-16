#ifndef CDATABASECONNECTIONDIALOG_H
#define CDATABASECONNECTIONDIALOG_H

#include <QDialog>

#include "src/libs/dao/CRepository.h"

extern CRepository gRepository;

namespace Ui {

class CDatabaseConnectionDialog;
}

/**
 * @brief The CDatabaseConnectionDialog class
 */
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

    /**
     * @brief GetHost Getter for host
     *
     * @return Host
     */
    QString GetHost() const;

    /**
     * @brief GetDriver Getter for Driver
     *
     * @return Driver
     */
    QString GetDriver() const;

    /**
     * @brief GetDatabaseName Getter for database name
     *
     * @return Database name
     */
    QString GetDatabaseName() const;

    /**
     * @brief GetUser Getter for user
     *
     * @return User
     */
    QString GetUser() const;

    /**
     * @brief GetPassword Getter for password
     *
     * @return Password
     */
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

    /**
     * @brief mHost Host
     */
    QString mHost;

    /**
     * @brief mUser User
     */
    QString mUser;

    /**
     * @brief mDatabaseName Database name
     */
    QString mDatabaseName;

    /**
     * @brief mPassword Password
     */
    QString mPassword;

    /**
     * @brief mDriver Driver
     */
    QString mDriver;

    /**
     * @brief ui Pointer to user interface
     */
    Ui::CDatabaseConnectionDialog *ui;
};

#endif // CDATABASECONNECTIONDIALOG_H
