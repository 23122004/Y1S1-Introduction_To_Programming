#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include "library.h"
#include <string>

class Console {
public:
    static void fixConsoleWindow(int WIDTH, int HEIGHT);
    static void gotoXY(int x, int y);
    static void setColor(int background_color, int text_color);
    static void showCursor(bool visibility);
    static void getCursorPosition(int& x, int& y);
    static int nextMove();
    static void drawImage(int x, int y, const std::string &nameFile);
    static void drawSquare(int i, int j, int x, int y, int color);
};

#endif
