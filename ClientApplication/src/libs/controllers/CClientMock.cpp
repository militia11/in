#include "CClientMock.h"

#include <QImage>

const QString CClientMock::GetLog() const {
		return mLog;
}

void CClientMock::ReadData() {
		mLog += "->ReadData";
}

bool CClientMock::ConnectToHost(QString aHost) {
		mLog += "->ConnectToHost(" + aHost + ")";
		return true;
}

QByteArray CClientMock::ConvertImageToByteArray(const QImage &aImage) {
		mLog += "->ConvertImageToByteArray" + QString::number(aImage.isNull()) + ")";
		return QByteArray("");
}

QByteArray CClientMock::PrepareMessageData(int16_t aChecksum) {
		mLog += "->PrepareMessageData" + QString::number(aChecksum) + ")";
		return QByteArray("");
}

bool CClientMock::WriteData(QByteArray aData) {
		mLog += "->WriteData" + aData + ")";;
		return true;
}

bool CClientMock::WriteMessage(QByteArray aData) {
		mLog += "->WriteMessage" + aData + ")";
		return true;
}

int16_t CClientMock::CalculateFileDataChecksum(QByteArray aData) {
		mLog += "->CalculateFileDataChecksum" + aData + ")";
		return 0;
}

QByteArray CClientMock::IntToArray(int32_t aSource) {
		mLog += "->IntToArray" + QString::number(aSource) + ")";
		return QByteArray("");
}

void CClientMock::UpdateServerPhotos() {
		mLog += "->UpdateServerPhotos";
}
