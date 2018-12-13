#include "buildingmenu.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "custombutton.h"

BuildingMenu::BuildingMenu(int posX,int posY,Building* building):building(building)
{
    CustomButton *button1 = new CustomButton(1,"Infantry");
    button1->setAutoDefault(true);
    QObject::connect(button1,SIGNAL(customClicked(int)),this,SLOT(create(int)));
    CustomButton *button2 = new CustomButton(2,"Bazooka");
    button2->setAutoDefault(true);
    QObject::connect(button2,SIGNAL(customClicked(int)),this,SLOT(create(int)));
    CustomButton *button3 = new CustomButton(3,"Recon");
    button3->setAutoDefault(true);
    QObject::connect(button3,SIGNAL(customClicked(int)),this,SLOT(create(int)));
    CustomButton *button4 = new CustomButton(4,"AntiAir");
    button4->setAutoDefault(true);
    QObject::connect(button4,SIGNAL(customClicked(int)),this,SLOT(create(int)));
    CustomButton *button5 = new CustomButton(5,"Tank");
    button5->setAutoDefault(true);
    QObject::connect(button5,SIGNAL(customClicked(int)),this,SLOT(create(int)));
    CustomButton *button6 = new CustomButton(6,"mdtank");
    button6->setAutoDefault(true);
    QObject::connect(button6,SIGNAL(customClicked(int)),this,SLOT(create(int)));
    CustomButton *button7 = new CustomButton(7,"megatank");
    button7->setAutoDefault(true);
    QObject::connect(button7,SIGNAL(customClicked(int)),this,SLOT(create(int)));
    CustomButton *button8 = new CustomButton(8,"neotank");
    button8->setAutoDefault(true);
    QObject::connect(button8,SIGNAL(customClicked(int)),this,SLOT(create(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);
    layout->addWidget(button4);
    layout->addWidget(button5);
    layout->addWidget(button6);
    layout->addWidget(button7);
    layout->addWidget(button8);

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
