#ifndef REGISTRATIONFORMDATA_H
#define REGISTRATIONFORMDATA_H

#include <QObject>
#include <QQmlListProperty>

class RegistrationFormData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name     MEMBER m_name       NOTIFY nameChanged)
    Q_PROPERTY(QString surname  MEMBER m_surname    NOTIFY surnameChanged)
    Q_PROPERTY(QString email    MEMBER m_email      NOTIFY emailChanged)
    Q_PROPERTY(QString address  MEMBER m_address    NOTIFY addressChanged)
    Q_PROPERTY(QVariant ccnList READ ccnList        NOTIFY ccnListChanged)

public:
    explicit RegistrationFormData(QObject *parent = 0);
    RegistrationFormData(const RegistrationFormData &other);

    QVariant ccnList() const;

signals:
    void nameChanged();
    void surnameChanged();
    void emailChanged();
    void addressChanged();
    void ccnListChanged();

public slots:

private:
    QString                 m_name;
    QString                 m_surname;
    QString                 m_email;
    QHash<uint, QString>    m_ccnList;
    QString                 m_address;
};
Q_DECLARE_METATYPE(RegistrationFormData)

#endif // REGISTRATIONFORMDATA_H
