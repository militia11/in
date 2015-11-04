#ifndef CSETTINGS_H
#define CSETTINGS_H

#include <QSettings>

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
};
#endif // CSETTINGS_H
