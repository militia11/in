#ifndef CSETTINGS_H
#define CSETTINGS_H

#include <QSettings>

/**
 * @brief The CSettings class represents application settings
 */
class CSettings {
 public:
  /**
   * @brief CSettings constructor
   */
  CSettings();

  /**
   * @brief GetDriver method read settings from
   *        configuration file
   *
   * @return QString driver name
   */
  QString GetDriver() const;

  /**
   * @brief GetPortNum get port number
   *
   * @return Port number
   */
  int GetPortNumber() const;

  /**
   * @brief GetConnectionString method read settings
   *        fromconfiguration file
   *
   * @return QString of connection parameter
   */
  QString GetConnectionString() const;

 protected:
  /**
   * @brief IsSQLiteDriver Verify if it is SQLite driver
   *
   * @return True if it is SQLite driver, otherwise false
   */
  bool IsSQLiteDriver() const;

  /**
   * @brief IsMySqlDriver Verify if it is MySql driver
   *
   * @return True if it is MySql driver, otherwise false
   */
  bool IsMySqlDriver() const;
};
#endif // CSETTINGS_H
