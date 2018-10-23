#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton bouton("Vous êtes mauvais !");
    bouton.show();/*Ceci est un nouvea test*/

    return app.exec();
}
