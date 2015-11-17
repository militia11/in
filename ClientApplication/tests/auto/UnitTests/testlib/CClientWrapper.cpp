#include "CClientWrapper.h"

QByteArray CClientWrapper::ForTestIntToArray(int32_t aSource) {
		return IntToArray(aSource);
}

QByteArray CClientWrapper::ForTestPrepareMessageData(int16_t aChecksum) {
		return PrepareMessageData(aChecksum);
}
