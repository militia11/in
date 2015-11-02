#ifndef ISERVER_H
#define ISERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include "src/libs/controllers/IReceiver.h"

/**
 * @brief The IServer class is interface of CServer class
 */
class IServer : public QTcpServer {
		Q_OBJECT

  public:
    /**
     * @brief Method called to start server
     */
    virtual void Run() = 0;

    /**
     * @brief Method called to stop listening server
     */
    virtual void StopListening() = 0;

    /**
     * @brief Method return CReceiver member of the class
     *
     * @return Object which represent  client class (CReceiver)
     */
    virtual IReceiver *GetReceiver() const = 0;

	private slots:
    /**
     * @brief Slot called when new incoming connection come
     */
    virtual void IncomingConnection() = 0;

    /**
     * @brief Method called to unblock incoming connection
     */
    virtual void ResumeAccepting() = 0;

    /**
     * @brief Method called to block incoming connection
     */
    virtual void PauseAccepting() = 0;

    /**
     * @brief Method connect client's signals to server's slots
     */
		virtual void ConnectClientSignals() = 0;

    /**
     * @brief UpdatePortNum get and update actually port number
     *              from programm config file to application
     */
		virtual void UpdatePortNumber() = 0;
};

#endif // ISERVER_H

