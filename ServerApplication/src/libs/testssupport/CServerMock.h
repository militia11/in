#ifndef CSERVERMOCK_H
#define CSERVERMOCK_H

#include "libs/controllers/IServer.h"
#include "libs/controllers/CClient.h"

#include <QString>
/**
 * @brief Mock of CClient used in unit tests
 */
class CServerMock : public IServer
{
public:
    /**
     * @brief Method called to start server.
     */
    void Run();

    /**
     * @brief Method called to stop listening server.
     */
    void StopListening();

    /**
     * @brief Method return CClient member of the class.
     *
     * @return Object which represent  client class (CClient).
     */
    CClient *GetClient() const;

signals:
    /**
     * @brief CreateClient signal is emitted when
         *              server create client.
     */
    void CreateClient();

    /**
         * @brief MessageStatus signal is emmitted when status
         *              of server changed.
     *
     * @param aMessage is text given to CMainWindow.
     * @param aTimeMsc parameter is time while message being shown.
     */
    void MessageStatus(const char *aMessage, int aTimeMsc);

    /**
     * @brief ChangeServerStatus emitted when server status
         *              changed.
     */
    void ChangeServerStatus();

    //private slots:
    /**
     * @brief Slot called when new incoming connection come.
     */
    void IncomingConnection();

    /**
     * @brief Method called to unblock incoming connection.
     */
    void ResumeAccepting();

    /**
     * @brief Method called to block incoming connection.
     */
    void PauseAccepting();

    /**
     * @brief Method connect client's signals to server's slots.
     */
    inline void ConnectClientSignals();

    /**
     * @brief UpdatePortNum get and update actually port number
     *              from programm config file to application.
     */
    inline void UpdatePortNum();

protected:
    /**
    * @brief Log of called methods
    */
    QString mLog;
};

#endif // CSERVERMOCK_H
