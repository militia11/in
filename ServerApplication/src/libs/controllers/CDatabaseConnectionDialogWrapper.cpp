#include "CDatabaseConnectionDialogWrapper.h"



void CDatabaseConnectionDialogWrapper::TestSetDriver(QString aDriver)
{
  mDriver = aDriver;
}

void CDatabaseConnectionDialogWrapper::TestSaveSettings()
{
  SaveSettings();
}
