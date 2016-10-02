#ifndef REGISTRATIONFORMDATA_H
#define REGISTRATIONFORMDATA_H

#include <QObject>
#include <QQmlListProperty>
#include <QDebug>

#include "behaviours/iserializable.h"

#define PasswordStorageType PhotoFlyModels::RegistrationFormData::PasswordType

namespace PhotoFlyModels{

using namespace PhotoFlyBehaviours;

class RegistrationFormData : public QObject, ISerializable
{
    Q_OBJECT

    Q_PROPERTY(bool isValid     READ isValid                NOTIFY isValidChanged)
    Q_PROPERTY(QString name     MEMBER m_name               NOTIFY nameChanged)
    Q_PROPERTY(QString surname  MEMBER m_surname            NOTIFY surnameChanged)
    Q_PROPERTY(QString email    MEMBER m_email              NOTIFY emailChanged)
    Q_PROPERTY(QString password MEMBER m_password           NOTIFY passwordChanged)
    Q_PROPERTY(QString address  MEMBER m_poastalAddress     NOTIFY addressChanged)
    Q_PROPERTY(QVariant ccnList READ ccnList                NOTIFY ccnListChanged)

public:

    static const QString NameKey;
    static const QString SurnameKey;
    static const QString EmailKey;
    static const QString PasswordKey;
    static const QString PostalAddressKey;
    static const QString CCNListKey;

    enum PasswordType{
        PT_Direct,
        PT_Hash
    };
    Q_ENUM(PasswordType)

    explicit RegistrationFormData(QObject *parent = 0);
    RegistrationFormData(const RegistrationFormData &other);

    ~RegistrationFormData(){
        qDebug() << "RegistrationFormData destroyed: " << m_name;
    }

    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const override;

    //    void serialize(QVariant &object);
    //    void deserialize(const QVariant &object);

    bool        isValid() const;
    QVariant    ccnList() const;

    QString getName() const;
    void setName(const QString &name);

    QString getSurname() const;
    void setSurname(const QString &surname);

    QString getEmail() const;
    void setEmail(const QString &email);

    QString getPassword() const;
    void setPassword(const QString &password);

    QMap<uint, QString> getCcnList() const;
    void setCcnList(const QMap<uint, QString> &ccnList);

    QString getPoastalAddress() const;
    void setPoastalAddress(const QString &poastalAddress);

    PasswordType getPasswordType() const;
    void setPasswordType(const PasswordType &passwordType);

signals:
    void nameChanged();
    void surnameChanged();
    void emailChanged();
    void addressChanged();
    void ccnListChanged();
    void isValidChanged();
    void passwordChanged();

public slots:

private:
    bool                    m_isValid;
    QString                 m_name;
    QString                 m_surname;
    QString                 m_email;
    QString                 m_password;
    QMap<uint, QString>     m_ccnList;
    QString                 m_poastalAddress;
    PasswordType            m_passwordType;


};

}

Q_DECLARE_METATYPE      (PhotoFlyModels::RegistrationFormData)
Q_DECLARE_OPAQUE_POINTER(PhotoFlyModels::RegistrationFormData)
//Q_DECLARE_METATYPE      (RegistrationFormData*)

#endif // REGISTRATIONFORMDATA_H
