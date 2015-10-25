#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include <QImage>
#include <QList>

/// jesli nie bedzie bazy zmienic nazwe klasy na cos zwiazane z pobieraniem sum zdjec z telefonu! i danych?

/**
 * @brief The CRepository class represents access to photos
 *              stored in mobile application.
 *
 * This class is client application repository.
 *
 * ///@todo nie wiadomo czy tak bedzie?
 * ///It's initialize communication to database.
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

    QList<QImage> GetImages();

  private:
    /**
     * @brief mImages container of images from mobile device.
     */
    QList<QImage> mImages;
};

#endif // CREPOSITORY_H
