#ifndef ISERIALIZATIONINFO_H
#define ISERIALIZATIONINFO_H

#include <QObject>
#include <QVariantMap>

namespace PhotoFlyContainers {

class SerializationInfo : public QObject
{
    Q_OBJECT
public:
    static const QString TypeIdKey;
    static const QString UndefinedTypeIdStr;

    explicit SerializationInfo(QObject *parent = 0);
    explicit SerializationInfo(QVariantMap map, QObject *parent = 0);
    explicit SerializationInfo(const SerializationInfo& other);
    SerializationInfo &operator=(const SerializationInfo& other);

    void addValue(QString name, QVariant value);
    void addValue(QString name, const SerializationInfo& value);
    QVariant value(QString name);
    bool equals(const SerializationInfo& other);

    QString getTypeId() const;
    void setTypeId(const QString& typeId);

    QList<QString> getKeys() const;

    void swap(SerializationInfo &_v) throw();

signals:

public slots:

private:
    QVariantMap m_data;

};

}

#endif // ISERIALIZATIONINFO_H
