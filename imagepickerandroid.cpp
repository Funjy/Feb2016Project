#include "imagepickerandroid.h"

static const int ACTIVITY_REQUEST_CODE = 1;

ImagePickerAndroid::ImagePickerAndroid(QObject *parent) : QObject(parent)
{

}

void ImagePickerAndroid::openGallery()
{
    QAndroidJniObject res = QAndroidJniObject::callStaticObjectMethod(
                "org/riftekit/example/myandroidapp/MyJavaClass",
                "getIntent",
                "()Landroid/content/Intent;");

    QtAndroid::startActivity(res.object<jobject>(), ACTIVITY_REQUEST_CODE, this);
}

void ImagePickerAndroid::handleActivityResult(int receiverRequestCode, int resultCode, const QAndroidJniObject &data)
{
    jint RESULT_OK = QAndroidJniObject::getStaticField<jint>("android/app/Activity", "RESULT_OK");
    if(resultCode != RESULT_OK)
    {
        emit imageSelected("Canceled");
        return;
    }
    QAndroidJniObject res = QAndroidJniObject::callStaticObjectMethod(
                "org/riftekit/example/myandroidapp/MyJavaClass",
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
    QAndroidJniObject arrayElement = jniEnv->GetObjectArrayElement(res.object<jobjectArray>(), splitArrayLength - 1 );

    QString retStr = arrayElement.toString();
    emit imageSelected("Count: " + QString::number(splitArrayLength)+ ".\nLast: " + retStr);
}

