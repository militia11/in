#include "CReceiver.h"

#include <ctype.h> // isdigit function

#include <stdexcept>
#include <stdio.h> // convert array to int function
#include <QDebug>
#include <QFile>
#include <QDataStream>
#include "src/libs/dao/CRepository.h"

extern CRepository gRepository;

CReceiver::CReceiver() :
  mSocket(nullptr),
  mReceiveBuffer(nullptr),
  mDataSize(nullptr),
  mReceiveDataMode(Mode_Receive_File_Data),
  mMessageSize(0),
  mReceiveByteCount(0) {}

CReceiver::~CReceiver() {
  Disconnected();
}

void CReceiver::CalculateProgress() {
  int vProgress = 0;

  if ((*mDataSize != 0 && mReceiveBuffer->size() != 0)) {
	double vs = (*mDataSize) / mReceiveBuffer->size();
	vProgress = 100.0 / vs;
  }

  emit ReceiveDataProgressChanged(int(vProgress));
}

bool CReceiver::HasDataReceivedCompletely() {
  return *mDataSize > 0 && mReceiveBuffer->size() >= *mDataSize;
}

bool CReceiver::HasSizeOfDataReceivedCompletely() {
  return *mDataSize == 0 && mReceiveBuffer->size() >= 4;
}

void CReceiver::RemoveDataFromBuffer(int32_t aCurrentSize) {
  mReceiveBuffer->remove(0, aCurrentSize);
}

void CReceiver::Connect(QTcpSocket *aSocket) {
  (aSocket) ? ExecuteConnectActions(aSocket) : EmitNotConnectedStatus();
}

void CReceiver::RemoveSizeFromBuffer() {
  mReceiveBuffer->remove(0, 4);
}

void CReceiver::SaveAndSetCurrentSize(int32_t *aCurrentSize) {
  QByteArray vData = mReceiveBuffer->left(4);
  *aCurrentSize = ByteArrayToInt(vData);

  *mDataSize = *aCurrentSize;
}

void CReceiver::StoreData(int32_t aCurrentSize) {
  QByteArray vData {mReceiveBuffer->left(aCurrentSize)};
  uint32_t vChecksum {CalculateFileDataChecksum(vData)};
  CStorePhotoTransaction StoreTransaction(
	vData,
	vData.size(),
	vChecksum);
  StoreTransaction.Execute();
  emit ReadData(vData);
}

bool CReceiver::NotPunk(int32_t aSize) {
  return aSize > 4;
}

bool CReceiver::CanReceive() {
  return HasSizeOfDataReceivedCompletely() ||
		 HasDataReceivedCompletely();
}

bool CReceiver::IsBytesAvailable() {
  return mSocket->bytesAvailable() > 0;
}

void CReceiver::CleanSizesFields(int *aCurrentSize) {
  *aCurrentSize = 0;
  *mDataSize    = *aCurrentSize;
}

void CReceiver::TryServeReceivedMessage() {
  try {
	ServeReceivedMessage();
  } catch (std::runtime_error vException) {
	MessageFormatException(vException.what());
  }
}

void CReceiver::PrepareBuffersToReceiveDataMode() {
  mReceiveDataMode = Mode_Receive_File_Data;
  mMessageSize = mReceiveByteCount;
  delete mReceiveBuffer;//->clear();
  mReceiveBuffer = new QByteArray();
  mReceiveByteCount = 0;
}

void CReceiver::CleanBuffers() {
  *mDataSize        = 0;
  mMessageSize      = 0;
  mReceiveByteCount = 0;
  mReceiveBuffer->clear();
  delete mReceiveBuffer;
  mReceiveBuffer = new QByteArray();
}

void CReceiver::VerifyMessageFormat() {
  if (!HasMessageCorrectFormat(mMessageFileChecksum)) {
	throw std::runtime_error("Nieprawidłowy format wiadomości");
  }
}

void CReceiver::AppendToChecksum(char aData) {
  mMessageFileChecksum[mReceiveByteCount] = aData;
  mReceiveByteCount++;
}

bool CReceiver::IsEndMessageChar(char aData) {
  return aData == '<';
}

void CReceiver::PreventBufferOverflow() {
  if (mReceiveByteCount >= 1024) {
	mReceiveByteCount = 0;
  }
}

void CReceiver::VerifyBeginMessage(QByteArray aData, int aPosition) {
  if (IsBeginChar(aData[aPosition]) && IsBeginChar(aData[aPosition + 1]))  {
	SetChecksumMode();
  }
}

void CReceiver::SetChecksumMode() {
  mReceiveDataMode = Mode_Receive_File_Checksum;
  mReceiveByteCount = 0;
}

bool CReceiver::IsBeginChar(char aChar) {
  return aChar == '>';
}

void CReceiver::RouteData(char aData) {
  switch (mReceiveDataMode) {
	case Mode_Receive_File_Data : {
	  ServeReceivedFileData();
	  break;
	}

	case Mode_Receive_File_Checksum: {
	  AppendToChecksum(aData);
	  PreventBufferOverflow();

	  if (IsEndMessageChar(aData)) {
		PrepareBuffersToReceiveDataMode();
		TryServeReceivedMessage();
	  }

	  break;
	}

	default:
	  break;
  }
}

