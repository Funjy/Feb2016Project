#include "paymentandroid.h"

static const int ACTIVITY_REQUEST_CODE_PAYMENT = 1;

void PaymentAndroid::init()
{
    QAndroidJniObject payClass(PAYMENT_CLASS_NAME_C_STR);
    m_class = QAndroidJniObject(PAYMENT_CLASS_NAME_C_STR);
    if(!m_class.isValid()){
        qCritical() << "Can't find class : " << PAYMENT_CLASS_NAME;
    }

//    QAndroidJniObject activity = QAndroidJniObject::callStaticObjectMethod("org/qtproject/qt5/android/QtNative", "activity", "()Landroid/app/Activity;");

//    QAndroidJniObject activity = QtAndroid::androidActivity();

//    if(!activity.isValid())
//        qCritical() << "Activity is not valid!";

//    QAndroidJniObject fragment = m_class.callObjectMethod(
//                "createBraintreeFragment",
//                "(Landroid/app/Activity;)Lcom/braintreepayments/api/BraintreeFragment;",
//                activity.object<jobject>());

//    if(!fragment.isValid())
//        qCritical() << "Fragment is not valid!";

//    QAndroidJniObject result = m_class.getObjectField<jstring>("fragmentResult");
//    if(result.isValid())
//        qDebug() << "fragment result: " << result.toString();
//    else
//        qCritical() << "Result is not valid!";

//    QAndroidJniObject sessionId = fragment.callObjectMethod<jstring>("getSessionId");
//    qDebug() << "session id: " << sessionId.toString();
}

void PaymentAndroid::callPaymentRequest()
{

    QAndroidJniObject prIntent = m_class.callObjectMethod("paymentRequest",
                       "(Landroid/content/Context;)Landroid/content/Intent;",
                       QtAndroid::androidActivity().object<jobject>());

    if(!prIntent.isValid()){
        qCritical() << "Wrong intent";
        return;
    }

    QtAndroid::startActivity(prIntent.object<jobject>(), ACTIVITY_REQUEST_CODE_PAYMENT);
//    QtAndroid::androidActivity().callObjectMethod("startActivity","(Landroid/content/Intent;)V", prIntent.object<jobject>());

}

PaymentAndroid::PaymentAndroid(QObject *parent) : QObject(parent)
{


}

PaymentAndroid::~PaymentAndroid() {
}
