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

    CClient *GetClient() const;

public slots:
    void IncomingConnection();

private:
    CClient *mClient;
};

#endif // CSERVER_H
