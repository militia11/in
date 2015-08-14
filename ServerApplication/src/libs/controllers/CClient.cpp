#include "CClient.h"

CClient::CClient(QObject *parent) :
    mReceiveBuffer(0),
    mReceiveByteCnt(0),
    mReceiveFrameNOKCnt(0),
    QTcpSocket(parent)
{
}
