#ifndef BUILDINGMATERIAL_H
#define BUILDINGMATERIAL_H

#include <QString>
#include "factory_global.h"

class FACTORY_EXPORT BuildingMaterial
{
public:
    BuildingMaterial(const QString& name, float price, float bagWeight);
    virtual ~BuildingMaterial() = default;

    QString name() const { return m_name; };
    double price() const { return m_price; };
    double bagWeight() const { return m_bagWeight; };

private:
    QString m_name;
    float m_price = 0.0;
    float m_bagWeight = 0.0;
};

#endif // BUILDINGMATERIAL_H
