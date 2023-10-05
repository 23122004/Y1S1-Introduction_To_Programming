#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_
#include "library.h"
#include "Console.h"
using namespace std;

void drawA(int XX, int YY);
void drawB(int XX, int YY);
void drawC(int XX, int YY);
void drawO(int XX, int YY);
void drawR(int XX, int YY);
void drawU(int XX, int YY);
void drawT(int XX, int YY);
void drawL(int XX, int YY);
void drawL(int XX, int YY);
void drawD(int XX, int YY);
void drawG(int XX, int YY);
void drawM(int XX, int YY);
void drawE(int XX, int YY);

void drawCARO(int XX, int YY);
void drawABOUT(int XX, int YY);
void drawLOADGAME(int XX, int YY);

void drawBoard(int startX, int startY);
void drawBoardMenu(int XX, int YY, int size, int b_color, string str);

#endif