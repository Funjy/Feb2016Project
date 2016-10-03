#ifndef SERIALIZATIONINFO_H
#define SERIALIZATIONINFO_H

#include <QObject>
#include <QVariantMap>
#include <QJsonObject>

namespace PhotoFlyContainers {

class SerializationInfo// : public QObject
{
//    Q_OBJECT
public:
    static const QString TypeIdKey;
    static const QString UndefinedTypeIdStr;

//    explicit SerializationInfo(QObject *parent = 0);
//    explicit SerializationInfo(QVariantMap map, QObject *parent = 0);
    explicit SerializationInfo() {}
    explicit SerializationInfo(const QVariantMap &map);
//    explicit SerializationInfo(QVariantMap map, QObject *parent = 0);
    explicit SerializationInfo(const QJsonObject &json);
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

    QVariantMap toMap() const;
    QJsonObject toJson() const;

private:
    QVariantMap m_data;

};

}
Q_DECLARE_METATYPE(PhotoFlyContainers::SerializationInfo)

#endif // SERIALIZATIONINFO_H
