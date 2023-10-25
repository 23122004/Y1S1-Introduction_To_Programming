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

//loadgame
//void loadFromFile(string filename, bool& vsBot, string& name1, string& name2, vector<ii>& Data);

void saveGame(int XX, int YY, vector<ii> Cache, int Xscore, int Oscore, string name1, string name2, string nameFile, bool vsBot);
void deleteFile(string nameFile);

#endif

/*
void Add_NewFile_to_vector_fileNames(string fileName);
void Overwrite_information_to_file(const std::string& fileName, int** a, int turn, int lastX, int lastY, int BOARD_SIZE);
void loadFromFile(string filename);
void CurrentGame(string filename, int XX, int YY, int index_file_name);
void drawBoardWithValues(int XX, int YY, int** a);
void drawNameOfGame(int XX, int YY, int index_file_name);
*/