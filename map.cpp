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
        unsigned k=0,j=0;
        while(getline(file,line))
        {
            map.push_back(vector<int>());
            for (unsigned i=0;i<line.length();++i)
            {
                if(line[i]==',')
                {
                    map[k].push_back(stoi(bit));
                    j++;
                    bit="";
                }
                else
                {
                    bit+=line[i];
                }
            }
            k++;
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    file.close();
}
