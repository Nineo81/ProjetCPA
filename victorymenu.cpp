#include "victorymenu.h"
#include <QApplication>
#include <QScreen>
#include <QPushButton>
#include <QLabel>

VictoryMenu::VictoryMenu(const QString & text)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    this->resize(screen->availableGeometry().width()/2,screen->availableGeometry().height()/2);
    move(screen->availableGeometry().center()-this->rect().center());
    QFont serifFont("Times", 22, QFont::Bold);
    QLabel* label = new QLabel(this);
    label->setFont(serifFont);
    label->setText(text);
    label->setAlignment(Qt::AlignCenter);
    QPushButton* button = new QPushButton("End Game",this);
    QObject::connect(button,SIGNAL(clicked()),this,SLOT(ending()));
    button->setGeometry(this->rect().center().x(),this->rect().center().y()-5,this->width()/4,this->height()/4);
}

void VictoryMenu::ending()
{
    emit endingGame();
    close();
}
