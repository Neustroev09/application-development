#include "manager.h"
#include <QDebug>

Manager::Manager(const QString& name)
{
    m_name = name;
}

void Manager::update(const QString& message)
{
    qInfo() << QString("%1 получил сообщение: %2").arg(m_name, message);
}
