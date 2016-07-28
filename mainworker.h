#ifndef MAINWORKER_H
#define MAINWORKER_H

#include <QObject>
#include <QDebug>
#ifdef __ANDROID__
//#include <QtAndroidExtras>
#include <QAndroidJniObject>
#include <QtAndroid>
#endif

#include <imagepickerandroid.h>
#include <registrationformdata.h>

class MainWorker : public QObject
{
    Q_OBJECT
public:
    MainWorker(QObject *parent = 0);
    MainWorker(qreal ratio, qreal ratioFont, QObject *parent = 0);

    Q_INVOKABLE void buttonClicked();

    Q_INVOKABLE void testFunc(RegistrationFormData* data);

    Q_INVOKABLE qreal ratio() const;
    Q_INVOKABLE qreal ratioFont() const;

    static qreal Ratio;
    static qreal RatioFont;
signals:
    void setMessage(QString message);

public slots:

private slots:
    void onImageSelected(QString imagePath);

private:
    ImagePickerAndroid m_imPicker;



};

#endif // MAINWORKER_H
