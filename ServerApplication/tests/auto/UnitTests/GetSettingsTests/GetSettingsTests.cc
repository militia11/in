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
    void SaveSettingsInConfigHelper(
				QString aValue,
        QString aKey,
        QString aGroup);

  private Q_SLOTS:
		void TestGetServerPortNumber();
		void TestGetConnectionStringSQLiteDriver();
    void TestGetConnectionStringMySqlDriver();
      void TestGetConnectionStringMySqlDriverWithoutHost();
};

GetSettingsTests::GetSettingsTests()
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
  SaveSettingsInConfigHelper(QString("sqlite3"), "driver", "database");
  SaveSettingsInConfigHelper(QString("testDbSqLite"), "databaseName", "database");

  CSettings vSettings;
  QString vExpectedConnectionString("database=testDbSqLite");
  QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);
}

void GetSettingsTests::TestGetConnectionStringMySqlDriver()
{
  SaveSettingsInConfigHelper(QString("mysql"), "driver", "database");
  SaveSettingsInConfigHelper(QString("testDbMysql"), "databaseName", "database");
  SaveSettingsInConfigHelper(QString("localhost"), "host", "database");
  SaveSettingsInConfigHelper(QString("testUser"), "user", "database");
  SaveSettingsInConfigHelper(QString("testPassword"), "password", "database");

  CSettings vSettings;
  QString vExpectedConnectionString(
        "host=localhost;user=testUser;password=testPassword;database=testDbMysql");
  QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);
}

void GetSettingsTests::TestGetConnectionStringMySqlDriverWithoutHost()
{
  // This scenarios is possible
  SaveSettingsInConfigHelper(QString("mysql"), "driver", "database");
  SaveSettingsInConfigHelper(QString("testDbMysql"), "databaseName", "database");
  SaveSettingsInConfigHelper(QString("testUser"), "user", "database");
  SaveSettingsInConfigHelper(QString("testPassword"), "password", "database");

  CSettings vSettings;
  QString vExpectedConnectionString(
        "host=;user=testUser;password=testPassword;database=testDbMysql");
  QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);
}

QTEST_MAIN(GetSettingsTests)

#include "GetSettingsTests.moc"
