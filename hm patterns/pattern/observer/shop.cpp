#include "shop.h"

Shop::Shop()
{
}

void Shop::addObserver(AbstractObserver* observer)
{
    m_listObservers.insert(observer);
}

void Shop::removeObserver(AbstractObserver* observer)
{
    m_listObservers.remove(observer);
}

void Shop::notifyObservers(const QString& message) const
{
    for (const auto& observer : qAsConst(m_listObservers))
        observer->update(message);
}
