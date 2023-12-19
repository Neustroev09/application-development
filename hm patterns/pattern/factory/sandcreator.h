#ifndef SANDCREATOR_H
#define SANDCREATOR_H

#include "abstractcreator.h"

class FACTORY_EXPORT SandCreator : public AbstractCreator
{
public:
    SandCreator(int countBagsInPallet, float volumeMaterial);

    bool hasMaterialForPallet() const override;
    QSet<BuildingMaterial*> createPallet() override;
};

#endif // SANDCREATOR_H
