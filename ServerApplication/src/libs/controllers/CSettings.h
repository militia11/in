#ifndef CSETTINGS_H
#define CSETTINGS_H

#include <QSettings>

class CSettings
{
public:
	/**
	 * @brief CSettings constructor.
	 */
	CSettings();

	/**
	 * @brief GetDriver method read settings from
	 * configuration file.
	 *
	 * @return QString driver name.
	 */
	QString GetDriver() const;

	/**
	 * @brief GetConnectionString method read settings from
	 * configuration file.
	 *
	 * @return QString of connection parameter.
	 */
	QString GetConnectionString() const;

	/**
	 * @brief SaveSettings method save database settings
	 * to configuration file.
	 */
	void SaveSettings();
};

#endif // CSETTINGS_H
