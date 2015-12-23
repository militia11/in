#include "CValidator.h"

CValidator::CValidator()
{
}



#include "CGODValidator.h"

#include <QByteArray>
#include <QSet>
#include <QString>

uint8_t CGODValidator::CalculateChecksum(const QByteArray &aData) const {
  uint8_t vChecksum = 0;

  for (int i = 0; i < aData.length(); ++i) {
    vChecksum += aData.at(i);
  }

  return vChecksum;
}

bool CGODValidator::HasMessageCorrectChecksum(const QByteArray &aMessage)
  const {
  // For Ascii checksum - cut CRLF, take last two bytes
  QString vAciiDeclaratedChecksum = aMessage.mid(aMessage.length()-4, 2);
  bool vCorrectConversion = true;
  uint8_t vDeclaratedChecksum = vAciiDeclaratedChecksum.toUInt(
    &vCorrectConversion,
    16/* 16, because we use hex number system */);

  QByteArray vMessageWithoutChecksum = aMessage;
  vMessageWithoutChecksum.chop(4);  // Cut checksum and CRLF
  uint8_t vCalculatedChecksum = CalculateChecksum(vMessageWithoutChecksum);

  return vCorrectConversion && (vDeclaratedChecksum == vCalculatedChecksum);
}

bool CGODValidator::HasMessageCorrectFormat(const QByteArray &aMessage)
  const {
  bool vCorrect = true;
  QSet<char> vSubmodules;
  vSubmodules << 'D' << 'L' << 'T' << 'S';

  if (aMessage.length() < 6) {
  // Minimal length is 6 -> 2 bytes of header, 2 bytes of checksum
  // CR and LF
    vCorrect = false;
  } else if (aMessage.at(0) != '>') {
    vCorrect = false;
  } else if (!vSubmodules.contains(aMessage.at(1))) {
    vCorrect = false;
  } else if (aMessage.right(2).at(0) != 0x0D) {  // CR
    vCorrect = false;
  } else if (aMessage.right(2).at(1) != 0x0A) {  // LF
    vCorrect = false;
  } else {
    QString vHexPart = aMessage.mid(2, aMessage.length()-4);

    for (int i = 0; i < vHexPart.length(); ++i) {
      vCorrect = isxdigit(vHexPart.at(i).unicode());

      if (!vCorrect) {
        break;
      }
    }
  }

  return vCorrect;
}
