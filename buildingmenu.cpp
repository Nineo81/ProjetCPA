#include "buildingmenu.h"
#include <QVBoxLayout>
#include <QPushButton>

BuildingMenu::BuildingMenu(int posX,int posY,Building* building):building(building)
{
    QPushButton *button1 = new QPushButton("Infantry");
    button1->setAutoDefault(true);
    QObject::connect(button1,SIGNAL(clicked()),this,SLOT(create1()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);

    setLayout(layout);
    move(posX,posY);
}

void BuildingMenu::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Backspace){
    //retour == bouton B
        close();
    }
}

void BuildingMenu::create1()
{
    building->createUnit(1);
}
