#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton bouton("Vous êtes mauvais !");
    bouton.show();/*Ceci est un test*/

    return app.exec();
}
