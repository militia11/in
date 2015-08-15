#ifndef CSERVER_H
#define CSERVER_H

#include <QTcpServer>
#include "libs/controllers/CClient.h"

/**
 * @brief The CServer class represents server for synchronize data from Android device.
 *
 * @details CServer class inherits from QTcpServer. CServer listening for incoming connection.
 * When client connected to the specify port server pause listening and resume accepting
 * incoming connections when client disconnected. @todo dopisać później
 */
class CServer : public QTcpServer {

		Q_OBJECT

	public:
		explicit CServer(QObject *parent = 0);
		~CServer();

		/**
		 * @brief Method called to start server
		 */
		void Run();
		void StopListening();

		CClient *GetClient() const;

	signals:
		void CreateClient();
		void MessageStatus(const char *aMessage, int aTimeMsc);

	private slots:
		/**
		 * @brief Slot called when new incoming connection come
		 */
		void IncomingConnection();
		void ResumeAccepting();



	private:
		CClient *mClient;
};

#endif // CSERVER_H
