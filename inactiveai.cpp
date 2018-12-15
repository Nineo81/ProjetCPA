#include "inactiveai.h"

using std::cout;
using std::endl;

InactiveAI::InactiveAI(Game* game,int player):AI(game,player)       //donner une couleur ou un *player??
{
    this->game = game;
    this->player = player;
}

void InactiveAI::play(){
    if (game->getCursor()->getPlayerState() == player){
        game->getCursor()->switchPlayerState();
        cout<<"Tour passé!"<<endl;
    }
}
