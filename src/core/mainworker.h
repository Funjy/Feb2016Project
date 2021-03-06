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
#include "controllers/registrationformcontroller.h"
#include "controllers/mainformcontroller.h"

#include "core/global_defs.h"

using namespace PhotoFlyBehaviours;
using namespace PhotoFlyModels;
using namespace PhotoFlyControllers;

class MainWorker : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWorker)

//    Q_PROPERTY(RegistrationFormController* regFormController MEMBER m_regFormController NOTIFY regFormControllerChanged)
//    Q_PROPERTY(RegistrationFormController* regFormController MEMBER m_regFormController CONSTANT)

    Q_PROPERTY(MainFormController* mainFormController MEMBER m_mainFormController CONSTANT)

    Q_PROPERTY(bool isRegistered READ isRegistered NOTIFY isRegisteredChanged)

public:
    MainWorker(QObject *parent = 0);

    Q_INVOKABLE void testFunc(RegistrationFormData* data);

    void Init();

    bool isRegistered() const;

signals:
    void isRegisteredChanged();
//    void regFormControllerChanged();

public slots:
    void updateUserInfo();

private slots:
//    void onImageSelected(QString imagePath);
    void onImagesSelected(QStringList imagePaths);

private:
//    IImageGalleryProvider   *m_imPicker;
    MainFormController      *m_mainFormController;

    RegistrationFormData    *m_userInfo;

//    RegistrationFormController *m_regFormController;
//    ImagePickerAndroid m_imPicker;



};

#endif // MAINWORKER_H
