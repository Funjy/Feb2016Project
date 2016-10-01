#include "imagepickerandroid.h"

static const int ACTIVITY_REQUEST_CODE = 1;
static const int ACTIVITY_REQUEST_CODE_OPEN_CAMERA = 2;

ImagePickerAndroid::ImagePickerAndroid(QObject *parent) : IImageGalleryProvider(parent)
{

}

void ImagePickerAndroid::openGallery()
{
    QString className = NATIVE_CODE_PATH + NATIVE_CODE_CLASSNAME;
    QAndroidJniObject res = QAndroidJniObject::callStaticObjectMethod(
                className.toStdString().c_str(),
                "getIntent",
                "()Landroid/content/Intent;");

    if(!res.isValid()){
        qDebug() << "Wrong intent";
        return;
    }

    QtAndroid::startActivity(res.object<jobject>(), ACTIVITY_REQUEST_CODE, this);
}

void ImagePickerAndroid::openCamera()
{
    QString className = NATIVE_CODE_PATH + NATIVE_CODE_CLASSNAME;
    QAndroidJniObject res = QAndroidJniObject::callStaticObjectMethod(
                className.toStdString().c_str(),
                "getOpenCameraIntent",
                "()Landroid/content/Intent;");

    if(!res.isValid()){
        qDebug() << "Wrong intent";
        return;
    }

    QtAndroid::startActivity(res.object<jobject>(), ACTIVITY_REQUEST_CODE_OPEN_CAMERA);
}

void ImagePickerAndroid::handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject &data)
{
    qDebug() << "req code: " << receiverRequestCode;
    Q_UNUSED(receiverRequestCode)
    jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
    if(resultCode != RESULT_OK)
    {
        emit imageSelected("Canceled");
        return;
    }
    QString className = NATIVE_CODE_PATH + NATIVE_CODE_CLASSNAME;
    QAndroidJniObject res = QAndroidJniObject::callStaticObjectMethod(
                className.toStdString().c_str(),
                "handleResult",
                "(Landroid/content/Intent;Landroid/app/Activity;)[Ljava/lang/String;",
                data.object<jobject>(),
                QtAndroid::androidActivity().object<jobject>());

    bool v = res.isValid();

    if(!v){
        emit imageSelected("Error");
        return;
    }
    QAndroidJniEnvironment jniEnv;
    int splitArrayLength = jniEnv->GetArrayLength(res.object<jarray>());

    QStringList ret;
    for(int i = 0; i < splitArrayLength; i++){
        QAndroidJniObject arrayElement = jniEnv->GetObjectArrayElement(res.object<jobjectArray>(), i );
//        QString retStr = arrayElement.toString();
        if(arrayElement.isValid())
            ret << arrayElement.toString();

    }

    emit imagesSelected(ret);


//    emit imageSelected("Count: " + QString::number(splitArrayLength)+ ".\nLast: " + retStr);
}

