#ifndef _LOADGAME_H_
#define _LOADGAME_H_
#include "library.h"
#include <vector>
#include <string>
#include <utility>

typedef std::pair<int, int> ii;

void loadGame(int XX, int YY);
void saveGame(int XX, int YY, std::vector<ii> Cache, int Xscore, int Oscore, std::string name1, std::string name2, std::string& nameFile, bool vsBot);
void loadFromFile(std::string nameFile, std::vector<ii>& Cache, int& Xscore, int& Oscore, std::string& name1, std::string& name2, bool& vsBot);
void deleteFile(std::string nameFile);
void pullList();
void pushList();

#endif
