#include "libs/ui/mainwindow.h"

#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  QTranslator translator;
  translator.load("sa_en_SE.qm");//QString("sa_en_SE.qm"));//+QLocale::system().name());
  a.installTranslator(&translator);

//  QTranslator qtTranslator;
//  qtTranslator.load(QString("qt_")+QLocale::system().name());
//  a.installTranslator(&qtTranslator);
  MainWindow w;
  w.show();

  return a.exec();
}
