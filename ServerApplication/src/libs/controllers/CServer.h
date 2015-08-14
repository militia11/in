#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include "libs/controllers/CClient.h"

class CServer : public QTcpServer {

    Q_OBJECT

public:
    CServer(QObject *parent = 0);

    /**
     * @brief Method called when we want to start server
     */
    void Run();

    /**
     * @brief Serve single received message
     */
    void ServeReceivedMessage(QByteArray aData);

    /**
     * @brief Check has message correct format
     *
     * Message should consist from:
     * - message begin char: ">"
     * - module id:
     * 		- "L" for ?
     * 		- "D" for data
     * - data as hex-ascii string
     * - checksum (1 byte) as 2 hex-ascii chars
     * - new line as CR LF
     *
     * @return TRUE for correct format, FALSE for incorrect
     */
    bool HasMessageCorrectFormat(QByteArray aData);

    CClient *GetClient() const;

public slots:
    void IncomingConnection();

private:
    CClient *mClient;
};

#endif // CSERVER_H
