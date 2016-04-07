#include <QString>
#include <QtTest>

class CalculateChecksumTests : public QObject {
  Q_OBJECT

 public:
  CalculateChecksumTests();

 private Q_SLOTS:
  void Test();
};

CalculateChecksumTests::CalculateChecksumTests() {
}

void CalculateChecksumTests::Test() {
  QVERIFY(false);
}

QTEST_APPLESS_MAIN(CalculateChecksumTests)

#include "CalculateChecksumTests.moc"
