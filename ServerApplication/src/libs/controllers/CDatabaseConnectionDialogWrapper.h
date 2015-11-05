#ifndef CDATABASECONNECTIONDIALOGWRAPPER_H
#define CDATABASECONNECTIONDIALOGWRAPPER_H

#include "src/libs/ui/CDatabaseConnectionDialog.h"

/**
 * @brief Wrapper for CDatabaseConnectionDialog class
 *
 * Used to acces to some private/protected variables in tests
 */
class CDatabaseConnectionDialogWrapper : public CDatabaseConnectionDialog {
  public:
    void TestSetDriver(QString aDriver);
    void TestSaveSettings();
};

#endif // CDATABASECONNECTIONDIALOGWRAPPER_H
