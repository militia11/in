#include "src/libs/ui/CMainwindow.h"

#include <QApplication>

#include "src/libs/controllers/CSettings.h"
#include "src/libs/dao/CChecksumList.h"
#include "src/libs/dao/CRepository.h"

extern CRepository gRepository;

int main(int argc, char *argv[]) {
  QApplication vApplication(argc, argv);

  QApplication::setOrganizationName("Mateusz Michniewski");
  QApplication::setOrganizationDomain("Moja Domena");
  QApplication::setApplicationName("Android Synchronizator Serwer");

  CSettings vSettings;
  gRepository.SetSettings(
	vSettings.GetDriver(),
	vSettings.GetConnectionString());

  CMainWindow vMainWindow;
  vMainWindow.showMaximized();
  vMainWindow.ConnectToDatabaseAgain();

  return vApplication.exec();
}
