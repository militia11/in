#include <QString>
#include <QtTest>

#include "libs/controllers/CSettings.h"

class SettingsTests : public QObject {
		Q_OBJECT

	public:
		SettingsTests();

	private Q_SLOTS:
		void TestGetPortNuber();
};

SettingsTests::SettingsTests() {
}

void SettingsTests::TestGetPortNuber() {
	int vPortNumber = 3868;

	CSettings vSettings;

	QCOMPARE(vSettings.GetPortNumber(), vPortNumber);
}

QTEST_APPLESS_MAIN(SettingsTests)

#include "SettingsTests.moc"
