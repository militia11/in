#ifndef CALCULATECHECKSUMHELPER_H
#define CALCULATECHECKSUMHELPER_H

#include <inttypes.h> //uint_t* and int_t* types
#include <QByteArray>

class CalculateChecksumHelper
{
public:
	CalculateChecksumHelper();
  static uint16_t CalculateFileDataChecksum(QByteArray aData);
};

#endif // CALCULATECHECKSUMHELPER_H
