#include "mainmenu.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QScreen>
#include "game.h"

MainMenu::MainMenu(QWidget *parent) : QWidget(parent)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    this->resize(screen->availableGeometry().width() / 2,screen->availableGeometry().height() / 2);
    move(screen->availableGeometry().center()-this->rect().center());
    text <<"Multiplayer (local)"<<"Multiplayer (online)"<<"Singleplayer (IA inactive)"<<"Singleplayer (IA pathfinder)"<<"Singleplayer (Greedy IA)";
    for(int i = 0; i < 5; i++)
    {
        listButton.push_back(new CustomButton(i + 1, text.at(i)));
        listButton[i]->setAutoDefault(true);
        QObject::connect(listButton[i],SIGNAL(customClicked(int)),this,SLOT(creatGame(int)));
    }
    QVBoxLayout *layout = new QVBoxLayout;
    for(int i = 0; i < 5; i++)
    {
        layout->addWidget(listButton[i]);
    }
    setLayout(layout);
}

void MainMenu::creatGame(int gameType)
{
    Game* g = new Game(gameType);
    close();
}

MainMenu::~MainMenu()
{
    for(CustomButton* b : listButton)
    {
        delete b;
    }
}
