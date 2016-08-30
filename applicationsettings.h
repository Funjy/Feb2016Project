#ifndef APPLICATIONSETTINGS_H
#define APPLICATIONSETTINGS_H

#include <QObject>
#include <QQmlEngine>
#include <QSettings>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QApplication>

#define appSettings ApplicationSettings::instance()
#define appSettingsCore appSettings.settings()

#define OPTION_IS_REGISTERED    "isRegistered"

class ApplicationSettings : public QObject
{
    Q_OBJECT
public:

    static ApplicationSettings& instance(){
        static ApplicationSettings instance;
        return instance;
    }

    void init();
    QSettings&  settings();

    Q_INVOKABLE void        setValue(const QString& key, const QVariant &value);
    Q_INVOKABLE QVariant    getValue(const QString& key);

signals:

public slots:

protected:
    explicit ApplicationSettings(QObject *parent = nullptr);
    ~ApplicationSettings() {}
    ApplicationSettings(const ApplicationSettings&);                 // Prevent copy-construction
    ApplicationSettings& operator=(const ApplicationSettings&);      // Prevent assignment

private:
    QSettings   *m_settings;
};

static QObject *ApplicationSettings_provider(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)

    return &appSettings;
}

#endif // APPLICATIONSETTINGS_H
