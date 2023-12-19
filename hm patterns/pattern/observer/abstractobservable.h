#ifndef ABSTRACTOBSERVABLE_H
#define ABSTRACTOBSERVABLE_H

#include "abstractobserver.h"
#include <QSet>

class AbstractObservable
{
public:
    AbstractObservable();
    virtual ~AbstractObservable() = default;

    virtual void addObserver(AbstractObserver* observer) = 0;
    virtual void removeObserver(AbstractObserver* observer) = 0;
    virtual void notifyObservers(const QString& message) const = 0;

protected:
    QSet<AbstractObserver*> m_listObservers;
};

#endif // ABSTRACTOBSERVABLE_H
