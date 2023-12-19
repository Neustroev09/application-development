#include "cementcreator.h"
#include "cement.h"
#include <QDebug>

CementCreator::CementCreator(int countBagsInPallet, float volumeMaterial) : AbstractCreator(countBagsInPallet, volumeMaterial)
{
    m_name = "Цемент";
    m_bagWeight = 6.0;
}

bool CementCreator::hasMaterialForPallet() const
{
    return (m_volumeMaterial - (m_bagWeight * m_countBagsInPallet) >= 0);
}

QSet<BuildingMaterial*> CementCreator::createPallet()
{
    QSet<BuildingMaterial*> pallet;
    for (int i = 0; i < m_countBagsInPallet; ++i)
    {
        pallet.insert(new Cement(150, m_bagWeight));
        m_volumeMaterial -= m_bagWeight;
    }
    qInfo() << "Паллета заполена мешками с цемантом";
    return pallet;
}
