#ifndef CCLIENTWRAPPER_H
#define CCLIENTWRAPPER_H

#include "libs/controllers/CClient.h"

/**
 * @brief Wrapper for CClient class
 *
 * Used to acces to some private/protected variables in tests
 */
class CClientWrapper : public CClient {
  public:
    CClientWrapper();

    char *TestGetMessageFileChecksum();
    int TestGetMessageSize();
    //void TestSetMessageFileChecksum();
    void TestSetMessageSize(int aSize);
    /* set je:
    	QTcpSocket *mSocket;
    	QByteArray *mReceiveBuffer;
    	int32_t *mDataSize;
    	ReceiveDataMode mReceiveDataMode;
    	char mMessageFileChecksum[1024];
    	int mMessageSize;
    	int mReceiveByteCount; */
};

#endif // CCLIENTWRAPPER_H
