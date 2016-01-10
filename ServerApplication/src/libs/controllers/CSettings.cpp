#include "CSettings.h"

#include <stdexcept>

CSettings::CSettings() {
}

QString CSettings::GetDriver() const {
    QSettings vSettings;
    vSettings.beginGroup("database");
    QString vDriver {vSettings.value("driver").toString()};
    vSettings.endGroup();

    return vDriver;
}

int CSettings::GetPortNumber() const {
    QSettings vSettings;
    vSettings.beginGroup("server");
    int vPortNumber {vSettings.value("port").toInt()};
    vSettings.endGroup();

    return vPortNumber;
}

QString CSettings::GetConnectionString() const {
    QString vConnectionString;
    QSettings vSettings;
    vSettings.beginGroup("database");

    if (IsMySqlDriver()) {
        vConnectionString = QString("host=%1;user=%2;password=%3;database=%4")
                            .arg(
                                vSettings.value("host").toString(),
                                vSettings.value("user").toString(),
                                vSettings.value("password").toString(),
                                vSettings.value("databaseName").toString()
                            );
    } else if (IsSQLiteDriver()) {
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

bool CSettings::IsSQLiteDriver() const {
    return GetDriver() == "sqlite3";
}

bool CSettings::IsMySqlDriver() const {
    return GetDriver() == "mysql";
}
