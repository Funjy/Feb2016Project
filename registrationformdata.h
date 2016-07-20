#ifndef REGISTRATIONFORMDATA_H
#define REGISTRATIONFORMDATA_H

#include <QObject>

class RegistrationFormData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name MEMBER m_name NOTIFY nameChanged)
    Q_PROPERTY(QString ccn MEMBER m_ccn NOTIFY ccnChanged)

public:
    explicit RegistrationFormData(QObject *parent = 0);
    RegistrationFormData(const RegistrationFormData &other);

signals:
    void nameChanged();
    void ccnChanged();

public slots:

private:
    QString m_name;
    QString m_ccn;
};
Q_DECLARE_METATYPE(RegistrationFormData)

#endif // REGISTRATIONFORMDATA_H
