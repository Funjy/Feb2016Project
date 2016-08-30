#include "applicationsettings.h"


void ApplicationSettings::init()
{
    if( QQmlEngine::objectOwnership(this) != QQmlEngine::CppOwnership )
        QQmlEngine::setObjectOwnership(this, QQmlEngine::CppOwnership);
    if(!m_settings){
        QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
        if(!QDir(path).exists()){
            QDir().mkpath(path);
        }
        QString fullName = QString("%1/%2.conf").arg(path).arg(qApp->applicationName());
        m_settings = new QSettings(fullName, QSettings::NativeFormat,  this);
    }
    setValue(OPTION_IS_REGISTERED, false);
}

QSettings &ApplicationSettings::settings()
{
    return *m_settings;
}

void ApplicationSettings::setValue(const QString& key, const QVariant& value)
{
    m_settings->setValue(key, value);
    m_settings->sync();
}

QVariant ApplicationSettings::getValue(const QString &key)
{
    return m_settings->value(key);
}

ApplicationSettings::ApplicationSettings(QObject *parent) : QObject(parent)
{
    m_settings = nullptr;
}
