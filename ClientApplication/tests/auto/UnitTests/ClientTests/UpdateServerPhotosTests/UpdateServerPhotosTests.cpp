#include <QString>
#include <QtTest>

#include "src/libs/dao/CRepository.h"
#include "tests/auto/UnitTests/testlib/CClientWrapper.h"

extern CRepository gRepository;

class UpdateServerPhotosTests : public QObject {
    Q_OBJECT

public:
    UpdateServerPhotosTests();

private Q_SLOTS:
    void TestUpdatePhotos();
};

UpdateServerPhotosTests::UpdateServerPhotosTests()
{
}

void UpdateServerPhotosTests::TestUpdatePhotos() {
    /*CClientWrapper vClient;
    vClient.ConnectToHost("localhost");
    vClient.UpdateServerPhotos();

    gRepository.PopulateRepository();
    QStringList vImagesPath = gRepository.GetImages();*/
}

QTEST_APPLESS_MAIN(UpdateServerPhotosTests)

#include "UpdateServerPhotosTests.moc"
