#ifndef _LOADGAME_H_
#define _LOADGAME_H_
#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"

using namespace std;

void loadGame();
void Add_NewFile_to_vector_fileNames(string fileName);
void Overwrite_information_to_file(const std::string& fileName, int** a, int turn, int lastX, int lastY, int BOARD_SIZE);
void loadFromFile(string filename);


#endif