#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include "libs/controllers/CSettings.h"

#include <litesql.hpp>

#include <QAbstractTableModel>

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

    virtual ~CRepository();
    /**
    * @brief Set database settings.
    */
    void SetSettings(const QString &aDriver,
                     const QString &aConnectionString);

    /**
     * @brief Refresh function refresh update data from
     * database to model
     */
    void Refresh();
    /**
     * @brief GetDatabase method is getter to
     * database connection object.
     *
     * @return server::database is pointer to
     * the actual database.
     */
    server::database *GetDatabase();

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
    server::database *mDatabase;
    QString mDriver;
    QString mConnectionString;
    //QJakisTableModel *mModel;
//    QString mHost;
//    QString mDatabaseName;
//    QString mUser;
//    QString mPassword;
};

#endif // CREPOSITORY_H
