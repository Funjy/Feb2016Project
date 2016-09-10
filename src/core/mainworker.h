#ifndef MAINWORKER_H
#define MAINWORKER_H

#include <QObject>
#include <QDebug>
#ifdef __ANDROID__
//#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include <QtAndroid>
#endif

#include "imagepickerandroid.h"
#include "models/registrationformdata.h"
#include "paymentandroid.h"

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
    ImagePickerAndroid m_imPicker;



};

#endif // MAINWORKER_H
