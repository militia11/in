#include "CReceiver.h"

#include <ctype.h> // isdigit function

#include <stdexcept>
#include <stdio.h> // convert array to int function
#include <QDebug>
#include <QFile>

#include "src/libs/dao/CRepository.h"
#include "tests/auto/UnitTests/testlibs/QTcpSocketMock.h"

extern CRepository gRepository;

CReceiver::CReceiver() :
		mSocket(nullptr),
		mReceiveBuffer(nullptr),
		mDataSize(nullptr),
    mReceiveDataMode(Mode_Receive_File_Data),
    mMessageSize(0),
    mReceiveByteCount(0) {
}

CReceiver::~CReceiver() {
    Disconnected();
}

void CReceiver::Connect(QTcpSocket *aSocket) {
		if (aSocket) {
				const char *vMessage {
						"Klient połączony. Nasłuchiwanie serwera wyłączone"
				};

        QByteArray b("12");
        qDebug() << CalculateFileDataChecksum(b);
				emit MessageStatus(vMessage, 2200);

        mSocket = aSocket;
				mDataSize = new int32_t {0};
				mReceiveBuffer = new QByteArray();

        ConnectSocketSignals();

		} else {
				const char *vMessage {
						"Nie można połączyć"
				};
        emit MessageStatus(vMessage, 2200);
				throw  std::runtime_error("Nie można połączyć");
		}
}

QTcpSocket *CReceiver::GetSocket() const {
    return mSocket;
}

void CReceiver::NewData() {
		while (mSocket->bytesAvailable() > 0) {
				QByteArray vData {mSocket->readAll()};
        mReceiveBuffer->append(vData);

				for (auto i = 0; i < vData.length(); i++) {
						char vTargetSign {vData[i]};

						switch (vTargetSign) {
								case '>': {  // Begin send message checksum
										char vNextChar {vData[i + 1]};

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

void CReceiver::RouteData(char aData) {
    switch (mReceiveDataMode) {

        case Mode_Receive_File_Data : {
            ServeReceivedFileData();
            break;
        }

        case Mode_Receive_File_Checksum: {
            mMessageFileChecksum[mReceiveByteCount] = aData;
            mReceiveByteCount++;

            // Prevent buffer overflow
            if (mReceiveByteCount >= 1024) {
                mReceiveByteCount = 0;
            }

            if (aData == '<') {       // End of send message checksum
                mReceiveDataMode = Mode_Receive_File_Data;
                mMessageSize = mReceiveByteCount;
                mReceiveBuffer->clear();
                mReceiveByteCount = 0;

                try {
										ServeReceivedMessage();
								} catch (std::runtime_error vException) {
										MessageFormatException(vException.what());
                }
            }

            break;
        }

        default:
            break;
    }
}

void CReceiver::ServeReceivedMessage() {
    if (!HasMessageCorrectFormat(mMessageFileChecksum)) {
				throw std::runtime_error("Nieprawidłowy format wiadomości");
    }

		int vChecksum {ConvertMessageArrayToInt()};
    emit ReadData(mMessageFileChecksum);///@todo usunac

    delete mDataSize;
    mDataSize         = new int32_t {0};
    mMessageSize      = 0;
    mReceiveByteCount = 0;
    mReceiveBuffer->clear();

		CChecksumList *vChecksumList {gRepository.GetChecksumList()};
		bool vIsChecksumInServer {vChecksumList->CheckFileChecksum(vChecksum)};

		if (!vIsChecksumInServer) {
				const char *vMessage {
						"SEND"
				};
				ResponeToClient(vMessage);
        //        i klient zapamietuje co wysylal jaka sume wiec ten plik wysyla
        //        alternatywa:
        //        QString vClientMessage = PrepareSendingToClientMessage(vChecksum);
        //        ResponeToClient(vClientMessage);
    }
}

bool CReceiver::HasMessageCorrectFormat(char *aMessage) {
		bool vCorrect {true};
		int vChecksumLength {mMessageSize - 3}; // Minus 3 bytes char '>', '>' and '<'

    if (aMessage[0] != '>' || aMessage[1] != '>') {  // Begin message
				vCorrect = false;
		} else if ((aMessage[mMessageSize - 1] != ('<'))) {  // End message
				vCorrect = false;

		} else {
				for (auto i = 2; i < vChecksumLength + 2; ++i) {  // Checksum
            if (!isxdigit(aMessage[i])) {
								vCorrect = false;

                return vCorrect;
            }
        }
    }

    return vCorrect;
}

void CReceiver::ServeReceivedFileData() {
    int32_t vCurrentSize {*mDataSize};

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
						if (vCurrentSize > 4 /*punk*/) {
								QByteArray vData {mReceiveBuffer->left(vCurrentSize)};
								u_int16_t vChecksum {CalculateFileDataChecksum(vData)};
								CStorePhotoTransaction StoreTransaction(vData, vData.size(), vChecksum);
								StoreTransaction.Execute();
                emit ReadData(vData);

                //pokazowa wersja pokazaniem obrazu z bazy:
								//CRetrievePhotoTransaction vRetrieveTransaction(175);
								//vRetrieveTransaction.Execute();
								//QByteArray vRetrieveData {vRetrieveTransaction.GetData()};
								/// pokaze sie obraz i napis Pobrano lub Zarchiwizowano
								//emit ReadData(vRetrieveData);///@todo odznaczyc kom na koniec sprawdzic co i jak
						}

            mReceiveBuffer->remove(0, vCurrentSize);

            vCurrentSize  = 0;
            *mDataSize    = vCurrentSize;
        }
    }
}

uint16_t CReceiver::CalculateFileDataChecksum(QByteArray aData) {
    uint16_t vSum {};

		for (auto i = 0; i < aData.length(); ++i) {
        vSum += aData[i];
    }

    return vSum;
}

int32_t CReceiver::ByteArrayToInt(QByteArray aData) {
    int32_t vResult {};
    QDataStream vData(&aData, QIODevice::ReadWrite);
    vData >> vResult;

    return vResult;
}

void CReceiver::ConnectSocketSignals() {
    QObject::connect(mSocket, SIGNAL(disconnected()), this,
                     SLOT(Disconnected()), Qt::DirectConnection);

    QObject::connect(mSocket, SIGNAL(readyRead()), this,
                     SLOT(NewData()), Qt::DirectConnection);
}

void CReceiver::Disconnected() {
		const char *vMessage {
				"Rozłączono"
		};

    emit MessageStatus(vMessage, 2200);
    emit Disconnect();

    mSocket->deleteLater();

    delete mReceiveBuffer;
    mReceiveBuffer = nullptr;

    delete mDataSize;
		mDataSize = nullptr;
}

int CReceiver::ConvertMessageArrayToInt() {
    // wersja 1:
    QString vNumberAsString;

		for (auto i = 0; i < mMessageSize; i++) {
        if (isdigit(mMessageFileChecksum[i])) {
            vNumberAsString.append(mMessageFileChecksum[i]);
        }
    }

    return vNumberAsString.toInt();
    // wersja alternatywna:
    //    std::string vStringFromArray(mMessageClntFileChecksum);
    //    std::string vNumAsString = vStringFromArray.substr(2, mMessageSize-4);
    //    int vNum = QString::fromStdString(vNumAsString).toInt();
}

void CReceiver::ResponeToClient(const char *aMessage) {
		mSocket->write(aMessage);
}

void CReceiver::MessageFormatException(const char *aException) {
    qDebug() << "Message Format Exception: " + QString::fromStdString(aException);
    MessageStatus(aException, 2200);
}
