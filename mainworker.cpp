#include "mainworker.h"

MainWorker::MainWorker(QObject *parent) : QObject(parent){
    connect(&m_imPicker, &ImagePickerAndroid::imageSelected, this, &MainWorker::onImageSelected);
    emit setMessage("Ready");
}

qreal MainWorker::Ratio;
qreal MainWorker::RatioFont;

MainWorker::MainWorker(qreal ratio, qreal ratioFont, QObject *parent)
{
    Ratio = ratio;
    RatioFont = ratioFont;
    qDebug() << QString("Ratio: %1\tRatio Font: %2").arg(Ratio, 0, 'f', 1).arg(RatioFont, 0, 'f', 1);
    int i = 0;
}

void MainWorker::buttonClicked()
{
    emit setMessage("Open clicked");

    m_imPicker.openGallery();

}

void MainWorker::testFunc(RegistrationFormData* data)
{
}

qreal MainWorker::ratio() const {return Ratio;}

qreal MainWorker::ratioFont() const {return RatioFont;}

void MainWorker::onImageSelected(QString imagePath)
{
    emit setMessage(imagePath);
}
