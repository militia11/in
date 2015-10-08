#include "CMainWindow.h"
#include <QApplication>
int main(int argc, char *argv[]) {
        QApplication vApplication(argc
, argv);
		CMainWindow w;
		w.show();

		return vApplication.exec();
}
