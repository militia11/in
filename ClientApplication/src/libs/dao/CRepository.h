#ifndef CREPOSITORY_H
#define CREPOSITORY_H

#include <QStringList>

/**
 * @brief The CRepository class represents access to photos
 *        stored in mobile application
 *
 * This class is client application repository. Store images paths
 *
 */
class CRepository {
 public:
  /**
   * @brief CRepository constructor
   */
  CRepository();

  /**
   * @brief CRepository destructor
   */
  virtual ~CRepository();

  /**
   * @brief PopulateRepository add photos from mobile device to
   *        repository
   */
  void PopulateRepository();

  QStringList GetImagesPaths();
  QStringList GetImagesNames();

  /**
   * @brief Get image path
   *
   * @param aNumber Number
   * @return Image path
   */
  QString GetImagePath(int aNumber);

 private:
  /**
   * @brief mImages Container of images path from mobile device
   */
  QStringList mImagesPaths;

  /**
   * @brief mImages Container of images names from mobile device
   */
  QStringList mImagesNames;
};

#endif // CREPOSITORY_H
