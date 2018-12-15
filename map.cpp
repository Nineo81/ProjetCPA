#include "map.h"
#include <string>
#include <iostream>
#include <fstream>
#include "mainwindow.h"

using namespace std;

Map::Map(const char* fileName)
{
    readFile(fileName);
}

Map::Map(unsigned int sizeX,unsigned int sizeY)
{
    for(unsigned int i = 0; i < sizeY; i++)
    {
        map.push_back(vector<int>(sizeX,0));
    }
}

void Map::readFile(const char* fileName)
{
    ifstream file;
    file.open(fileName);//Ouverture du fichier

    if(file) //Vérifie que le fichier existe bien
    {
        string line; //stockage des lignes du fichier (on travail ligne par ligne)
        string bit = "";  //stockage de partie de ligne
        unsigned int y = 0, x = 0; //compteur ligne et compteur colonne de la matrice map
        while(getline(file,line))
        {
            map.push_back(vector<int>()); //on crée une ligne vide dans la matrice
            for (unsigned int i = 0; i < line.length(); ++i) //on parcours la ligne du fichier
            {
                if(line[i] == ',') //Dès qu'on croise une virgule
                {
                    map[y].push_back(stoi(bit)); //stockage de la partie de ligne créé dans la map (stoi converti un string en int)
                    x++; //update du compteur de colonne
                    bit = ""; //reset du stockage de partie de ligne
                }
                else if(line[i] == '.')
                {
                    map[y].push_back(stoi(bit));
                    break;
                }
                else //Dans les autres cas
                {
                    bit += line[i]; //on ajoute dans le stockage partie de ligne le charactère lu de la ligne
                }
            }
            y++; //update du compteur ligne
        }
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    file.close();
}

unsigned int Map::getSize(char a)
{
    unsigned int size;
    if(a == 'y')
    {
        size = map.size();
    }
    else
    {
        size = map[0].size();
    }
    return size;
}

void Map::replace(unsigned int oldX,unsigned int oldY,unsigned int newX,unsigned int newY)
{
    int element = map[oldY][oldX];
    map[oldY][oldX] = 0;
    map[newY][newX] = element;
    window->updateWidget();
}

int Map::getElement(unsigned int posX, unsigned int posY)
{
    return map[posY][posX];
}

void Map::setElement(int element, unsigned int posX, unsigned int posY)
{
    map[posY][posX] = element;
    window->updateWidget();
}

void Map::setWindow(MainWindow* window)
{
    this->window=window;
}
