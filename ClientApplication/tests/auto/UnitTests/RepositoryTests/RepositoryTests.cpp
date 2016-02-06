#include <QString>
#include <QtTest>
#include "src/libs/dao/CRepository.h"

class RepositoryTests : public QObject {
    Q_OBJECT

public:
    RepositoryTests();

private Q_SLOTS:
    void TestPopulateAndGetImagesPaths();
};

RepositoryTests::RepositoryTests() {
}

void RepositoryTests::TestPopulateAndGetImagesPaths()
{
CRepository vRepostitory;
vRepostitory.PopulateRepository();
QStringList vAllFiles = vRepostitory.GetImages();

QStringList vPicturesLocation = QStandardPaths::standardLocations(
                                  QStandardPaths::PicturesLocation);
QString vValidPath = vPicturesLocation.at(0);
vValidPath += "/";

foreach (QString location, vAllFiles) {
   QVERIFY(location.contains(vValidPath));
}
}

QTEST_APPLESS_MAIN(RepositoryTests)

#include "RepositoryTests.moc"
