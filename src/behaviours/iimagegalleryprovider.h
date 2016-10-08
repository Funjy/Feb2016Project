#ifndef IIMAGEGALLERYPROVIDER_H
#define IIMAGEGALLERYPROVIDER_H

#include <QObject>

namespace PhotoFlyBehaviours{

class IImageGalleryProvider : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(IImageGalleryProvider)

public:
    virtual void openGallery() = 0;
    Q_INVOKABLE virtual void openCamera() = 0;

protected:
    explicit IImageGalleryProvider(QObject * parent = nullptr) : QObject(parent) {}

signals:

    void imageSelected(QString imagePath);
    void error(QString error);
    void imagesSelected(QStringList imagePaths);

};

}

Q_DECLARE_METATYPE(PhotoFlyBehaviours::IImageGalleryProvider*)

#endif // IIMAGEGALLERYPROVIDER_H
