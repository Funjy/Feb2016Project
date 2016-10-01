#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H

#include <QObject>
#include <QQmlEngine>
#include <QSettings>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QApplication>
#include <QScreen>

//#include "models/registrationformdata.h"

#define appSettings PhotoFlySettings::ApplicationSettings::instance()
#define appSettingsCore appSettings.settings()

#define AppSettingsKeys PhotoFlySettings::ApplicationSettings::SettingsKeys

//#define GROUP_GENERAL           "general"

//#define OPTION_IS_REGISTERED    "isRegistered"
//#define OPTION_IS_FIRST_LAUNCH  "isFirstLaunch"

#define FULL_PARAM_KEY(g,p) QString(g) + "/" + p

namespace PhotoFlySettings{

// General group
static constexpr const char* GroupGeneral =       "general";
static constexpr const char* KeyIsRegistered =    "isRegistered";
static constexpr const char* KeyIsFirstLaunch =   "isFirstLaunch";

class ApplicationSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString keyIsRegistered READ keyIsRegistered CONSTANT)

    Q_PROPERTY(qreal ratio READ ratio CONSTANT)
    Q_PROPERTY(qreal fontRatio READ fontRatio CONSTANT)

public:

    static ApplicationSettings& instance(){
        static ApplicationSettings instance;
        return instance;
    }

    void init();
    QSettings&  settings();    

    Q_INVOKABLE void        setValue(const QString& key, const QVariant &value);
    Q_INVOKABLE QVariant    getValue(const QString& key, const QVariant &defaultValue = QVariant());
    Q_INVOKABLE bool        isFirstLaunch() const;

    QString keyIsRegistered() const;
    qreal ratio() const;
    qreal fontRatio() const;

    enum SettingsKeys{
        SK_IsRegistered,
        SK_IsFirsLaunch
    };
    Q_ENUM(SettingsKeys)

    Q_INVOKABLE static QString getSettingsKeyString(AppSettingsKeys key);

signals:

public slots:

protected:
    explicit ApplicationSettings(QObject *parent = nullptr);
    ~ApplicationSettings() {}
    ApplicationSettings(const ApplicationSettings&);                 // Prevent copy-construction
    ApplicationSettings& operator=(const ApplicationSettings&);      // Prevent assignment

private:
    void calcRatio();

    QSettings   *m_settings;        
    qreal       m_ratio;
    qreal       m_fontRatio;
    bool        m_isFirstLaunch;
};

static QObject *ApplicationSettings_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return &appSettings;
}

}

#endif // APPLICATIONSETTINGS_H
