#include <QString>
#include <QtTest>

//#include "libs/controllers/CSettings.h"
//#include "libs/testssupport/CDatabaseConnectionDialogWrapper.h"
//#include "libs/ui/CServerSettingsDialog.h"

class SettingsTests : public QObject {
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
    //CSettings s;
    //CDatabaseConnectionDialogWrapper vDialog;


    /*vDialog.mDriver = "mysql";
    vDialog.mHost = "129.0.4.1";
    vDialog.mDatabaseName = "testDb";
    vDialog.mUser = "testUser";
    vDialog.mPassword = "0000";
    vDialog.SaveSettings();

    QString vExpectedConnectionString("host=129.0.4.1;user=testUser;password=0000;database=testDb");
    QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);*/
}

void SettingsTests::TestConnectionStringSQLiteDriver() {
    /*CDatabaseConnectionDialogWrapper vDialog;
    vDialog.mDriver = "sqlite3";
    vDialog.mDatabaseName = "testDbSqlite";
    vDialog.SaveSettings();

    QString vExpectedConnectionString("database=testDbSqlite");
    CSettings vSettings;

    QCOMPARE(vSettings.GetConnectionString(), vExpectedConnectionString);*/
}

void SettingsTests::TestDefaultPortNumber() {
    /*CServerSettingsDialog vDialog;
    vDialog.on_mPushButtonResetDefault_clicked();

    int vExpectedDefaultPortNuber = 1234;
    CSettings vSettings;

    QCOMPARE(vSettings.GetPortNumber(), vExpectedDefaultPortNuber); */
}

QTEST_APPLESS_MAIN(SettingsTests)

#include "SettingsTests.moc"
