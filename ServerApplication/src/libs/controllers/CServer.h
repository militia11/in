#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include "libs/controllers/CServerThread.h"
#include "libs/controllers/CClient.h"

class CServer : public QTcpServer {

    Q_OBJECT

public:
    CServer(QObject *parent = 0);

    /**
     * @brief Method called when server run
     */
    void Run();

    /**
     * @brief Serve single received message
     */
    void ServeReceivedMessage(QByteArray aData);

    /**
     * @brief Check has message correct format
     *
     * As "Specyfikacja szeregowej komunikacji glowicy GOD-1_2015_04_29.doc"
     * said in chapter 3.1.2 message should consist from:
     * - message begin char: ">"
     * - module id:
     * 		- "S" for drive
     * 		- "L" for laser
     * 		- "D" for daylight camera
     * 		- "T" for termal camera
     * - data as hex-ascii string
     * - checksum (1 byte) as 2 hex-ascii chars
     * - new line as CR LF
     *
     * @return TRUE for correct format, FALSE for incorrect
     */
    bool HasMessageCorrectFormat(QByteArray aData);

public slots:
    void IncomingConnection();

    /**
     * @brief Method called on new incomming data
     *
     * @param aData is QByteArray buffer
     * @param aLen length of new data
     */
    void NewData();

signals:

    /**
     * @brief Signal emit when send data
     *
     * @param aData is QByteArray data which is sending
     */
    void SendData(QByteArray aData);

private:
    CClient *mClient;
};

#endif // CSERVER_H
