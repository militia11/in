#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "src/libs/controllers/CSettings.h"

///@todo temp settings zrobic zapisywanie gdzie indziej
class GetSettingsTests : public QObject
{
    Q_OBJECT

  public:
		GetSettingsTests();

  private:
    void initTestCase();
    void cleanupTestCase();

		void SaveSettingsInConfigHelper(
				QString aValue,
        QString aKey,
        QString aGroup);

  private Q_SLOTS:
		void TestGetServerPortNumber();
		void TestGetConnectionStringSQLiteDriver();
		void TestGetConnectionStringMySqlDriver();
};

GetSettingsTests::GetSettingsTests()
{
}

void GetSettingsTests::initTestCase()
{

}

void GetSettingsTests::cleanupTestCase()
{

}

void GetSettingsTests::SaveSettingsInConfigHelper(QString aValue, QString aKey, QString aGroup)
{
	QSettings vQSettings;
	vQSettings.beginGroup(aGroup);
	vQSettings.setValue(aKey, aValue);
	vQSettings.endGroup();
}

void GetSettingsTests::TestGetServerPortNumber()
{
	CSettings vSettings;

	int vExpectedPortNumber {4639};
	SaveSettingsInConfigHelper(QString::number(vExpectedPortNumber), "port", "server");

QCOMPARE(vSettings.GetPortNumber(), vExpectedPortNumber);
}

void GetSettingsTests::TestGetConnectionStringSQLiteDriver()
{

}

void GetSettingsTests::TestGetConnectionStringMySqlDriver()
{

}

	//qDebug()<<vSettings.GetConnectionString();
	//QString vExpectedConnectionString("host=129.0.4.1;user=testUser;password=0000;database=testDb");
  //QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);*/
/*
  void SettingsTests::TestConnectionStringSQLiteDriver() {
		CDatabaseConnectionDialogWrapper vDialog;
    vDialog.mDriver = "sqlite3";
    vDialog.mDatabaseName = "testDbSqlite";
    vDialog.SaveSettings();

    QString vExpectedConnectionString("database=testDbSqlite");
    CSettings vSettings;

    QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);
}
*/
QTEST_MAIN(GetSettingsTests)

#include "GetSettingsTests.moc"
