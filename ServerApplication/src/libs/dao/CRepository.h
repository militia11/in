#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include <libs/dao/androidphotosdatabase.hpp>
#include <litesql.hpp>

#include <QAbstractTableModel>

#include "libs/controllers/CSettings.h"
#include "libs/dao/CChecksumList.h"

class CSettings;

/**
 * @brief The CRepository class represents
 *				Data Access Object class
 *
 * This class is server application repository. It's
 * initialize communication to database
 *
 * @todo dopisać
 */
class CRepository {
  public:
    /**
     * @brief CRepository constructor
     */
    CRepository();

    /**
     * @brief CRepository destructor
     */
    virtual ~CRepository();

    /**
     * @brief Set database settings
     */
    void SetSettings(const QString &aDriver,
                     const QString &aConnectionString);

    /**
     * @brief Refresh function refresh update data from
     *				database to model
     */
    void RefreshModel();

    /**
     * @brief GetDatabase method is getter to
     *				database connection object.
     *
     * @return server::AndroidPhotosDatabase is pointer to
     *				 the actual database.
     */
    server::AndroidPhotosDatabase *GetDatabase() const;

    /**
     * @brief GetChecksumList get list of checksums.
     *
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
     * @brief Disconnect from database
     */
    void Disconnect();

    /**
     * @brief mLastConnectionError whever we have error in last
     *				connection
     */
    bool mLastConnectionError;

  protected:
    /**
     * @brief RefreshChecksums update checksum list represent as
     *				mChecksumList variable
     */
    void RefreshChecksums();

    /**
     * @brief mDatabase represent database connection object.
     */
    server::AndroidPhotosDatabase *mDatabase;

    /**
     * @brief mChecksumList is list of checksums photos stored
     *				in database
     */
    CChecksumList *mChecksumList;

    /**
     * @brief mDriver is database driver
     */
    QString mDriver;

    /**
     * @brief mConnectionString is string to connect to database.
     */
    QString mConnectionString;

    //QJakisTableModel *mModel;
};

#endif // CREPOSITORY_H
