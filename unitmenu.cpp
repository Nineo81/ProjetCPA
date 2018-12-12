#include "unitmenu.h"
#include <QVBoxLayout>
#include <QPushButton>

UnitMenu::UnitMenu(int posX,int posY,int type)
{
    QPushButton *button1 = new QPushButton("Move");
    button1->setAutoDefault(true);
    QObject::connect(button1, SIGNAL(clicked()),this,SLOT(movement()));
    QPushButton *button2 = new QPushButton("Attack");
    button2->setAutoDefault(true);
    QObject::connect(button2, SIGNAL(clicked()),this,SLOT(attack()));
    QPushButton *button3 = new QPushButton("Capture");
    button3->setAutoDefault(true);
    QObject::connect(button3, SIGNAL(clicked()),this,SLOT(capture()));
    QPushButton *button4 = new QPushButton("Wait");
    button4->setAutoDefault(true);
    QObject::connect(button4,SIGNAL(clicked()),this,SLOT(unitWait()));

    QVBoxLayout *layout = new QVBoxLayout;
    switch(type){
        case 1:
            layout->addWidget(button1);
            layout->addWidget(button2);
            layout->addWidget(button3);
            layout->addWidget(button4);
        break;
        case 2:
            layout->addWidget(button1);
            layout->addWidget(button3);
            layout->addWidget(button4);
        break;
        case 3:
            layout->addWidget(button1);
            layout->addWidget(button2);
            layout->addWidget(button4);
        break;
        case 4:
            layout->addWidget(button1);
            layout->addWidget(button4);
        break;
        case 5:
            layout->addWidget(button2);
            layout->addWidget(button3);
            layout->addWidget(button4);
        break;
        case 6:
            layout->addWidget(button3);
            layout->addWidget(button4);
        break;
        case 7:
            layout->addWidget(button2);
            layout->addWidget(button4);
        break;
        case 8:
            layout->addWidget(button4);
        break;
    }
    setLayout(layout);
    move(posX,posY);
}

void UnitMenu::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Backspace){
    //retour == bouton B
        close();
    }
}

void UnitMenu::movement()
{
    emit moveUnit();
    close();
}

void UnitMenu::unitWait()
{
    emit waiting();
    close();
}

void UnitMenu::capture()
{
    emit capturing();
    close();
}

void UnitMenu::attack()
{
    emit attacking();
    close();
}
