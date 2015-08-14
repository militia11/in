#include "CClient.h"
#include <QDebug>

CClient::CClient(QObject *aParent) :
    QObject(aParent),
    mSocket(NULL),
    mReceiveBuffer(NULL),
    mReceiveByteCnt(0),
    mReceiveFrameNOKCnt(0)
{
    mReceiveDataMode = Mode_UnknownData;
}

CClient::~CClient()
{
    // dorobić WAZNE !!!!!!!!!!!1 i funkcje diskonekted tez wazne bardziej ją i tam delete mReceiveBuffer
}

void CClient::Connect(QTcpSocket *aSocket)
{
    if(aSocket) {
        mReceiveBuffer = new char[1025];
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
    char* vData = new char[16];
    mSocket->read(vData,16);

    //if (!vData.isEmpty()) { // nie wiem czy ten if ma sens?

        for (int i = 0; i < 16; i++) {
            char vTargetData = vData[i];
            qDebug() << "u"<<vData[i];
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

            //char vRouteTarget = vData[i];
            mReceiveBuffer[mReceiveByteCnt] = vData[i];
            ++mReceiveByteCnt;

            if (vData[i] == 0x0A) { // 0x0A samo A
                qDebug() << " yeah koniec :)" <<vData;

                for(int i=0;i<16;i++){
                    qDebug() << "b"<<vData[i];
                }
                //ServeReceivedMessage(mReceiveBuffer); //, mReceiveByteCnt
                mReceiveByteCnt = 0;
            }                                 //vData[i]
            //RouteData(mReceiveDataMode, vRouteTarget);

        }

      /* nie konieczne*/mSocket->write("Odebrano dane :");
      /* nie konieczne*/mSocket->write(vData);


    emit ReadData(vData);
}

void CClient::RouteData(ReceiveDataMode mReceiveDataMode, char aData)
{
    switch (mReceiveDataMode) {

    case Mode_Receive_FileList:

        break;
    case Mode_Receive_Files:
        qDebug() << "Mode_Receive_Files:";
        if (aData == 0x0A) {
            qDebug() << "Mode_Receive_Files: 0x0A :) hurra";
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

void CClient::ServeReceivedMessage(QByteArray aData)
{
    for(int i=0;i<aData.length();i++){
        qDebug()  << "adata serve" << aData[i];
    }
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

//    for(int i=0;i<aData.length();i++){
//        qDebug() << "b"<<aData[i];
//    }
//    if (aData[0] != '>') {  // begin character
//        vCorrect =  false;
//        qDebug() << "a" ;
//    } else if (aData[1] != 'L' && aData[1] != 'D') {
//        vCorrect = false;
//        qDebug() << "b"<<aData[1];
//    } else if ((aData[vDataLen-2] != 0x0D) || (aData[vDataLen-1] != 0x0A)) {  // CR LF
//        vCorrect = false;
//        qDebug() << "c";
//    } else {
//        for (int i = 2; i < vDataAndChecksumLength; ++i) {
//            if (!isxdigit(aData[i])) {
//                vCorrect = false;
//                qDebug() << "d";
//            }
//        }
//    }

    return vCorrect;
}


