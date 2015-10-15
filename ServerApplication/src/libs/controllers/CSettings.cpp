#include "CSettings.h"

#include <stdexcept>
#include <QDebug>

CSettings::CSettings() {
}

QString CSettings::GetDriver() const {
		QSettings vSettings;
		vSettings.beginGroup("database");
		QString vDriver = vSettings.value("driver").toString();
		vSettings.endGroup();

    return vDriver;
}
int CSettings::GetPortNumber() const {
		QSettings vSettings;
		vSettings.beginGroup("server");
		int vPortNum = vSettings.value("port").toInt();
		vSettings.endGroup();

    return vPortNum;
}

QString CSettings::GetConnectionString() const {
		QString vConnectionString;
		QSettings vSettings;
		vSettings.beginGroup("database");

    if (GetDriver() == "mysql") {
				vConnectionString = QString("host=%1;user=%2;password=%3;database=%4")
                      .arg(
													vSettings.value("host").toString(),
													vSettings.value("user").toString(),
													vSettings.value("password").toString(),
													vSettings.value("databaseName").toString()
                      );
    } else if (GetDriver() == "sqlite3") {
				vConnectionString = QString("database=%1")
                      .arg(
													vSettings.value("databaseName").toString()
                      );
    } else {
        throw std::runtime_error("Nieobsługiwany silnik");
    }

		vSettings.endGroup();

		return vConnectionString;
}
