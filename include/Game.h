#ifndef _GAME_H_
#define _GAME_H_

#include "library.h"
#include <vector>
#include <string>
#include <set>
#include <utility>

struct Point {
    int X, Y, opt; // opt = 1 if X, opt = -1 if O, 0 if empty
};

class Game {
public:
    static const int BOARD_SIZE = 15;

    Game();
    ~Game();

    void startGame(bool vsBot, bool isNewGame, int XX, int YY, std::string name1, std::string name2, std::vector<std::pair<int, int>> Data, std::string fileName, int Xscore, int Oscore);

    // Public for View to access (or could be friend)
    Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];

private:
    int Turn;
    int maxDepth;
    std::vector<std::pair<int, int>> Cache;
    std::vector<std::pair<int, int>> winLine;
    std::set<std::pair<int, int>> Neighbor;

    // Helper methods
    long long consecutiveScore(int len, int openEnds, bool currentTurn);
    long long get_score(int a[], int player);
    bool valid(int x, int y);
    long long evaluation(int player);
    long long minimax(int depth, long long alpha, long long beta, int player, int& x, int& y);
    void botMove(int& x, int& y);
    void addNeighbor(int x, int y);
    void makeMove(int Turn, int x, int y);
    void updateNeighbor();
    void displayWinLine(int XX, int YY);
};

#endif
