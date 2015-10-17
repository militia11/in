#include <QString>
#include <QtTest>

#include "libs/controllers/CClient.h"

class ConvertIntToArrayTests : public QObject {
		Q_OBJECT

	public:
		ConvertIntToArrayTests();

	private Q_SLOTS:
		void TestConvertIntToArrayTest();
};

ConvertIntToArrayTests::ConvertIntToArrayTests() {

}

void ConvertIntToArrayTests::TestConvertIntToArrayTest() {
		int32_t vNumber = 12;

		CClient vClient;
		QByteArray vConvertedData = vClient.IntToArray(vNumber);

		QDataStream vStream(&vConvertedData, QIODevice::ReadWrite);
		vStream << vNumber;

		const char *vDataAsHexAscii =
				qPrintable(QString(vConvertedData.toHex().toUpper()));

		QCOMPARE(vDataAsHexAscii, "0000000C");

		// Qt 5.4 have function toStdString which is ideal for this compare
		// but it is not compatibile with Qt MySql driver
}

QTEST_APPLESS_MAIN(ConvertIntToArrayTests)

#include "ConvertIntToArrayTests.moc"
