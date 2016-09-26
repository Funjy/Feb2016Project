#ifndef ISERIALIZATIONINFO_H
#define ISERIALIZATIONINFO_H

#include <QObject>
#include <QVariantMap>

namespace PhotoFlyContainers {

class SerializationInfo : public QObject
{
    Q_OBJECT
public:
    explicit SerializationInfo(QObject *parent = 0);

    void addValue(QString name, QVariant value);
    QVariant value(QString name);
    bool equals(const SerializationInfo& other);

    QList<QString> getKeys() const;

signals:

public slots:

private:
    QVariantMap m_data;

};

}

#endif // ISERIALIZATIONINFO_H
