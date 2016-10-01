#ifndef GENERICSERVICEMESSAGE_H
#define GENERICSERVICEMESSAGE_H

#include <QObject>

#include "servicemessage.h"


namespace PhotoFlyService {

class GenericServiceMessage : public QObject, public ServiceMessage
{
    Q_OBJECT
    Q_PROPERTY(ServiceMessageType messageType READ getType WRITE setType NOTIFY messageTypeChanged)
    Q_PROPERTY(QVariantMap content READ getContent WRITE setContent NOTIFY contentChanged)

public:
    explicit GenericServiceMessage(QObject *parent = nullptr);
    explicit GenericServiceMessage(
            ServiceMessageType type,
            const QVariantMap& content,
            QObject *parent = nullptr);

    // ISerializable interface
    virtual void getObjectInfo(PhotoFlyContainers::SerializationInfo &info) const override;

    // ServiceMessage interface
    virtual ServiceMessageType getType() const override;

    void setType(ServiceMessageType value);

    QVariantMap getContent() const;
    void setContent(const QVariantMap &content);

    // ----------- Cope -----------

    GenericServiceMessage(const GenericServiceMessage& other);
//    GenericServiceMessage(GenericServiceMessage&& other);
    GenericServiceMessage &operator=(const GenericServiceMessage &other);
//    GenericServiceMessage &operator=(GenericServiceMessage other);
    virtual ~GenericServiceMessage(){}
    void swap(GenericServiceMessage &_v) throw();
    static void swap(GenericServiceMessage &first, GenericServiceMessage &second) throw();
    // ----------------------------

signals:
    void messageTypeChanged();
    void contentChanged();

public slots:

protected:
    QVariantMap &contentData();

private:
    ServiceMessageType      m_type;
    QVariantMap             m_content;

};

}
Q_DECLARE_METATYPE(PhotoFlyService::GenericServiceMessage)

#endif // GENERICSERVICEMESSAGE_H
