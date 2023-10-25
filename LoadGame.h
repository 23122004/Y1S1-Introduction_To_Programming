#ifndef _LOADGAME_H_
#define _LOADGAME_H_
#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
#include <fstream>
#include <utility>

#define F first
#define S second
typedef pair<int, int> ii;

using namespace std;

//main
void loadGame(int XX, int YY);

//savegame
void Write_File(string fileName, bool vsBot, string name1, string name2, vector<ii> Data);

//loadgame
void loadFromFile(string filename, bool& vsBot, string& name1, string& name2, vector<ii>& Data);

//??
void drawNameOfGame(int XX, int YY, int index_file_name);

#endif