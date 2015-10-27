#ifndef CSERVERMOCK_H
#define CSERVERMOCK_H

#include "libs/controllers/IServer.h"
#include "libs/controllers/CReceiver.h"

#include <QString>
/**
 * @brief Mock of CReceiver used in unit tests
 */
class CServerMock : public IServer {
  public:
		const QString GetLog() const;

    /**
		 * @brief Mock of Run method
     */
    void Run();

    /**
		 * @brief Mock of StopListening method
     */
    void StopListening();

    /**
		 * @brief Mock of GetClient method
     *
		 * @return Object which represent  client class (CReceiver)
     */
    CReceiver *GetClient() const;
//?
	//signals:
    /**
     * @brief CreateClient signal is emitted when
         *              server create client.
     */
		//void CreateClient();

    /**
         * @brief MessageStatus signal is emmitted when status
         *              of server changed.
     *
     * @param aMessage is text given to CMainWindow.
     * @param aTimeMsc parameter is time while message being shown.
     */
		//void MessageStatus(const char *aMessage, int aTimeMsc);

    /**
     * @brief ChangeServerStatus emitted when server status
         *              changed.
     */
		//void ChangeServerStatus();

		private slots:
    /**
		 * @brief Mock of IncomingConnection method
     */
    void IncomingConnection();

    /**
		 * @brief Mock of ResumeAccepting method
     */
    void ResumeAccepting();

    /**
		 * @brief Mock of PauseAccepting method
     */
    void PauseAccepting();

    /**
		 * @brief Mock of ConnectClientSignals method
     */
    inline void ConnectClientSignals();

    /**
		 * @brief Mock of UpdatePortNum method
     */
    inline void UpdatePortNum();

  protected:
    /**
    * @brief Log of called methods
    */
		mutable QString mLog;
};

#endif // CSERVERMOCK_H
