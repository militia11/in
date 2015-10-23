#ifndef ISERVER_H
#define ISERVER_H

#include <QObject>
#include <QTcpSocket>

#include <libs/controllers/CClient.h>
/**
 * @brief The IServer class is interface of CServer class
 */
class IServer : public QObject
{
public:
    /**
     * @brief Method called to start server.
     */
    virtual void Run() = 0;

    /**
     * @brief Method called to stop listening server.
     */
    virtual void StopListening() = 0;

    /**
     * @brief Method return CClient member of the class.
     *
     * @return Object which represent  client class (CClient).
     */
    virtual CClient *GetClient() const = 0;

signals:
    /**
     * @brief CreateClient signal is emitted when
         *              server create client.
     */
    virtual void CreateClient() = 0;

    /**
         * @brief MessageStatus signal is emmitted when status
         *              of server changed.
     *
     * @param aMessage is text given to CMainWindow.
     * @param aTimeMsc parameter is time while message being shown.
     */
    virtual void MessageStatus(const char *aMessage, int aTimeMsc) = 0;

    /**
     * @brief ChangeServerStatus emitted when server status
         *              changed.
     */
    virtual void ChangeServerStatus() = 0;

    //private slots:
    /**
     * @brief Slot called when new incoming connection come.
     */
    virtual void IncomingConnection() = 0;

    /**
     * @brief Method called to unblock incoming connection.
     */
    virtual void ResumeAccepting() = 0;

    /**
     * @brief Method called to block incoming connection.
     */
    virtual void PauseAccepting() = 0;

    /**
     * @brief Method connect client's signals to server's slots.
     */
    virtual inline void ConnectClientSignals() = 0;

    /**
     * @brief UpdatePortNum get and update actually port number
     *              from programm config file to application.
     */
    virtual inline void UpdatePortNum() = 0;
};

#endif // ISERVER_H

