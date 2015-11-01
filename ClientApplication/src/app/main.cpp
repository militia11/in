#include "src/libs/ui/CMainWindow.h"
#include <QApplication>
int main(int argc, char *argv[]) {
    QApplication vApplication(argc
                              , argv);
    CMainWindow vMainWindow;
    vMainWindow.show();

    return vApplication.exec();
}
