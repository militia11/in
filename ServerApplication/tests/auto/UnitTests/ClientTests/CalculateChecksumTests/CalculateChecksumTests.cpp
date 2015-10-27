#include <QString>
#include <QtTest>

#include "libs/controllers/CReceiver.h"

class CalculateChecksumTests : public QObject {
    Q_OBJECT

  public:
    CalculateChecksumTests();

  private Q_SLOTS:
    void test();
};

CalculateChecksumTests::CalculateChecksumTests() {
}

void CalculateChecksumTests::test() {

}

QTEST_APPLESS_MAIN(CalculateChecksumTests)

#include "CalculateChecksumTests.moc"
