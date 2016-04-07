#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include <src/libs/dao/androidphotosdatabase.hpp>
#include <litesql.hpp>

#include <QAbstractTableModel>

#include "src/libs/controllers/CSettings.h"
#include "src/libs/dao/CChecksumList.h"

class CSettings;

/**
 * @brief The CRepository class represents
 *        Data Access Object class
 *
 * This class is server application repository. It's
 * initialize communication to database
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
   * @brief Update checksum list represent as
   *        mChecksumList variable
   */
  void UpdateChecksums();

  /**
   * @brief Set database settings
   */
  void SetSettings(const QString &aDriver,
				   const QString &aConnectionString);

  /**
   * @brief GetDatabase method is getter to
   *        database connection object
   *
   * @return server::AndroidPhotosDatabase is pointer to
   *         the actual database
   */
  server::AndroidPhotosDatabase *GetDatabase() const;

  /**
   * @brief GetChecksumList get list of checksums.
   *
   * @return Checksums list
   */
  CChecksumList *GetChecksumList() const;

  /**
   * @brief Method create database tables
   */
  void PopulateDatabase();

  /**
   * @brief Connect function call to connect to database
   */
  void Connect();

  /**
   * @brief Disconnect from database
   */
  void Disconnect();

  /**
   * @brief mLastConnectionError whever we have error in last
   *        connection
   */
  bool mLastConnectionError;

 protected:
  /**
   * @brief AttendDatabaseConnectionException attend
   *        connection exception
   *
   * @param aException Database connection error
   */
  void AttendDatabaseConnectionException(const char *aException);

  /**
   * @brief mDatabase represent database connection object.
   */
  server::AndroidPhotosDatabase *mDatabase;

  /**
   * @brief mChecksumList is list of checksums photos stored
   *        in database
   */
  CChecksumList *mChecksumList;

  /**
   * @brief mDriver is database driver
   */
  QString mDriver;

  /**
   * @brief mConnectionString is string to connect to database
   */
  QString mConnectionString;
};

#endif // CREPOSITORY_H
