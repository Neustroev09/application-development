#ifndef ABSTRACTCREATOR_H
#define ABSTRACTCREATOR_H

#include "buildingmaterial.h"
#include <QSet>

class FACTORY_EXPORT AbstractCreator
{
public:
    AbstractCreator(int countBagsInPallet, float volumeMaterial);
    virtual ~AbstractCreator() = default;

    QString nameMaterial() { return m_name; };

    virtual bool hasMaterialForPallet() const = 0;
    virtual QSet<BuildingMaterial*> createPallet() = 0;

protected:
    QString m_name;
    float m_bagWeight = 0.0;
    int m_countBagsInPallet = 0;
    float m_volumeMaterial = 0.0;
};

#endif // ABSTRACTCREATOR_H
