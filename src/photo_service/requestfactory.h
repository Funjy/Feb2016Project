#ifndef REQUESTFACTORY_H
#define REQUESTFACTORY_H

#include <QObject>

class RequestFactory : public QObject
{
    Q_OBJECT
public:
    explicit RequestFactory(QObject *parent = 0);

signals:

public slots:
};

#endif // REQUESTFACTORY_H