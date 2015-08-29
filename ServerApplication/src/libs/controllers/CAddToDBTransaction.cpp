#include "CAddToDBTransaction.h"

#include <litesql.hpp>
//#include "litesql/field.hpp"
#include "libs/dao/androidphotosdatabase.hpp"

#include "libs/dao/CRepository.h"

#include <QImageWriter>
#include <QImageReader>
#include <QImage>
#include <QDebug>
using server::AndroidPhotosDatabase;
using server::Photo;
using namespace litesql;
extern CRepository gRepository;

CAddToDBTransaction::CAddToDBTransaction(QByteArray aData, int aChecksum) :
		mData(aData),
		mChecksum(aChecksum) {
}

void CAddToDBTransaction::Execute() {

		QImage vImage = QImage ("/home/mmichniewski/pies.jpg", "JPG"); // from data load
		QBuffer vBuffer;

		QImageWriter vWriter(&vBuffer, "JPG");
		vWriter.write(vImage);
		//qDebug() << vImage.size() << "im1";

		QByteArray vData = vBuffer.data();
		qDebug() << vData.size() << "tab";

		server::AndroidPhotosDatabase *mDatabase  = gRepository.GetDatabase();
		Photo vPhoto(*mDatabase);
		vPhoto.checksum = mChecksum; //mChecksum

		const char * vDataChar = mData.constData();

		//const char * vDataChar = vData.constData();
		Blob vDataIn(vDataChar,4);
		vPhoto.data = vDataIn;
		vPhoto.update();
		//	model->odswiez();

		//retrieve przeniesc pozniej:
//		QBuffer buffer(&vData);
//		buffer.open( QIODevice::ReadOnly );
//		QImageReader reader(&buffer, "JPG");
//		QImage image = reader.read();
		//qDebug() << image.size() << "im2";
}

//	QSqlQuery qry;
//	int id;
//	qry.prepare( "SELECT COUNT(*) FROM images" );
//	qry.exec();
//	qry.next();
//	id = qry.value(0).toInt() + 1;
//	qry.prepare( "INSERT INTO images (id, data) VALUES (:id, :data)" );
//	qry.bindValue( ":id", id );
//	qry.bindValue( ":data", buffer.data() );
//	qry.exec();
//	foreach( QString tag, tags )
//	addTag( id, tag );


//		try {

//				std::string b = "768";
//				vPhoto.data = b;//stdString ;

//		} catch (const char *msg) {
//				qDebug() << msg << "exc";
//		}
