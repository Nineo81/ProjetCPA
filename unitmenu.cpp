#include "unitmenu.h"
#include <QVBoxLayout>
#include <QPushButton>

UnitMenu::UnitMenu(int posX,int posY)
{
    QPushButton *button1 = new QPushButton("Move");
    button1->setAutoDefault(true);
    QObject::connect(button1, SIGNAL(clicked()),this,SLOT(movement()));
    QPushButton *button2 = new QPushButton("Attack");
    button1->setAutoDefault(true);
    QObject::connect(button2, SIGNAL(clicked()),this,SLOT(close()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);

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
