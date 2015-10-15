#include "CClient.h"

#include "libs/dao/CRepository.h"

#include <stdio.h> // convert array to int function
#include <ctype.h> // isdigit function
#include <QDebug>
#include <QFile>

extern CRepository gRepository;

CClient::CClient(QObject *aParent) :
    QObject(aParent),
    mSocket(NULL),
    mReceiveBuffer(NULL),
    mDataSize(NULL),
    mReceiveDataMode(Mode_Receive_File_Data),
    mMessageSize(0),
		mReceiveByteCount(0) {
}

CClient::~CClient() {
    Disconnected();
}

void CClient::Connect(QTcpSocket *aSocket) {
    if (aSocket) {
        const char *vMessage = "Klient połączony. Nasłuchiwanie serwera wyłączone";
        qDebug() << vMessage;

        emit MessageStatus(vMessage, 2200);

        mSocket = aSocket;
        mDataSize = new qint32(0);
        mReceiveBuffer = new QByteArray();

        ConnectSocketSignals();

    } else {
        const char *vMessage = "Nie można połączyć";
        qDebug() << vMessage;

        emit MessageStatus(vMessage, 2200);
        emit mSocket->error();
    }
}

QTcpSocket *CClient::GetSocket() const {
    return mSocket;
}

void CClient::NewData() {

    while (mSocket->bytesAvailable() > 0) {
        QByteArray vData = mSocket->readAll();
        mReceiveBuffer->append(vData);

        for (int i = 0; i < vData.length(); i++) {
            char vTargetSign = vData[i];

            switch (vTargetSign) {

								case '>': {					// Begin send message checksum

                    char vNextChar = vData[i + 1];

                    if (vNextChar == '>') {
												mReceiveDataMode = Mode_Receive_File_Checksum;
												mReceiveByteCount = 0;
                    }

                    break;
                }

                default:
                    break;
            }

            RouteData(vTargetSign);
        }
    }
}

void CClient::RouteData(char aData) {
    switch (mReceiveDataMode) {

        case Mode_Receive_File_Data : {
            qDebug() << "MODE_RECEIVE_FILE_DATA";
            ServeReceivedFileData();
            break;
        }

				case Mode_Receive_File_Checksum: {
            qDebug() << "MODE_RECEIVE_FILE_CHECKSUM";
						mMessageFileChecksum[mReceiveByteCount] = aData;
						mReceiveByteCount++;

						// Prevent buffer overflow
						if (mReceiveByteCount >= 1024) {
								mReceiveByteCount = 0;
            }

						if (aData == '<') {		    // End of send message checksum
                mReceiveDataMode = Mode_Receive_File_Data;
								mMessageSize = mReceiveByteCount;
                mReceiveBuffer->clear();
								mReceiveByteCount = 0;
                ServeReceivedMessage();
            }

            break;
        }

        default:
            break;
    }
}

void CClient::ServeReceivedMessage() {
		if (!HasMessageCorrectFormat(mMessageFileChecksum)) {
        const char *vMessage = "Nieprawidłowy format wiadomości";
        MessageStatus(vMessage, 2200);
        qDebug() << vMessage;

        return;
    }

		int vChecksum = ConvertMessageArrayToInt();

    CChecksumList *vChecksumList = gRepository.GetChecksumList();

		bool vIsChecksumInServer = vChecksumList->CheckFileChecksum(vChecksum);
		qDebug() << vIsChecksumInServer;

    mReceiveBuffer->clear();

		delete mDataSize;
    mDataSize  = new qint32(0);

		mMessageSize		= 0;
		mReceiveByteCount = 0;

		if (!vIsChecksumInServer) {
        QByteArray vMessage("SEND");
        ResponeToClient(vMessage);
        //				i klient zapamietuje co wysylal jaka sume wiec ten plik wysyla

        //				alternatywa:
        //        QString vClientMessage = PrepareSendingToClientMessage(vChecksum);
        //        ResponeToClient(vClientMessage);
    }
}

