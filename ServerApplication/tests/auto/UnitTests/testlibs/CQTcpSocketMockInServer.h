#ifndef CQTCPSOCKETMOCKINSERVER_H
#define CQTCPSOCKETMOCKINSERVER_H

#include <QTcpSocket>

/**
 * @brief The CQTcpSocketMock class is mock of QTcpSocket class in server
 */
class CQTcpSocketMockInServer : public QTcpSocket
{
  public:
    /**
     * @brief CQTcpSocketMockInServer class constructor
     */
    CQTcpSocketMockInServer();

    /**
     * @brief GetLog get actual log
     *
     * @return Log
     */
    const QString GetLog() const;

    /**
     * @brief bytesAvailable Mock of bytesAvailable method for unit tests
     *
     * @return Integer equal 5 to unit tests
     */
    virtual qint64 bytesAvailable() const;

  protected:
    /**
     * @brief Log of called methods
     */
    mutable QString mLog;
};

#endif // CQTCPSOCKETMOCKINSERVER_H
