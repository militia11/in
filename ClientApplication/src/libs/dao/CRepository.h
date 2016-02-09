#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include <QStringList>

/**
 * @brief The CRepository class represents access to photos
 *        stored in mobile application.
 *
 * This class is client application repository. Store images paths.
 *
 */
class CRepository {
  public:
    /**
     * @brief CRepository constructor.
     */
    CRepository();

    /**
     * @brief CRepository destructor.
     */
    virtual ~CRepository();

    /**
     * @brief PopulateRepository add photos from mobile device to
     *        repository.
     */
    void PopulateRepository();

    QStringList GetImages();

  private:
    /**
     * @brief mImages container of images path from mobile device.
     */
    QStringList mImagesPaths;
};

#endif // CREPOSITORY_H
