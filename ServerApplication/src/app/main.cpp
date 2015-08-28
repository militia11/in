#include "libs/ui/CMainwindow.h"

#include <QApplication>

#include "libs/dao/CRepository.h"
#include "libs/controllers/CSettings.h"
#include "libs/dao/CCheckSumList.h"

extern CRepository gRepository;

int main(int argc, char *argv[]) {
		QApplication vApplication(argc, argv);

		QApplication::setOrganizationName("Mateusz Michniewski");
		QApplication::setOrganizationDomain("Moja Domena");
		QApplication::setApplicationName("Android Synchronizator Serwer");

		CSettings vSettings;
		gRepository.SetSettings(vSettings.GetDriver(),
														vSettings.GetConnectionString());

		CMainWindow vMainWindow;
		vMainWindow.show();
		vMainWindow.ConnectToDatabaseAgain();

		return vApplication.exec();
}
