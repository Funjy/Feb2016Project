#ifndef ISERIALIZATIONINFO_H
#define ISERIALIZATIONINFO_H

#include <QObject>

class ISerializationInfo : public QObject
{
    Q_OBJECT
public:
    explicit ISerializationInfo(QObject *parent = 0);

signals:

public slots:
};

#endif // ISERIALIZATIONINFO_H