#include "CRepository.h"

CRepository gRepository;

CRepository::CRepository() {
}

CRepository::~CRepository() {
}

void CRepository::PopulateRepository() {
    // zapełnienie listy zdjęć zdjęciami z telefonu
    //for()
    //mImages.append();
}

QList<QImage> CRepository::GetImages() {
    return mImages;
}
