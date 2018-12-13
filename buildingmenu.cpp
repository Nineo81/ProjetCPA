#include "buildingmenu.h"
#include <QVBoxLayout>
#include "custombutton.h"

BuildingMenu::BuildingMenu(int posX,int posY,Building* building):building(building)
{
    text <<"Infantery"<<"Bazooka"<<"Recon"<<"AntiAir"<<"Tank"<<"MdTank"<<"MegaTank"<<"NeoTank"<<"B-copter"<<"Bomber"<<"Fighter";
    for(int i=0;i<11;i++)
    {
        listButton.push_back(new CustomButton(i+1,text.at(i)));
        listButton[i]->setAutoDefault(true);
        QObject::connect(listButton[i],SIGNAL(customClicked(int)),this,SLOT(create(int)));
    }

    QVBoxLayout *layout = new QVBoxLayout;
    if(building->getType()==35 || building->getType()==44){
    for(int i=0;i<8;i++)
    {
        layout->addWidget(listButton[i]);
    }
    }
    else
    {
        for(int i=8;i<11;i++)
        {
            layout->addWidget(listButton[i]);
        }
    }
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

void BuildingMenu::create(int type)
{
    building->createUnit(type);
    emit createU();
    this->close();
}

void BuildingMenu::isCLosing(QCloseEvent *event)
{
    if(event->isAccepted())
    {
        emit qMenuClose();
    }
}
