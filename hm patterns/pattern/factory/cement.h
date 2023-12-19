#ifndef CEMENT_H
#define CEMENT_H

#include "buildingmaterial.h"

class Cement : public BuildingMaterial
{
public:
    Cement(float price, float bagWeight);
};

#endif // CEMENT_H
