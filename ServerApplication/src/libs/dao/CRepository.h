#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include "libs/controllers/CSettings.h"

#include "libs/dao/CChecksumList.h"

#include <libs/dao/androidphotosdatabase.hpp>

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
    	 * database to model.
     */
    void RefreshModel();

    /**
     * @brief GetDatabase method is getter to
     * database connection object.
     *
    	 * @return server::AndroidPhotosDatabase is pointer to
     * the actual database.
     */
    server::AndroidPhotosDatabase *GetDatabase() const;

    /**
     * @brief GetChecksumList
     * @return checksums list.
     */
    CChecksumList *GetChecksumList() const;

    /**
     * @brief Method create database tables.
     */
    void PopulateDatabase();

    /**
     * @brief Connect function call to connect to database.
     */
    void Connect();

    /**
     * @brief Disconnect from database.
     */
    void Disconnect();

    bool mLastConnectionError;

  private:
    /**
     * @brief RefreshChecksums update checksum list represent as
     * mChecksumList variable.
     */
    void RefreshChecksums();

    /**
     * @brief mDatabase represent database connection object.
     */
    server::AndroidPhotosDatabase *mDatabase;
    CChecksumList *mChecksumList;
    QString mDriver;
    QString mConnectionString;
    //QJakisTableModel *mModel;
};

#endif // CREPOSITORY_H
