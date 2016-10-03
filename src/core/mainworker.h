#ifndef MAINWORKER_H
#define MAINWORKER_H

#include <QObject>
#include <QDebug>
#ifdef __ANDROID__
//#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include <QtAndroid>
#include "imagepickerandroid.h"
#include "paymentandroid.h"
#endif

#include "behaviours/iimagegalleryprovider.h"
#include "models/registrationformdata.h"
#include "photo_service/serviceprovider.h"

using namespace PhotoFlyBehaviours;
using namespace PhotoFlyModels;

class MainWorker : public QObject
{
    Q_OBJECT
public:
    MainWorker(QObject *parent = 0);
//    MainWorker(qreal ratio, qreal ratioFont, QObject *parent = 0);

    Q_INVOKABLE void selectImageFromGallery();

    Q_INVOKABLE void openCamera();

    Q_INVOKABLE void testFunc(RegistrationFormData* data);

    void Init();

signals:
    void setMessage(QString message);

public slots:

private slots:
//    void onImageSelected(QString imagePath);
    void onImagesSelected(QStringList imagePaths);

private:
    IImageGalleryProvider *m_imPicker;
//    ImagePickerAndroid m_imPicker;



};

#endif // MAINWORKER_H
