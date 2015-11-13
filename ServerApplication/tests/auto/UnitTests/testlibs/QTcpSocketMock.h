#ifndef QTCPSOCKETMOCK_H
#define QTCPSOCKETMOCK_H

#include <QTcpSocket>

class CTcpSocketMock : public QTcpSocket {
		Q_OBJECT

	public:
		explicit CTcpSocketMock(QObject *parent = 0);

		virtual void write(const char *data);
		/**
		 * @brief GetLog get actual log
		 *
		 * @return Log
		 */
		const QString GetLog() const;

	protected:
		/**
		 * @brief Log of called methods
		 */
		mutable QString mLog;
};

#endif // QTCPSOCKETMOCK_H
