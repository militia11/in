#include "libs/ui/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

		QApplication::setOrganizationName("Mateusz Michniewski");
		QApplication::setOrganizationDomain("Moja Domena");
		QApplication::setApplicationName("Synchronization Tool");

    MainWindow w;
    w.show();

    return a.exec();
}
