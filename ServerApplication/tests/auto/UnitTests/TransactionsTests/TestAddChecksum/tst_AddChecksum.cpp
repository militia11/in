#include <QString>
#include <QtTest>

#include "libs/dao/CChecksumList.h"
#include "libs/dao/CRepository.h"

extern CRepository gRepository;

class AddChecksum : public QObject {
		Q_OBJECT

	public:
		AddChecksum();

	private Q_SLOTS:
		void TestAddChecksum();
};

AddChecksum::AddChecksum() {
}

void AddChecksum::TestAddChecksum() {
		int16_t vChecksum = 194;

		CChecksumList vChecksumList;
		vChecksumList.AddFileChecksum(vChecksum);

		QVERIFY(vChecksumList.CheckFileChecksum(vChecksum));

		// lub gdyby w programie byly problemy z dodawaniem sumy i sprawdzaniem
		// CChecksumList *vChecksumList = gRepository.GetChecksumList();
		// vChecksumList->AddFileChecksum(12);
}

QTEST_APPLESS_MAIN(AddChecksum)

#include "tst_AddChecksum.moc"
