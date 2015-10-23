#ifndef CSERVERSETTINGSDIALOGWRAPPER_H
#define CSERVERSETTINGSDIALOGWRAPPER_H

#include "libs/ui/CServerSettingsDialog.h"
/**
 * @brief Wrapper for CServerSettingsDialog class
 *
 * Used to acces to some private/protected variables in tests
 */
class CServerSettingsDialogWrapper : public CServerSettingsDialog {
  public:
    CServerSettingsDialogWrapper();
};

#endif // CSERVERSETTINGSDIALOGWRAPPER_H
