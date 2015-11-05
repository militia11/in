#ifndef CReceiverWRAPPER_H
#define CReceiverWRAPPER_H

#include "src/libs/controllers/CReceiver.h"

/**
 * @brief Wrapper for CReceiver class
 *
 * Used to acces to some private/protected variables in tests
 */
class CReceiverWrapper : public CReceiver {
  public:
    CReceiverWrapper();

    char *TestGetMessageFileChecksum();
    int TestGetMessageSize();
    //void TestSetMessageFileChecksum();
		void TestSetMessageSize(int aSize);
		void TestConnect(QTcpSocket *aSocket);
		bool TestHasMessageCorrectFormat(char *aMessage);
		void TestSetMessage(char *aMessageFileChecksum);
	QTcpSocket *ForTestGetSocket();
	QByteArray *ForTestGetReveiveBuffer();
	int32_t *ForTestGetDataSize();
int TestConvertMessageArrayToInt();
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
