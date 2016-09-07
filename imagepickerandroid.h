#ifndef IMAGEPICKERANDROID_H
#define IMAGEPICKERANDROID_H

#include <QObject>
#include <QtAndroidExtras>
#include <QDebug>

#define NATIVE_CODE_PATH            QString("ca/riftekit/photofly/")
#define NATIVE_CODE_CLASSNAME       QString("MyJavaClass")

class ImagePickerAndroid : public QObject, public QAndroidActivityResultReceiver
{
    Q_OBJECT
public:
    explicit ImagePickerAndroid(QObject *parent = 0);


    void openGallery();
    void openCamera();

    virtual void handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject & data);

signals:

    void imageSelected(QString imagePath);
    void error(QString error);
    void imagesSelected(QStringList imagePaths);

public slots:
};

#endif // IMAGEPICKERANDROID_H
