#ifndef CEMENTCREATOR_H
#define CEMENTCREATOR_H

#include "abstractcreator.h"

class FACTORY_EXPORT CementCreator : public AbstractCreator
{
public:
    CementCreator(int countBagsInPallet, float volumeMaterial);

    bool hasMaterialForPallet() const override;
    QSet<BuildingMaterial*> createPallet() override;
};

#endif // CEMENTCREATOR_H
