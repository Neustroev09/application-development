#include "cement.h"
#include <QDebug>

Cement::Cement(float price, float bagWeight)
    : BuildingMaterial("Цемент", price, bagWeight)
{
    qInfo() << "Создан мешок с цементои";
}
