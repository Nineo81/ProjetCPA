#include "pausemenu.h"
#include <QVBoxLayout>
#include <QPushButton>

PauseMenu::PauseMenu(QWidget *parent) : QWidget(parent)
{
    QPushButton *button1 = new QPushButton("Pass Turn");
    button1->setAutoDefault(true);
    QObject::connect(button1, SIGNAL(clicked()),this,SLOT(passTurn()));
    QPushButton *button2 = new QPushButton("End Game");
    button1->setAutoDefault(true);
    QObject::connect(button2, SIGNAL(clicked()),this,SLOT(endGame()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(button1);
    layout->addWidget(button2);

    setLayout(layout);
    setFixedSize(300,400);
}

void PauseMenu::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Backspace){
    //retour == bouton B
        close();
    }
}

void PauseMenu::passTurn()
{
    emit nextPlayer();
    close();
}

void PauseMenu::endGame()
{
    emit ending();
    close();
}
