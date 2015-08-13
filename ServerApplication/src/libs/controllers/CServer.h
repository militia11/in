#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include "libs/controllers/CServerThread.h"

class CServer : public QTcpServer {

    Q_OBJECT

public:
    CServer(QObject *parent = 0);
    void Run();

//    /**
//     * @brief Serve single received message
//     */
//    void ServeReceivedMessage(BYTE *aData, int aLen);


public slots:
    void IncomingConnection();

    /**
     * @brief Method called on new incomming data
     *
     * @param aData pointer to buffer
     * @param aLen length of new data
     */
    void NewData();

signals:
    void SendData(QByteArray aData);

private:
    QTcpSocket *mSocket;
    QByteArray mReceiveBuffer;
    int mReceiveByteCnt;
};

#endif // CSERVER_H
