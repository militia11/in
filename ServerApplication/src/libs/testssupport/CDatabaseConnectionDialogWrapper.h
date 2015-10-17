#ifndef CDATABASECONNECTIONDIALOGWRAPPER_H
#define CDATABASECONNECTIONDIALOGWRAPPER_H

#include "libs/ui/CDatabaseConnectionDialog.h"

/**
 * @brief Wrapper for CDatabaseConnectionDialog class
 *
 * Used to acces to some private/protected variables in tests
 */
class CDatabaseConnectionDialogWrapper : public CDatabaseConnectionDialog
{
public:
	CDatabaseConnectionDialogWrapper();
};

#endif // CDATABASECONNECTIONDIALOGWRAPPER_H
