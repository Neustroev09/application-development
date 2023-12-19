#include "buildingmaterial.h"

BuildingMaterial::BuildingMaterial(const QString& name, float price, float bagWeight)
{
    m_name = name,
    m_price = price;
    m_bagWeight = bagWeight;
}
