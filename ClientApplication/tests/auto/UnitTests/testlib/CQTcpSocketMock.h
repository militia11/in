#ifndef CQTCPSOCKETMOCK_H
#define CQTCPSOCKETMOCK_H

#include <QTcpSocket>

/**
 * @brief The CQTcpSocketMock class is mock of QTcpSocket class
 */
class CQTcpSocketMock : public QTcpSocket {
  Q_OBJECT
 public:
  /**
   * @brief CQTcpSocketMock constructor
   *
   * @param parent Parent object
   */
  explicit CQTcpSocketMock(QObject *parent = 0);

  /**
   * @brief GetLog get actual log
   *
   * @return Log
   */
  const QString GetLog() const;

  /**
   * @brief waitForBytesWritten Mock of waitForBytesWritten method in QTcpSocket class
   *
   * @param msecs Miliseconds wait
   */
  virtual bool waitForBytesWritten(int msecs = 30000);
  /**
 * @brief connectToHost Mock of connectToHost method in QTcpSocket class
 *
 * @param address Host addres
 * @param port Port Number
 * @param openMode Open mode
 * @param protocol Protocol
 */
 virtual void connectToHost(const QString &hostName, quint16 port, OpenMode mode = ReadWrite, NetworkLayerProtocol protocol = AnyIPProtocol);

  /**
   * @brief ForTestSetState Call protected method setSocketState
   *        for unit tests
   *
   * @param aState State to set
   */
  void ForTestSetSocketState(QAbstractSocket::SocketState aState);

 protected:
  /**
   * @brief Log of called methods
   */
  mutable QString mLog;
};

#endif // CQTCPSOCKETMOCK_H
