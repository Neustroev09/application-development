#include <QCoreApplication>
#include <QDebug>

#include "../observer/manager.h"
#include "../observer/shop.h"
#include "../factory/cementcreator.h"
#include "../factory/sandcreator.h"


void sendPallets(AbstractCreator* creator, const Shop* shop)
{
    if (creator->hasMaterialForPallet())
        creator->createPallet();
    else
        shop->notifyObservers(QString("На складе закончился %1").arg(creator->nameMaterial()));
}


int main()
{
    AbstractCreator* sandCreator = new SandCreator(5, 40);
    AbstractCreator* cementCreator = new CementCreator(10, 60);
    Shop* shop = new Shop();

    Manager* manager1 = new Manager("Петя");
    Manager* manager2 = new Manager("Вася");
    Manager* manager3 = new Manager("Максим");

    shop->addObserver(manager1);
    shop->addObserver(manager2);
    shop->addObserver(manager3);

    sendPallets(sandCreator, shop);
    sendPallets(cementCreator, shop);
    qInfo() << "----------------------------------------\n";

    sendPallets(sandCreator, shop);
    sendPallets(cementCreator, shop);


    delete sandCreator;
    delete cementCreator;
    delete shop;
    delete manager1;
    delete manager2;
    delete manager3;

    return 0;
}
