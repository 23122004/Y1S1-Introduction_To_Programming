#ifndef _GRAPHIC_H_
#define _GRAPHIC_H_

#include "library.h"
#include "Game.h"

// Graphics is a namespace or class of static methods to handle rendering
class Graphics {
public:
    static void drawA(int XX, int YY);
    static void drawB(int XX, int YY);
    static void drawC(int XX, int YY);
    static void drawO(int XX, int YY, int co_txt);
    static void drawR(int XX, int YY);
    static void drawU(int XX, int YY);
    static void drawT(int XX, int YY);
    static void drawL(int XX, int YY);
    static void drawD(int XX, int YY);
    static void drawG(int XX, int YY);
    static void drawM(int XX, int YY);
    static void drawE(int XX, int YY);
    static void drawN(int XX, int YY);
    static void drawW(int XX, int YY);
    static void drawH(int XX, int YY);
    static void drawP(int XX, int YY);
    static void drawX(int XX, int YY, int co_txt);
    static void drawI(int XX, int YY);

    static void drawCARO(int XX, int YY);
    static void drawABOUT(int XX, int YY);
    static void drawLOAD_GAME(int XX, int YY);
    static void drawNEW_GAME(int XX, int YY);
    static void drawHELP(int XX, int YY);
    static void drawIN_MATCH(int XX, int YY);
    static void drawX_WIN(int XX, int YY);
    static void drawO_WIN(int XX, int YY);
    static void drawDRAW(int XX, int YY);

    // Update: takes Game object reference
    static void drawBoard(int startX, int startY, std::string name1, std::string name2, int Xscore, int Oscore, std::string fileName, Game& game);

    static void drawBoardMenu(int XX, int YY, int size, int b_color, std::string str);
    static void drawBoardSize(int XX, int YY, int h, int w);
    static void drawPopUp(int XX, int YY, int h, int w);
    static void drawName_Board(int XX, int YY, std::string fileName);
    static void drawStatus(int XX, int YY, int opt);
};

#endif
