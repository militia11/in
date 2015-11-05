#include <QString>
#include <QtTest>
#include <QCoreApplication>

#include "../ServerApplication/src/libs/controllers/CSettings.h"
#include "../ServerApplication/src/libs/controllers/CDatabaseConnectionDialogWrapper.h"
#include "../ServerApplication/src/libs/ui/CServerSettingsDialog.h"

class SetSettingsTestsTest : public QObject
{
    Q_OBJECT

  public:
    SetSettingsTestsTest();

  private Q_SLOTS:
    void SetSettingsTests();
};

SetSettingsTestsTest::SetSettingsTestsTest()
{
}

void SetSettingsTestsTest::SetSettingsTests()
{
	//CDatabaseConnectionDialogWrapper vDialog;

	//vDialog.TestSetDriver("mysql");
	//vDialog.TestSaveSettings();
	/*vDialog.mHost = "129.0.4.1";
  vDialog.mDatabaseName = "testDb";
  vDialog.mUser = "testUser";
  vDialog.mPassword = "0000";
  */

	//CSettings vSettings;
	//qDebug()<<vSettings.GetConnectionString();
	//QString vExpectedConnectionString("host=129.0.4.1;user=testUser;password=0000;database=testDb");
  //QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);*/
}


/*
  void SettingsTests::TestConnectionStringSQLiteDriver() {
    /*CDatabaseConnectionDialogWrapper vDialog;
    vDialog.mDriver = "sqlite3";
    vDialog.mDatabaseName = "testDbSqlite";
    vDialog.SaveSettings();

    QString vExpectedConnectionString("database=testDbSqlite");
    CSettings vSettings;

    QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);
}

void SettingsTests::TestDefaultPortNumber() {
    CServerSettingsDialog vDialog;
    vDialog.on_mPushButtonResetDefault_clicked();

		int vExpectedDefaultPortNuber {1234};
    CSettings vSettings;

    QCOMPARE(vSettings.GetPortNumber(), vExpectedDefaultPortNuber);
}
*/

QTEST_MAIN(SetSettingsTestsTest)

#include "SetSettingsTests.moc"
