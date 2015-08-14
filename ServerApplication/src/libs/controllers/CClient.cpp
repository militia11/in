#include "CClient.h"
#include <QDebug>

CClient::CClient(QObject *aParent) :
    QObject(aParent),
    mSocket(NULL),
    mReceiveBuffer(0),
    mReceiveByteCnt(0),
    mReceiveFrameNOKCnt(0)
{
    mReceiveDataMode = Mode_UnknownData;
}

void CClient::Connect(QTcpSocket *aSocket)
{
    if(aSocket) {
        mSocket = aSocket;
        QObject::connect(mSocket, SIGNAL(readyRead()), this, SLOT(NewData()));
    } else {
        emit mSocket->error();
    }

}

QTcpSocket *CClient::GetSocket() const
{
    return mSocket;
}

void CClient::SendData(char *aData)
{
    mSocket->write(aData);
}

void CClient::NewData()
{
    QByteArray vData = mSocket->readAll();
    if (!vData.isEmpty()) { // nie wiem czy ten if ma sens?

        for (int i = 0; i < vData.length(); i++) {
            char vTargetData = vData[i];

            switch (vTargetData) {

            case '>':
                mReceiveDataMode = Mode_Receive_Files;
                mReceiveByteCnt = 0;
                break;

            case '^':
                mReceiveDataMode = Mode_Receive_FileList;
                mReceiveByteCnt = 0;
                break;

            default:
                break;
            }

            if (mReceiveByteCnt >= 1023) { // Prevent buffer overflow
                mReceiveByteCnt = 0;
            }

            mReceiveBuffer[mReceiveByteCnt] = vData[i];
            ++mReceiveByteCnt;

            RouteData(mReceiveDataMode, vData[i]);
        }

      /* nie konieczne*/mSocket->write("Odebrano dane :");
      /* nie konieczne*/mSocket->write(vData);
    }

    emit ReadData(vData);
}

void CClient::ServeReceivedMessage(QByteArray aData)
{
    if (!HasMessageCorrectFormat(aData)) { //aData.length()
        //PrintMessage(":" + GetDeviceName() + ":IncorrectMessageFormat: ", aData, aLen);
        ++mReceiveFrameNOKCnt;
        return;
    }

//	if (!HasMessageCorrectChecksum(aData, aLen)) {
//		PrintMessage(":" + GetDeviceName() + ":IncorrectMessageChecksum: ", aData, aLen);
//		++mReceiveFrameFaultCnt;
//		return;
//	}

//	CMutexHelper vMutexHelper(&mMsgMutex);
//	BYTE* vAsciiDataBegin = aData+2;  // 2 bytes of header
//	int vAsciiMessageDataLength = aLen-6;  // 2 bytes of header, 2 of checksum, CR, LF
//	ConvertHexAsciiToBinary(vAsciiDataBegin, vAsciiMessageDataLength, mBinaryMessageData);

//	++mReceiveFrameOKCnt;
    //	RouteMessage(mBinaryMessageData, vAsciiMessageDataLength/2, aData);
}

bool CClient::HasMessageCorrectFormat(QByteArray aData)
{
    bool vCorrect = true;
    int vDataLen = aData.length();
    int vDataAndChecksumLength = vDataLen-4;  // 2 bytes of header, CR, LF

    if (aData[0] != '>') {  // begin character
        vCorrect =  false;
        qDebug() << "a";
    } else if (aData[1] != 'L' && aData[1] != 'D') {
        vCorrect = false;
        qDebug() << "b";
    } else if ((aData[vDataLen-2] != 0x0D) || (aData[vDataLen-1] != 0x0A)) {  // CR LF
        vCorrect = false;
        qDebug() << "c";
    } else {
        for (int i = 2; i < vDataAndChecksumLength; ++i) {
            if (!isxdigit(aData[i])) {
                vCorrect = false;
                qDebug() << "d";
            }
        }
    }

    return vCorrect;
}

void CClient::RouteData(ReceiveDataMode mReceiveDataMode, QByteRef aData)
{
    switch (mReceiveDataMode) {
    case Mode_Receive_FileList:


        break;
    case Mode_Receive_Files:
        if (aData[i] == 0x0A) {
            ServeReceivedMessage(mReceiveBuffer); //, mReceiveByteCnt
            mReceiveByteCnt = 0;
        }
        break;
    case Mode_UnknownData:
        break;

    default:
        break;
    }
}
