#include "CSettings.h"

#include <stdexcept>
#include <QDebug>

CSettings::CSettings() {
}

QString CSettings::GetDriver() const {
		QSettings vSetting;
		vSetting.beginGroup("database");
    QString vDriver = vSetting.value("driver").toString();
		vSetting.endGroup();

    return vDriver;
}
int CSettings::GetPortNum() const {
    QSettings vSetting;
    vSetting.beginGroup("server");
    int vPortNum = vSetting.value("port").toInt();
    vSetting.endGroup();

    return vPortNum;
}

QString CSettings::GetConnectionString() const {
    QString vConnString;
    QSettings vSetting;
    vSetting.beginGroup("database");

    if (GetDriver() == "mysql") {
        vConnString = QString("host=%1;user=%2;password=%3;database=%4")
                      .arg(
                          vSetting.value("host").toString(),
                          vSetting.value("user").toString(),
                          vSetting.value("password").toString(),
                          vSetting.value("databaseName").toString()
                      );
    } else if (GetDriver() == "sqlite3") {
        vConnString = QString("database=%1")
                      .arg(
                          vSetting.value("databaseName").toString()
                      );
    } else {
        throw std::runtime_error("Nieobsługiwany silnik");
    }

    vSetting.endGroup();
    return vConnString;
}

//QString CSettings::GetHost() const {
//		QSettings vSetting;
//		vSetting.beginGroup("database");
//		QString driver = vSetting.value("host").toString();
//		vSetting.endGroup();

//		return driver;
//}

//QString CSettings::GetDatabaseName() const {
//		QSettings vSetting;
//		vSetting.beginGroup("database");
//		QString vDriver = vSetting.value("databaseName").toString();
//		vSetting.endGroup();

//		return vDriver;
//}

//QString CSettings::GetUser() const {
//		QSettings vSetting;
//		vSetting.beginGroup("database");
//		QString vDriver = vSetting.value("user").toString();
//		vSetting.endGroup();

//		return vDriver;
//}

//QString CSettings::GetPassword() const {
//		QSettings vSetting;
//		vSetting.beginGroup("database");
//		QString driver = vSetting.value("password").toString();
//		vSetting.endGroup();

//		return driver;
//}