void CReceiver::ServeReceivedMessage() {
  VerifyMessageFormat();
  qDebug() << mMessageFileChecksum;///@todo usunac
  CleanBuffers();

  if (NotChecksumInServer()) {
	qDebug() << "nottttttttttt available\n";

	const char *vMessage = "NOT AVAILABLE";
	ResponeToClient(vMessage);  //NOTE:1

  } else {
	qDebug() << "in sssssssssserver\n";

	const char *vMessage = "IN SERVER";
	ResponeToClient(vMessage);  //NOTE:1
  }
}

bool CReceiver::NotChecksumInServer() {
  int vChecksum {ConvertMessageArrayToInt()};
  CChecksumList *vChecksumList {gRepository.GetChecksumList()};

  return !(vChecksumList->CheckFileChecksum(vChecksum));
}

bool CReceiver::HasMessageCorrectFormat(char *aMessage) {
  bool vCorrect {true};
  int vChecksumLength {mMessageSize - 3}; // Minus 3 bytes: two chars '>' and one '<'

  if (aMessage[0] != '>' || aMessage[1] != '>') {  // Begin message
	vCorrect = false;
  } else if ((aMessage[mMessageSize - 1] != ('<'))) {  // End message
	vCorrect = false;
  } else {
	for (auto i = 2; i < vChecksumLength + 2; ++i) {  // Checksum
	  if (!isxdigit(aMessage[i])) {
		vCorrect = false;
		break;
	  }
	}
  }

  return vCorrect;
}

void CReceiver::ServeReceivedFileData() {
  while (CanReceive()) {
	int32_t vCurrentSize = *mDataSize;

	if (HasSizeOfDataReceivedCompletely()) {
	  SaveAndSetCurrentSize(&vCurrentSize);
	  RemoveSizeFromBuffer();
	}

	CalculateProgress();

	if (HasDataReceivedCompletely()) {
	  if (NotPunk(vCurrentSize)) {
		qDebug() << "store data\n";
		StoreData(vCurrentSize);
	  }

	  RemoveDataFromBuffer(vCurrentSize);
	  CleanSizesFields(&vCurrentSize);
	}
  }
}

uint32_t CReceiver::CalculateFileDataChecksum(QByteArray aData) {
  uint32_t vChecksum {};

  for (auto i = 0; i < aData.length(); ++i) {
	vChecksum += aData[i];
  }

  return vChecksum;
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
  const char *vMessage = "Rozłączono";

  emit MessageStatus(vMessage, 2200);
  emit Disconnect();

  mSocket->deleteLater();

  delete mReceiveBuffer;
  mReceiveBuffer = nullptr;

  delete mDataSize;
  mDataSize = nullptr;
}

int CReceiver::ConvertMessageArrayToInt() {
  QString vNumberAsString;

  for (auto i = 0; i < mMessageSize; i++) {
	if (isdigit(mMessageFileChecksum[i])) {
	  vNumberAsString.append(mMessageFileChecksum[i]);
	}
  }

  return vNumberAsString.toInt();
}

void CReceiver::ResponeToClient(const char *aMessage) {
  mSocket->write(aMessage);
}

void CReceiver::MessageFormatException(const char *aException) {
  qDebug() << "Message Format Exception: " + QString::fromStdString(aException);
  MessageStatus(aException, 2200);
}

void CReceiver::ExecuteConnectActions(QTcpSocket *aSocket) {
  const char *vMessage {
	"Klient połączony. Nasłuchiwanie serwera wyłączone"
  };
  qDebug() << "Klient połączony. Nasłuchiwanie serwera wyłączone";

  QByteArray b("12");
  qDebug() << CalculateFileDataChecksum(b);
  emit MessageStatus(vMessage, 2200);

  mSocket = aSocket;
  mDataSize = new int32_t {0};
  mReceiveBuffer = new QByteArray();

  ConnectSocketSignals();
}

void CReceiver::EmitNotConnectedStatus() {
  const char *vMessage {
	"Nie można połączyć"
  };
  qDebug() << "Nie można połączyć";

  emit MessageStatus(vMessage, 2200);
  throw  std::runtime_error("Nie można połączyć");
}

QTcpSocket *CReceiver::GetSocket() const {
  return mSocket;
}

void CReceiver::NewData() {
  while (IsBytesAvailable()) {
	QByteArray vData {mSocket->readAll()};
	mReceiveBuffer->append(vData);

	for (auto i = 0; i < vData.length(); i++) {

	  VerifyBeginMessage(vData, i);
	  RouteData(vData[i]);
	}
  }
}

//NOTE:1
//  i klient zapamietuje co wysylal jaka sume wiec ten plik wysyla
//  alternatywa:    QString vClientMessage = PrepareSendingToClientMessage(vChecksum);ResponeToClient(vClientMessage);

//NOTE:2
//pokazowa wersja pokazaniem obrazu z bazy:
//CRetrievePhotoTransaction vRetrieveTransaction(175);
//vRetrieveTransaction.Execute();
//QByteArray vRetrieveData {vRetrieveTransaction.GetData()};
// pokaze sie obraz i napis Pobrano lub Zarchiwizowano
//emit ReadData(vRetrieveData);
