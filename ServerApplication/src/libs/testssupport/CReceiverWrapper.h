#ifndef CReceiverWRAPPER_H
#define CReceiverWRAPPER_H

#include "src/libs/controllers/CReceiver.h"

/**
 * @brief Wrapper for CReceiver class
 *
 * Used to acces to some private/protected variables in tests
 */
class CReceiverWrapper : public CClient {
  public:
    CReceiverWrapper();

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

#endif // CReceiverWRAPPER_H
