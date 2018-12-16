#include "unitmenu.h"
#include <QVBoxLayout>

UnitMenu::UnitMenu(int posX,int posY,int type)
{
    setEscape(true);
    setFocusPolicy(Qt::ClickFocus);
    text <<"Move"<<"Attack"<<"Capture"<<"Wait";
    for(int i=0;i<4;i++)
    {
        listButton.push_back(new QPushButton(text.at(i)));
        listButton[i]->setAutoDefault(true);
    }

    QObject::connect(listButton[0], SIGNAL(clicked()),this,SLOT(movement()));
    QObject::connect(listButton[1], SIGNAL(clicked()),this,SLOT(attack()));
    QObject::connect(listButton[2], SIGNAL(clicked()),this,SLOT(capture()));
    QObject::connect(listButton[3],SIGNAL(clicked()),this,SLOT(unitWait()));

    QVBoxLayout *layout = new QVBoxLayout;
    switch(type){
        case 1:
            layout->addWidget(listButton[0]);
            layout->addWidget(listButton[1]);
            layout->addWidget(listButton[2]);
            layout->addWidget(listButton[3]);
        break;
        case 2:
            layout->addWidget(listButton[1]);
            layout->addWidget(listButton[2]);
            layout->addWidget(listButton[3]);
        break;
        case 3:
            layout->addWidget(listButton[0]);
            layout->addWidget(listButton[1]);
            layout->addWidget(listButton[3]);
        break;
        case 4:
            layout->addWidget(listButton[0]);
            layout->addWidget(listButton[3]);
        break;
        case 5:
            layout->addWidget(listButton[1]);
            layout->addWidget(listButton[2]);
            layout->addWidget(listButton[3]);
        break;
        case 6:
            layout->addWidget(listButton[2]);
            layout->addWidget(listButton[3]);
        break;
        case 7:
            layout->addWidget(listButton[1]);
            layout->addWidget(listButton[3]);
        break;
        case 8:
            layout->addWidget(listButton[3]);
        break;
    }
    setLayout(layout);
    move(posX,posY);
}

void UnitMenu::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape && escape){
    //retour == bouton B
        emit menuClose();
        close();
    }
}

void UnitMenu::movement()
{
    emit menuClose();
    emit moveUnit();
    close();
}

void UnitMenu::unitWait()
{
    emit menuClose();
    emit waiting();
    close();
}

void UnitMenu::capture()
{
    emit menuClose();
    emit capturing();
    close();
}

void UnitMenu::attack()
{
    emit menuClose();
    emit attacking();
    close();
}

void UnitMenu::setEscape(bool escape)
{
    this->escape = escape;
}

void UnitMenu::focusOutEvent(QFocusEvent* event)
{
    if(!forceResponse)
    {
        close();
    }
}

void UnitMenu::forceResp()
{
    forceResponse = true;
}

UnitMenu::~UnitMenu()
{
    for(QPushButton* b : listButton)
    {
        delete b;
    }
}
