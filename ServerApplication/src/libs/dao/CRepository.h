#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include "libs/controllers/CSettings.h"

//#include <QxOrm.h>

class CSettings;

/**
 * @brief The CRepository class represents
 *  Data Access Object class.
 *
 * @details CRepository class is programm repository. This class
 *  initialize communication to database. @todo dopisać
 */
class CRepository {
  public:
    /**
     * @brief CRepository constructor.
     */
    CRepository();

    /**
    * @brief Set database settings.
    */
    void SetSettings(const QString &aDriver, const QString &aHost,
                     const QString &aDatabaseName, const QString &aUser, const QString &aPassword);

    /**
     * @brief GetDatabase method is getter to
     * database connection object.
     *
     * @return qx::QxSqlDatabase is pointer to
     * the actual database.
     */
    //qx::QxSqlDatabase *GetDatabase();

    /**
     * @brief Method create database tables.
     */
    void PopulateDatabase();

    /**
     * @brief Connect to database.
     */
    void Connect();

    /**
     * @brief Disconnect from database.
     */
    void Disconnect();

    bool mLastConnectionError;

  private:
    /**
     * @brief mDatabase represent database connection object.
     */
    //qx::QxSqlDatabase *mDatabase;

    QString mDriver;
    QString mHost;
    QString mDatabaseName;
    QString mUser;
    QString mPassword;
};

#endif // CREPOSITORY_H
