#ifndef CREATOR_H
#define CREATOR_H

#include "buildingmaterial.h"

class FACTORY_EXPORT Creator
{
public:
    Creator();
    virtual ~Creator() = default;
    virtual BuildingMaterial* factoryMethod() const = 0;

    void createPallet();
};

#endif // CREATOR_H
