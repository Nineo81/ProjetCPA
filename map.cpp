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
        string bit="";
        while(getline(file,line))
        {
            for (unsigned i=0;i<line.length();++i)
            {
                if(line[i]==',')
                {

                }
                else
                {
                    bit+=line[i];
                }
            }
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}
