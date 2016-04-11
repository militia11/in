#include <QString>

int main(int argc, char *argv[]) {
  Q_UNUSED(argc);
  QString vCommand {"$PWD/run_unit_tests_server -silent"};
  vCommand.append(argv[1]);
  return system(qPrintable(vCommand));
}
