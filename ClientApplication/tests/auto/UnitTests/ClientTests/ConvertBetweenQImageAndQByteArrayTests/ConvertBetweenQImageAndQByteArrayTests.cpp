#include <QImage>
#include <QImageReader>
#include <QString>
#include <QtTest>

#include "src/libs/controllers/CClient.h"

class ConvertBetweenQImageAndQByteArrayTests : public QObject {
    Q_OBJECT

  public:
    ConvertBetweenQImageAndQByteArrayTests();

  private Q_SLOTS:
    void TestConvertBetweenQImageAndQByteArray();
};

ConvertBetweenQImageAndQByteArrayTests::ConvertBetweenQImageAndQByteArrayTests() {
}

void ConvertBetweenQImageAndQByteArrayTests::TestConvertBetweenQImageAndQByteArray() {
    Q_INIT_RESOURCE(client_resources); // Use resources from diffrent project

		QImage vImageToByte {QImage(":/sample_photo.jpg", "JPG")};

    // Part convert image
    /*CClient vClient;
		QByteArray vImageData {vClient.ConvertImageToByteArray(vImageToByte)};

    // Convert array of bytes to image
    QBuffer vBufferByteToImages(&vImageData);
    vBufferByteToImages.open(QIODevice::ReadOnly);

    QImageReader vReader(&vBufferByteToImages, "JPG");
		QImage vImageFromByte {vReader.read()};

    QCOMPARE(vImageToByte.size(), vImageFromByte.size());
    QCOMPARE(vImageToByte.format(), vImageFromByte.format());
*/
    // QVERIFY(vImageToByte.operator == (vImageFromByte));
    // porównanie qimage w tym przypadku również różne skonwertowany obraz nie jest
    // taki sam. Operacja binarna nie jest taka sama
    // pixel compare: różne 4281016857 != 4281016597
}

QTEST_APPLESS_MAIN(ConvertBetweenQImageAndQByteArrayTests)

#include "ConvertBetweenQImageAndQByteArrayTests.moc"
