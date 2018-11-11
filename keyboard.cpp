#include "keyboard.h"
#include <QKeyEvent>

Keyboard::Keyboard(Game* game):game(game)
{

}

void Keyboard::keyPressEvent(QKeyEvent * event){
    /*Je ne suis pas sure que ce sera ici a la fin,
     * ça depend de comment on fait notre truc il me semble.*/
    if (event->key() == Qt::Key_Left){
    //faire bouger la case selectionnee vers la gauche
    }
    if (event->key() == Qt::Key_Right){

    }
    if (event->key() == Qt::Key_Up){
    //faire bouger la case ou l'option (dans un menu) selectionee
    }
    if (event->key() == Qt::Key_Down){

    }
    if (event->key() == Qt::Key_Space || event->key() == Qt::Key_Enter){
    //confirmer la selection == bouton A
    }
    if (event->key() == Qt::Key_Escape || event->key() == Qt::Key_Backspace){
    //retour == bouton B
    }
}
