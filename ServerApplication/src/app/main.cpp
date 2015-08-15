#include "libs/ui/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

		QApplication::setOrganizationName("Mateusz Michniewski");
		QApplication::setOrganizationDomain("Moja Domena");
		QApplication::setApplicationName("Android Synchronizator");

    MainWindow w;
    w.show();

    return a.exec();
}
