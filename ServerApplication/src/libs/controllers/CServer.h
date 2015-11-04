#ifndef CSERVER_H
#define CSERVER_H

#include "../ServerApplication/src/libs/controllers/IReceiverFactory.h"
#include "../ServerApplication/src/libs/controllers/IServer.h"

/**
 * @brief The CServer class represents server for synchronize data from mobile device
 *
 * CServer class inherits from QTcpServer. CServer listening for incoming connection.
 * When client connected to the specify port server pause listening and resume accepting
 * incoming connections when client disconnected
 *
 * @todo dopisać później
 */
class CServer : public IServer {
  Q_OBJECT

 public:
  /**
   * @brief CServer constructor
   */
  CServer(IReceiverFactory *aReceiversFactory);

  /**
   * @brief CServer destructor
   */
  ~CServer();

  /**
   * @brief Method called to start server
   */
  void Run();

  /**
   * @brief Method called to stop listening server
   */
  void StopListening();

  /**
   * @brief Method return CReceiver member of the class
   *
   * @return Object which represent client class (CReceiver)
   */
  IReceiver *GetReceiver() const;

 signals:
  /**
   * @brief ConnectClient signal is emitted when
   *        client is connected to server
   */
  void ConnectClient();

  /**
   * @brief MessageStatus signal is emmitted when status
   *        of server changed
   *
   * @param aMessage is text given to CMainWindow.
   * @param aTimeMsc parameter is time while message being shown
   */
  void MessageStatus(const char *aMessage, int aTimeMsc);

  /**
   * @brief ChangeServerStatus emitted when server status
   *        changed
   */
  void ChangeServerStatus();
  ///@todso moze private zbadać?
 protected slots:
  /**
   * @brief Slot called when new incoming connection come
   */
  void IncomingConnection();

  /**
   * @brief Method called to unblock incoming connection
   */
  void ResumeAccepting();

  /**
   * @brief Method called to block incoming connection
   */
  void PauseAccepting();

 protected:
  /**
   * @brief Method connect client's signals to server's slots
   */
  void ConnectClientSignals();

  /**
   * @brief UpdatePortNumber get and update actually port number
   *        from programm config file to application
   */
  void UpdatePortNumber();

  /**
   * @brief mReceiversFactory is Receivers factory
   */
  IReceiverFactory *mReceiversFactory;

  /**
   * @brief mReceiver communicate with mobile device and receives data
   */
  IReceiver *mReceiver;

  /**
   * @brief mPortNumber is port number which server listen
   */
  int mPortNumber;
};

#endif // CSERVER_H
