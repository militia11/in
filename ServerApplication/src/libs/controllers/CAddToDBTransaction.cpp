#include "CAddToDBTransaction.h"
#include "libs/dao/CRepository.h"

#include <QBuffer>
#include <QImageWriter>
#include <QImage>

using server::AndroidPhotosDatabase;
using server::Photo;

extern CRepository gRepository;

CAddToDBTransaction::CAddToDBTransaction() :
		mChecksum(0) {
}

void CAddToDBTransaction::Execute() {

		QImage vImage; // from data load
		QBuffer vBuffer;
		QImageWriter vWriter(&vBuffer, "JPG");
		vWriter.write(vImage);

		server::AndroidPhotosDatabase *mDatabase  = gRepository.GetDatabase();

		Photo vPhoto(*mDatabase);
		vPhoto.checksum = 3; //mChecksum
		vPhoto.update();

		//	model->odswiez();

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
}
