#include "map.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Map::Map()
{

}

void Map::ReadFile(string fileName)
{
    ifstream file(fileName);

    if(file)
    {
        string line;
        while(getline(file,line))
        {

        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}
