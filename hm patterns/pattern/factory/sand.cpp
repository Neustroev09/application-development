#include "sand.h"
#include <QDebug>

Sand::Sand(float price, float bagWeight)
    : BuildingMaterial("Песок", price, bagWeight)
{
    qInfo() << "Создан мешок с песком";
}
