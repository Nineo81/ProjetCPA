#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QPushButton bouton("Vous êtes mauvais !");
    bouton.show();/* A small change */

    return app.exec();
}
