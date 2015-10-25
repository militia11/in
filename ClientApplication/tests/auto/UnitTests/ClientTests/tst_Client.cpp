#include <QString>
#include <QtTest>

class Client : public QObject
{
	Q_OBJECT

public:
	Client();

private Q_SLOTS:
	void ClientTests();
};

Client::Client()
{
}

void Client::ClientTests()
{

}

QTEST_APPLESS_MAIN(Client)

#include "tst_Client.moc"
