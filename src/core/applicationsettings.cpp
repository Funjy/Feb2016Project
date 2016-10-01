#include "applicationsettings.h"


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
    m_isFirstLaunch = appSettingsCore.value(OPTION_IS_FIRST_LAUNCH, true).toBool();
    setValue(OPTION_IS_FIRST_LAUNCH, false);
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

QVariant ApplicationSettings::getValue(const QString &key)
{
    return m_settings->value(key);
}

bool ApplicationSettings::isFirstLaunch() const
{
    return m_isFirstLaunch;
}

QString ApplicationSettings::keyIsRegistered() const
{
    return QString(GROUP_GENERAL) + "/" + OPTION_IS_REGISTERED;
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
