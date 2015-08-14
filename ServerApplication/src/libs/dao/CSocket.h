#ifndef CSOCKET_H
#define CSOCKET_H

#include <QTcpSocket>

class CSocket : public QTcpSocket
{
        Q_OBJECT
    public:
        explicit CSocket(QObject *parent = 0);

    signals:

    public slots:

};

#endif // CSOCKET_H
