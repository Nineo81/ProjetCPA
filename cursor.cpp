#include "cursor.h"

Cursor::Cursor(int posX,int posY):posX(posX),posY(posY)
{

}

void Cursor::move(int up,int left,int down,int right)
{
    if(posX-left>0){this->posX=posX-left;}
}
