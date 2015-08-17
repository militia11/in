#include "CSettings.h"

#include <stdexcept>
#include <QDebug>

CSettings::CSettings() {
}

QString CSettings::GetDriver() const {
	QSettings setting;
	setting.beginGroup("database");
	QString driver = setting.value("driver").toString();
	setting.endGroup();

	return driver;
}

QString CSettings::GetConnectionString() const {
	QString connString;
	QSettings setting;
	setting.beginGroup("database");

	if (GetDriver() == "mysql") {
		connString = QString("host=%1;user=%2;password=%3;database=%4")
			.arg(
				setting.value("host").toString(),
				setting.value("user").toString(),
				setting.value("password").toString(),
				setting.value("databaseName").toString()
			);
 } else if (GetDriver() == "sqlite3") {
	connString = QString("database=%1")
			.arg(
				setting.value("databaseName").toString()
			);
 } else {
	 throw std::runtime_error("Nieobsługiwany silnik");
 }

	setting.endGroup();
	return connString;
}

void CSettings::SaveSettings() {
	QSettings setting;

	setting.beginGroup("database");

	setting.setValue("driver", "mysql");
	setting.setValue("host", "localhost");
	setting.setValue("user", "mmichniewski");
	setting.setValue("databaseName", "dokumenty");
	setting.setValue("password", "end");

	setting.endGroup();

	qDebug() << "Saved";  // usunąć na koniec
}

