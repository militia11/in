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

	QString GetDriver() const;
	QString GetConnectionString() const;
	void SaveSettings();
};

#endif // CSETTINGS_H
