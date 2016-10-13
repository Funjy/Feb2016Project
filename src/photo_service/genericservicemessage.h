#ifndef GENERICSERVICEMESSAGE_H
#define GENERICSERVICEMESSAGE_H

#include <QObject>

#include "servicemessage.h"


namespace PhotoFlyService {
using namespace PhotoFlyContainers;

class GenericServiceMessage : public QObject, public ServiceMessage
{
    Q_OBJECT
    Q_PROPERTY(ServiceMessageType messageType READ getMessageType WRITE setMessageType NOTIFY messageTypeChanged)
    Q_PROPERTY(QVariantMap content READ getContent WRITE setContent NOTIFY contentChanged)

    static const QString TypeId;
public:
    static const QString ContentKey;

    explicit GenericServiceMessage(QObject *parent = nullptr);
    explicit GenericServiceMessage(
            ServiceMessageType type,
            const QVariantMap& content,
            QObject *parent = nullptr);

    // ISerializable interface
    virtual void getObjectInfo(SerializationInfo &info) const override;
    virtual void deserialize(const SerializationInfo &info) override;

    // ServiceMessage interface
    virtual ServiceMessageType getMessageType() const override;

    void setMessageType(ServiceMessageType value);
    void setMessageType(const QString& value);

    virtual const QVariantMap &getContent() const override;
    inline QVariantMap &getContent()
    { return m_content; }

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
