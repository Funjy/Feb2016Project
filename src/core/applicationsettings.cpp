#include "applicationsettings.h"

using namespace PhotoFlySettings;

void ApplicationSettings::init()
{
    calcRatio();
    QQmlEngine::setObjectOwnership(&appSettings, QQmlEngine::CppOwnership);

    // Init settings file
    if (!m_settings) {
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
//    setValue(KeyIsFirstLaunch, true);
    // note: debug
//    m_isFirstLaunch = true;

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

void ApplicationSettings::saveUserInfo(const RegistrationFormData &userInfo)
{
    appSettingsCore.beginGroup(RegistrationFormData::UserInfoGroup);
    SerializationInfo si;
    userInfo.getObjectInfo(si);
    for (auto key : si.asMap().keys()) {
        appSettingsCore.setValue(key, si[key]);
    }
    appSettingsCore.endGroup();
}

void ApplicationSettings::readUserInfo(RegistrationFormData *userInfo)
{
    if (!userInfo)
        return;

    appSettingsCore.beginGroup(RegistrationFormData::UserInfoGroup);


    SerializationInfo si;
    userInfo->getObjectInfo(si);
//    auto keys = si.keys();
//    si.clear();

    for (auto key : si.asMap().keys()) {
//        si.addValue(key, appSettingsCore.value(key));
        si[key] = appSettingsCore.value(key);
    }
    userInfo->deserialize(si);
    appSettingsCore.endGroup();

}

//QString ApplicationSettings::keyIsRegistered() const
//{
//    return FULL_PARAM_KEY(GroupGeneral, KeyIsRegistered);
//}

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
