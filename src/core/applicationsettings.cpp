#include "applicationsettings.h"

using namespace PhotoFlySettings;

void ApplicationSettings::init()
{
    calcRatio();
    QQmlEngine::setObjectOwnership(&appSettings, QQmlEngine::CppOwnership);

    // Init settings file
    if(!m_settings){
//        QString path = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
//        if(!QDir(path).exists()){
//            QDir().mkpath(path);
//        }
//        QString fullName = QString("%1/%2.conf").arg(path).arg(qApp->applicationName());
//        m_settings = new QSettings(fullName, QSettings::NativeFormat, this);
        m_settings = new QSettings(QSettings::UserScope, qApp->organizationName(), qApp->applicationName(), this);
    }
    // Registration data
    m_isFirstLaunch = appSettingsCore.value(KeyIsFirstLaunch, true).toBool();
    setValue(KeyIsFirstLaunch, false);
    // note: debug
    m_isFirstLaunch = true;

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

QVariant ApplicationSettings::getValue(const QString &key, const QVariant &defaultValue)
{
    return m_settings->value(key, defaultValue);
}

bool ApplicationSettings::getBoolValue(const QString &key, bool defaultValue)
{
    return m_settings->value(key, defaultValue).toBool();
}

bool ApplicationSettings::isFirstLaunch() const
{
    return m_isFirstLaunch;
}

QString ApplicationSettings::keyIsRegistered() const
{
    return FULL_PARAM_KEY(GroupGeneral, KeyIsRegistered);
}

qreal ApplicationSettings::ratio() const
{
    return m_ratio;
}

qreal ApplicationSettings::fontRatio() const
{
    return m_fontRatio;
}

ApplicationSettings::ApplicationSettings(QObject *parent) : QObject(parent)
{
    m_settings = nullptr;
}

void ApplicationSettings::calcRatio()
{
    // It's about iphone 5
    qreal refDpi = 326.;
    qreal refHeight = 1136.;
    qreal refWidth = 640.;
    QRect rect = qApp->primaryScreen()->geometry();
    qreal height = qMax(rect.width(), rect.height());
    qreal width = qMin(rect.width(), rect.height());
    qreal dpi = qApp->primaryScreen()->physicalDotsPerInch();
    m_ratio = qMin(height/refHeight, width/refWidth);
    m_fontRatio = qMin(height*refDpi/(dpi*refHeight), width*refDpi/(dpi*refWidth));
}

QString ApplicationSettings::getSettingsKeyString(AppSettingsKeys key)
{
    switch(key){
    case AppSettingsKeys::SK_IsFirsLaunch:
        return KeyIsFirstLaunch;
    case AppSettingsKeys::SK_IsRegistered:
        return KeyIsRegistered;
    default:
        return "";
    }
}
