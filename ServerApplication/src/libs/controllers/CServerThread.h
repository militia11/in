#ifndef CSERVERTHREAD_H
#define CSERVERTHREAD_H

#include <QThread>
#include <QDebug>
#include <QTcpSocket>

class CServerThread : public QThread  {

    Q_OBJECT

public:
    explicit CServerThread(int aId, QObject *aParent = 0);
    void Run();

signals:
    void Error(QTcpSocket::SocketError aSocketError);
    void ReadData(QByteArray *aData);

   public slots:
    void ReadyRead();
    void ConnectionLosted();

   private:
    QTcpSocket *mSocket;
    int mSocketDescriptor;
};

#endif // CSERVERTHREAD_H
