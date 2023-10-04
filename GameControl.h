#ifndef _GAMECONTROL_H_
#define _GAMECONTROL_H_
#include "library.h"
using namespace std;

struct _Point 
{
	int X, Y, opt;
};

long long consecutiveScore(int len, int openEnds, bool currentTurn);
long long get_score(int a[],int player);
bool valid(int x, int y);
long long evaluation(int player);
long long minimax(int depth, long long alpha, long long beta, int player, int& x, int& y);
void resetData(int startX, int startY);
void botMove(int& x, int& y);
void playerMove(int& x, int& y, int turn);

#endif