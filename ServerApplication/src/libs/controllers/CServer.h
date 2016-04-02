#ifndef CSERVER_H
#define CSERVER_H

#include "src/libs/controllers/IReceiverFactory.h"
#include "src/libs/controllers/IServer.h"

/**
 * @brief The CServer class represents server for synchronize data from mobile device
 *
 * CServer class inherits from QTcpServer. CServer listening for incoming connection.
 * When client connected to the specify port server pause listening and resume accepting
 * incoming connections when client disconnected
 */
class CServer : public IServer {
    Q_OBJECT

  public:
    /**
     * @brief CServer constructor
     *
     * @param aReceiverFactory Factory of receivers
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

    /**
     * @brief Receive data progress changed
     *
     * @param aProgress Progress
     */
    void ReceiveDataProgressChanged(int aProgress);

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
     * @brief TryConnect Try call Connect method and throw exception
     *        when it is socket error
     *
     * @param aSocket Socket
     */
	void TryConnect(QTcpSocket *aSocket);

	/**
     * @brief ListenOnSpecifyPort Verify Server listening status on specify port
     *
     * @return True if server not listening on specify port, otherwise false
	 */
	bool ListenOnSpecifyPort();

    /**
     * @brief SocketError attend socket exception
     *
     * @param aText socket error
     */
    void SocketError(const char *aText);

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
	 * @brief mReceiver receieive connection from mobile device
     */
    IReceiver *mReceiver;

    /**
     * @brief mPortNumber is port number which server listen
     */
    int mPortNumber;
};

#endif // CSERVER_H
