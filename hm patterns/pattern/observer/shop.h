#ifndef SHOP_H
#define SHOP_H

#include "abstractobservable.h"
#include "observer_global.h"

class OBSERVER_EXPORT Shop : public AbstractObservable
{
public:
    Shop();

    void addObserver(AbstractObserver* observer) override;
    void removeObserver(AbstractObserver* observer) override;
    void notifyObservers(const QString& message) const override;
};

#endif // SHOP_H
