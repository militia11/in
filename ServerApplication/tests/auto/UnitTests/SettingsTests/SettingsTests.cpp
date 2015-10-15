#include <QString>
#include <QtTest>

//#include "libs/controllers/CSettings.h"
#include "libs/ui/CDatabaseConnectionDialog.h"
#include "libs/ui/CServerSettingsDialog.h"

class SettingsTests : public CDatabaseConnectionDialog, CServerSettingsDialog {
		Q_OBJECT

	public:
		SettingsTests();

	private Q_SLOTS:
		void TestConnectionStringMySqlDriver();
		void TestConnectionStringSQLiteDriver();
		void TestDefaultPortNumber();
};

SettingsTests::SettingsTests() {
}

void SettingsTests::TestConnectionStringMySqlDriver() {
		CDatabaseConnectionDialog vDialog;
		vDialog.mDriver = "mysql";
		vDialog.mHost = "129.0.4.1";
		vDialog.mDatabaseName = "testDb";
		vDialog.mUser = "testUser";
		vDialog.mPassword = "0000";
		vDialog.SaveSettings();

		QString vExpectedConnectionString("host=129.0.4.1;user=testUser;password=0000;database=testDb");
		QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);
}

void SettingsTests::TestConnectionStringSQLiteDriver() {
	CDatabaseConnectionDialog vDialog;
	vDialog.mDriver = "sqlite3";
	vDialog.mDatabaseName = "testDbSqlite";
	vDialog.SaveSettings();

	QString vExpectedConnectionString("database=testDbSqlite");
	CSettings vSettings;

	QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);
}

void SettingsTests::TestDefaultPortNumber()
{
	CServerSettingsDialog vDialog;
	vDialog.on_mPushButtonResetDefault_clicked();

	int vExpectedDefaultPortNuber = 1234;
	CSettings vSettings;

	QCOMPARE(vSettings.GetPortNumber(), vExpectedDefaultPortNuber);
}

QTEST_APPLESS_MAIN(SettingsTests)

#include "SettingsTests.moc"
