#ifndef ABSTRACTOBSERVER_H
#define ABSTRACTOBSERVER_H

#include <QString>

class AbstractObserver
{
public:
    AbstractObserver();
    virtual ~AbstractObserver() = default;

    virtual void update(const QString& message) = 0;
};

#endif // ABSTRACTOBSERVER_H
