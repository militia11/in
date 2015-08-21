#include "CSettings.h"

#include <stdexcept>
#include <QDebug>

CSettings::CSettings() {
}

QString CSettings::GetDriver() const {
	QSettings vSetting;
	vSetting.beginGroup("database");
	QString driver = vSetting.value("driver").toString();
	vSetting.endGroup();

	return driver;
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

void CSettings::SaveSettings() {
	QSettings vSetting;

	vSetting.beginGroup("database");

	vSetting.setValue("driver", "mysql");
	vSetting.setValue("host", "localhost");
	vSetting.setValue("user", "mmichniewski");
	vSetting.setValue("databaseName", "dokumenty");
	vSetting.setValue("password", "end");

	vSetting.endGroup();

	qDebug() << "Saved";  // usunąć na koniec
}

