#ifndef MANAGER_H
#define MANAGER_H

#include "abstractobserver.h"
#include "observer_global.h"

class OBSERVER_EXPORT Manager : public AbstractObserver
{
public:
    Manager(const QString& name);

    void update(const QString& message) override;

private:
    QString m_name;
};

#endif // MANAGER_H
