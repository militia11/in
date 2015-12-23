#include "src/libs/controllers/CSynchrionizer.h"

Synchrionizer::Synchrionizer()
{
}
// Copyright 2015 WB Electronics S.A.

// Copyright 2015 WB Electronics S.A.

#include "CGODSynchronizer.h"

QList<QByteArray> CGODSynchronizer::SynchronizeMessages(
  const QByteArray &aNewData) {
  QList<QByteArray> vNewMessageList;

  foreach (char aByte, aNewData) {  // NOLINT(whitespace/parens)
    if (aByte == '>') {
      mBuffer.resize(0);
    }

    mBuffer.append(aByte);

    if (aByte == 0x0A) {
      vNewMessageList.append(mBuffer);
    }
  }

  return vNewMessageList;
}
