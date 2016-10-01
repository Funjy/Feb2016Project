#ifndef IIMAGEGALLERYPROVIDER_H
#define IIMAGEGALLERYPROVIDER_H

#include <QObject>

namespace PhotoFlyBehaviours{

class IImageGalleryProvider : public QObject
{
    Q_OBJECT
public:
    virtual void openGallery() = 0;

signals:

    void imageSelected(QString imagePath);
    void error(QString error);
    void imagesSelected(QStringList imagePaths);

};

}

#endif // IIMAGEGALLERYPROVIDER_H
