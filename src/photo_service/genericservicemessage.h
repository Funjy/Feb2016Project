#ifndef GENERICSERVICEMESSAGE_H
#define GENERICSERVICEMESSAGE_H

#include <QObject>

#include "servicemessage.h"

namespace PhotoFlyService {

class GenericServiceMessage : public QObject, public ServiceMessage
{
    Q_OBJECT
    Q_PROPERTY(ServiceMessage::Type messageType READ getType WRITE setType NOTIFY messageTypeChanged)
    Q_PROPERTY(QVariantMap content READ getContent WRITE setContent NOTIFY contentChanged)

public:
    explicit GenericServiceMessage(QObject *parent = 0);
    GenericServiceMessage(const GenericServiceMessage& other) { Q_UNUSED(other) }
    GenericServiceMessage &operator=(const GenericServiceMessage &other) {return *this;}

    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) override;

    // ServiceMessage interface
    virtual Type getType() const override;

    void setType(Type value);

    QVariantMap getContent() const;
    void setContent(const QVariantMap &content);

signals:
    void messageTypeChanged();
    void contentChanged();

public slots:

private:
    Type        m_type;
    QVariantMap m_content;



};

}
Q_DECLARE_METATYPE(PhotoFlyService::GenericServiceMessage)

#endif // GENERICSERVICEMESSAGE_H
