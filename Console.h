#ifndef _CONSOLE_H_
#define _CONSOLE_H_
#include "library.h"
using namespace std;

void fixConsoleWindow(int WIDTH, int HEIGHT);
void gotoXY(int x, int y);
void setColor(int background_color, int text_color);
void ShowCur(bool CursorVisibility);

#endif

