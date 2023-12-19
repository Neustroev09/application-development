#include "sandcreator.h"
#include "sand.h"
#include <QDebug>

SandCreator::SandCreator(int countBagsInPallet, float volumeMaterial) : AbstractCreator(countBagsInPallet, volumeMaterial)
{
    m_name = "Песок";
    m_bagWeight = 8.0;
}

bool SandCreator::hasMaterialForPallet() const
{
    return (m_volumeMaterial - (m_bagWeight * m_countBagsInPallet) >= 0);
}

QSet<BuildingMaterial*> SandCreator::createPallet()
{
    QSet<BuildingMaterial*> pallet;
    for (int i = 0; i < m_countBagsInPallet; ++i)
    {
        pallet.insert(new Sand(100, m_bagWeight));
        m_volumeMaterial -= m_bagWeight;
    }
    qInfo() << "Паллета заполена мешками с песком";
    return pallet;
}