bool CClient::HasMessageCorrectFormat(char *aMessage) {
    bool vCorrect = true;///@todo sprawdzic ponizszy komentarz
		int vChecksumLength = mMessageSize - 3; // Minus 3 bytes char '>', '>' and '<'

		if (aMessage[0] != '>' || aMessage[1] != '>') {  // Begin message
        vCorrect =  false;
		} else if ((aMessage[mMessageSize - 1] != ('<'))) { // End message
        vCorrect = false;
    } else {
				for (int i = 2; i < vChecksumLength + 2; ++i) { // Checksum
            if (!isxdigit(aMessage[i])) {
                vCorrect = false;
                return vCorrect;
            }
        }
    }

    return vCorrect;
}

void CClient::ServeReceivedFileData() {
    int32_t vCurrentSize = *mDataSize;

		while ((vCurrentSize == 0 && mReceiveBuffer->size() >= 4) ||
            (vCurrentSize > 0 &&
             mReceiveBuffer->size() >= vCurrentSize)) {

        if (vCurrentSize == 0 &&
                mReceiveBuffer->size() >=
								4) {
						vCurrentSize = ByteArrayToInt(mReceiveBuffer->left(4));

            *mDataSize = vCurrentSize;
						mReceiveBuffer->remove(0, 4);
        }

        if (vCurrentSize > 0 && mReceiveBuffer->size() >=
                vCurrentSize) {
						if (vCurrentSize > 4/*punk*/) {
                QByteArray vData = mReceiveBuffer->left(vCurrentSize);

								u_int16_t vChecksum = CalculateFileDataChecksum(vData);

								CRetrievePhotoTransaction vRetrieveTransaction(175);
                vRetrieveTransaction.Execute();
								QByteArray vRetrieveData = vRetrieveTransaction.GetData();

								// CStorePhotoTransaction StoreTransaction(vData, vData.size(), vChecksum);
								// StoreTransaction.Execute();

								emit ReadData(vRetrieveData);///@todo odznaczyc kom na koniec sprawdzic co i jak
            }

            mReceiveBuffer->remove(0, vCurrentSize);

						vCurrentSize	= 0;
						*mDataSize		= vCurrentSize;

            //						CRetrieveFromDBTransaction vRetrieveTransaction(221);
            //						vRetrieveTransaction.Execute();
						//						QByteArray vRetrieveData =  vRetrieveTransaction.getData();

            //						const char *vMessage = "Odebrano dane : ";
            //						ResponeToClient(vMessage, vData);
        }
    }
}

uint16_t CClient::CalculateFileDataChecksum(QByteArray aData) {
		uint16_t vSum = 0;

    for (int i = 0; i < aData.length(); ++i) {
        vSum += aData[i];
    }

    return vSum;
}

int32_t CClient::ByteArrayToInt(QByteArray aData) {
    int32_t vResult;
    QDataStream vData(&aData, QIODevice::ReadWrite);
    vData >> vResult;

		return vResult;
}

void CClient::ConnectSocketSignals() {
    QObject::connect(mSocket, SIGNAL(disconnected()), this,
                     SLOT(Disconnected()), Qt::DirectConnection);

    QObject::connect(mSocket, SIGNAL(readyRead()), this,
                     SLOT(NewData()), Qt::DirectConnection);
}

void CClient::Disconnected() {
    const char *vMessage = "Rozłączono";
    qDebug() << vMessage;

    emit MessageStatus(vMessage, 2200);
    emit Disconnect();

    mSocket->deleteLater();

    delete mReceiveBuffer;
    mReceiveBuffer = 0;

    delete mDataSize;
		mDataSize = 0;
}

int CClient::ConvertMessageArrayToInt() {
    // wersja 1:

		QString vNumberAsString;

    for (int i = 0; i < mMessageSize; i++) {
				if (isdigit(mMessageFileChecksum[i])) {
						vNumberAsString.append(mMessageFileChecksum[i]);
        }
    }

		return vNumberAsString.toInt();

    // wersja alternatywna:
    //		std::string vStringFromArray(mMessageClntFileChecksum);
    //		std::string vNumAsString = vStringFromArray.substr(2, mMessageSize-4);
    //		int vNum = QString::fromStdString(vNumAsString).toInt();
}

void CClient::ResponeToClient(QByteArray aData) {
    mSocket->write(aData);
}
