#ifndef PAYMENTANDROID_H
#define PAYMENTANDROID_H

#include <QObject>
#include <QtAndroidExtras>
#include <QDebug>
#include <QQmlApplicationEngine>

#define NATIVE_CODE_PATH            QString("ca/riftekit/photofly/")
#define NATIVE_CODE_CLASSNAME       QString("MyPayment")

#define PAYMENT_CLASS_NAME          NATIVE_CODE_PATH + NATIVE_CODE_CLASSNAME
#define PAYMENT_CLASS_NAME_C_STR    (PAYMENT_CLASS_NAME).toStdString().c_str()

class PaymentAndroid : public QObject
{
    Q_OBJECT
public:

    explicit PaymentAndroid(QObject *parent = 0);
    ~PaymentAndroid();

    void init();

    void callPaymentRequest();

signals:

public slots:

protected:
    PaymentAndroid(const PaymentAndroid&);                 // Prevent copy-construction
    PaymentAndroid& operator=(const PaymentAndroid&);      // Prevent assignment

private:
    QAndroidJniObject m_class;


};

#endif // PAYMENTANDROID_H
