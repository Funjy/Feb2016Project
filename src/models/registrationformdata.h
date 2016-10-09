#ifndef REGISTRATIONFORMDATA_H
#define REGISTRATIONFORMDATA_H

#include <QObject>
#include <QQmlListProperty>
#include <QDebug>

#include "behaviours/iserializable.h"

#define PasswordStorageType PhotoFlyModels::RegistrationFormData::PasswordType
#define SourceFormType PhotoFlyModels::RegistrationFormData::SourceForm

#define USE_RegistrationFormData_TYPEID 0

namespace PhotoFlyModels{

using namespace PhotoFlyBehaviours;

class RegistrationFormData : public QObject, ISerializable
{
    Q_OBJECT
    Q_DISABLE_COPY(RegistrationFormData)

    Q_PROPERTY(bool isValid     READ isValid                NOTIFY isValidChanged)
    Q_PROPERTY(QString name     MEMBER m_name               NOTIFY nameChanged)
    Q_PROPERTY(QString surname  MEMBER m_surname            NOTIFY surnameChanged)
    Q_PROPERTY(QString email    MEMBER m_email              NOTIFY emailChanged)
    Q_PROPERTY(QString password MEMBER m_password           NOTIFY passwordChanged)
    Q_PROPERTY(QString address  MEMBER m_postalAddress      NOTIFY addressChanged)
    Q_PROPERTY(QString phoneNumber  MEMBER m_phoneNumber    NOTIFY phoneNumberChanged)
    Q_PROPERTY(QVariant ccnList READ ccnList                NOTIFY ccnListChanged)
//    Q_PROPERTY(SourceFormType sourceForm MEMBER m_sourceForm NOTIFY sourceFormChanged)

public:

    static const QString UserInfoGroup;
    static const QString NameKey;
    static const QString SurnameKey;
    static const QString EmailKey;
    static const QString PasswordKey;
    static const QString PostalAddressKey;
    static const QString PhoneNumberKey;
    static const QString CCNListKey;

    enum PasswordType{
        PT_Direct,
        PT_Hash
    };
    Q_ENUM(PasswordType)

//    enum SourceForm{
//        SF_Login,
//        SF_Registration
//    };
//    Q_ENUM(SourceForm)

    explicit RegistrationFormData(QObject *parent = 0);
//    RegistrationFormData(const RegistrationFormData &other);

    // ISerializable interface
    virtual void getObjectInfo(SerializationInfo &info) const override;
    virtual void deserialize(const SerializationInfo& info) override;

    //    void serialize(QVariant &object);
    //    void deserialize(const QVariant &object);

    Q_INVOKABLE bool    isValid() const;
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

    QString getPostalAddress() const;
    void setPostalAddress(const QString &postalAddress);

    PasswordType getPasswordType() const;
    void setPasswordType(const PasswordType &passwordType);

    QString getPhoneNumber() const;
    void setPhoneNumber(const QString &phoneNumber);

//    static const QStringList &properties2Serialize();

signals:
    void nameChanged();
    void surnameChanged();
    void emailChanged();
    void addressChanged();
    void ccnListChanged();
    void isValidChanged();
    void passwordChanged();
    void phoneNumberChanged();
//    void sourceFormChanged();

public slots:

private:
    bool                    m_isValid;
    QString                 m_name;
    QString                 m_surname;
    QString                 m_email;
    QString                 m_password;
    QString                 m_phoneNumber;
    QMap<uint, QString>     m_ccnList;
    QString                 m_postalAddress;
    PasswordType            m_passwordType;
//    SourceForm              m_sourceForm;

};

}

Q_DECLARE_METATYPE      (PhotoFlyModels::RegistrationFormData*)

#endif // REGISTRATIONFORMDATA_H
