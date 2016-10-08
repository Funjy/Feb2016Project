#ifndef IMAGEPICKERANDROID_H
#define IMAGEPICKERANDROID_H

#include <QObject>
#include <QtAndroidExtras>
#include <QDebug>

#include "behaviours/iimagegalleryprovider.h"

#define NATIVE_CODE_PATH            QString("ca/riftekit/photofly/")
#define NATIVE_CODE_CLASSNAME       QString("MyJavaClass")

using namespace PhotoFlyBehaviours;

class ImagePickerAndroid : public IImageGalleryProvider, protected QAndroidActivityResultReceiver
{
    Q_OBJECT
    Q_DISABLE_COPY(ImagePickerAndroid)

public:
    explicit ImagePickerAndroid(QObject *parent = 0);


    virtual void openGallery() override;
    Q_INVOKABLE virtual void openCamera() override;

protected:
    virtual void handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject & data);

//signals:
//    void imageSelected(QString imagePath);
//    void error(QString error);
//    void imagesSelected(QStringList imagePaths);

public slots:
};

#endif // IMAGEPICKERANDROID_H
