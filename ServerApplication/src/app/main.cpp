#include "libs/ui/mainwindow.h"

#include <QApplication>

#include <libs/dao/CRepository.h>
#include "libs/controllers/CSettings.h"

extern CRepository gRepository;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

		QApplication::setOrganizationName("Mateusz Michniewski");
		QApplication::setOrganizationDomain("Moja Domena");
		QApplication::setApplicationName("Android Synchronizator Serwer");

		CSettings vSettings;
		vSettings.SaveSettings();
		gRepository.SetSettings(vSettings.GetDriver(), vSettings.GetConnectionString());
		gRepository.Connect();
		gRepository.PopulateDatabase();

    MainWindow w;
    w.show();

    return a.exec();
}
