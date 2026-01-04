#include "../include/Game.h"
#include "../include/Console.h"
#include "../include/Graphic.h"
#include "../include/LoadGame.h"
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define F first
#define S second

// Helper macro to move cursor based on grid coordinates
#define moveTo(x, y) Console::gotoXY(status[x][y].X, status[x][y].Y)

typedef pair<int, int> ii;

Game::Game() : Turn(1), maxDepth(3) {
    // Initialize status board?
    // Actually status array init depends on drawBoard mapping logical to screen coords.
    // This happens in drawBoard (in Graphic.cpp), which Game calls.
}

Game::~Game() {
}

long long Game::consecutiveScore(int len, int openEnds, bool currentTurn)
{
    if (len < 5 && openEnds == 0) return 0;
    switch (len)
    {
    case 4:
        switch (openEnds)
        {
        case 1:
            if (currentTurn)
                return 10000000;
            return 50;
        case 2:
            if (currentTurn)
                return 10000000;
            return 10000000;
        }
    case 3:
        switch (openEnds)
        {
        case 1:
            if (currentTurn)
                return 7;
            return 5;
        case 2:
            if (currentTurn)
                return 10000;
            return 50;
        }
    case 2:
        switch (openEnds)
        {
        case 1:
            return 3;
        case 2:
            return 5;
        }
    case 1:
        switch (openEnds)
        {
        case 1:
            return 1;
        case 2:
            return 2;
        }
    default:
        switch (openEnds)
        {
        case 2:
            return (long long)1e10;
        case 1:
            return (long long)1e10 - (long long)1e9;
        case 0:
            return (long long)1e10 - (long long)2e9;
        }
    }
}

long long Game::get_score(int a[], int player)
{
    int Size = BOARD_SIZE + 2;
    long long score = 0;
    for (int i = 1; i < Size - 1; i++) if (abs(a[i]) == 1) // get consecutive equal elements 
    {
        int j = i;
        while (j + 1 < Size - 1 && a[i] == a[j + 1]) j++;

        int len = j - i + 1;
        int openEnds = 2 - (a[i - 1] != 0) - (a[j + 1] != 0); // number of open cells
        score += 1ll * consecutiveScore(len, openEnds, player == a[i]) * a[i];
        i = j;
    }
    return score;
}

bool Game::valid(int x, int y)
{
    return y > 0 && x > 0 && x <= BOARD_SIZE && y <= BOARD_SIZE;
}

long long Game::evaluation(int player)
{
    long long score = 0;
    int* b = new int[BOARD_SIZE + 2];
    for (int i = 1; i <= BOARD_SIZE; i++) // get a row
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(i, k))
                b[k] = status[i][k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ i, k });
            delete[] b;
            return score;
        }
    }

    for (int j = 1; j <= BOARD_SIZE; j++) // get a column
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(k, j))
                b[k] = status[k][j].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ k, j });
            delete[] b;
            return score;
        }
    }

    for (int i = 0; i <= BOARD_SIZE; i++) // get a main diagonal
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(i + k, k))
                b[k] = status[i + k][k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ i + k, k });
            delete[] b;
            return score;
        }
    }
    for (int j = 1; j <= BOARD_SIZE; j++) // get a main diagonal
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(k, j + k))
                b[k] = status[k][j + k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ k, j + k });
            delete[] b;
            return score;
        }
    }

    for (int i = 1; i <= BOARD_SIZE + 1; i++) // get a secondary diagonal
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(i - k, k))
                b[k] = status[i - k][k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ i - k, k });
            delete[] b;
            return score;
        }
    }
    for (int j = 1; j <= BOARD_SIZE; j++) // get a secondary diagonal
    {
        for (int k = 0; k < BOARD_SIZE + 2; k++)
        {
            if (valid(BOARD_SIZE + 1 - k, j + k))
                b[k] = status[BOARD_SIZE + 1 - k][j + k].opt;
            else
                b[k] = 2;
        }
        score += get_score(b, player);
        if (abs(score) >= 1e8)
        {
            winLine.clear();
            for (int k = 0; k < BOARD_SIZE + 2; k++)
                winLine.push_back({ BOARD_SIZE + 1 - k, j + k });
            delete[] b;
            return score;
        }
    }
    delete[] b;
    return score;
}

long long Game::minimax(int depth, long long alpha, long long beta, int player, int& x, int& y)
{
    long long val = evaluation(player);
    if (depth == 0 || abs(val) >= 1e8)
        return val;

    if (player == 1)
    {
        long long maxEval = (long long)-1e11;
        vector<ii> a(Neighbor.begin(), Neighbor.end());
        for (const ii& tmp : a)
        {
            int i = tmp.F, j = tmp.S;
            if (status[i][j].opt == 0)
            {
                status[i][j].opt = 1;
                long long eval = minimax(depth - 1, alpha, beta, -1, x, y);
                status[i][j].opt = 0;
                if (maxEval < eval)
                {
                    maxEval = eval;
                    if (depth == maxDepth) x = i, y = j;
                }
                if (alpha < eval) alpha = eval;
                if (beta <= alpha)
                    break;
            }
        }
        return maxEval;
    }
    else
    {
        long long minEval = (long long)1e11;
        vector<ii> a(Neighbor.begin(), Neighbor.end());
        for(const ii &tmp : a)
        {
            int i = tmp.F, j = tmp.S;
            if (status[i][j].opt == 0)
            {
                status[i][j].opt = -1;
                long long eval = minimax(depth - 1, alpha, beta, 1, x, y);
                status[i][j].opt = 0;
                if (minEval > eval)
                {
                    minEval = eval;
                    if (depth == maxDepth) x = i, y = j;
                }
                if (beta > eval) beta = eval;
                if (beta <= alpha)
                    break;
            }
        }
        return minEval;
    }
}

void Game::botMove(int& x, int& y)
{
    Console::showCursor(0);
    if (Cache.size() == 1)
    {
        int dx[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
        int dy[] = { 0, 0, -1, 1, 1, -1, 1, -1 };
        int r = rand() % 8;
        while (!valid(x + dx[r], y + dy[r])) r = rand() % 4;
        x += dx[r];
        y += dy[r];
    }
    else minimax(maxDepth = (Neighbor.size() <= 110 ? 3 : 2), (long long)-1e11, (long long)1e11, -1, x, y);
    if (status[x][y].opt != 0)
    {
        int dx[] = { -1, 1, 0, 0, -1, 1, 1, -1 };
        int dy[] = { 0, 0, -1, 1, 1, -1, 1, -1 };
        int r = rand() % 8;
        while (!valid(x + dx[r], y + dy[r]) && status[x][y].opt != 0) r = rand() % 4;
        x += dx[r];
        y += dy[r];
    }
    Console::showCursor(1);
}

void Game::addNeighbor(int x, int y)
{
    if (Neighbor.count({ x, y })) Neighbor.erase({ x, y });
    int radius = 3;

    int Upx = x - radius, Upy = y - radius, Lowx = x + radius, Lowy = y + radius;
    for (int i = Upx; i <= Lowx; i++)
        for (int j = Upy; j <= Lowy; j++)
        {
            if (valid(i, j) && status[i][j].opt == 0)
                Neighbor.insert({ i, j });
        }
}

void Game::makeMove(int Turn, int x, int y)
{
    status[x][y].opt = Turn;
    
    moveTo(x, y);
    
    if (Turn == 1)
    {
        Console::setColor(15, 4);
        cout << 'X';
    }
    else if(Turn == -1)
    {
        Console::setColor(15, 1);
        cout << 'O';
    }
    else
    {
        Console::setColor(15, 15);
        cout << " ";
    }
    moveTo(x, y);
}

void Game::updateNeighbor()
{
    Neighbor.clear();
    for(int i = 1; i <= BOARD_SIZE; i++)
        for(int j = 1; j <= BOARD_SIZE; j++)
            if (status[i][j].opt != 0) addNeighbor(i, j);
}

void Game::displayWinLine(int XX, int YY)
{
#define getVal(i) status[winLine[i].F][winLine[i].S].opt
    
    for (int i = 0; i < winLine.size(); i++)
    {
        if (abs(getVal(i)) == 1) 
        {
            int j = i;
            while (j + 1 < (int)winLine.size() - 1 && getVal(i) == getVal(j + 1)) j++;
            int len = j - i + 1;
            if (len >= 5)
            {
                for (int T = 0; T < 3; T++)
                {
                    for (int k = i; k <= j; k++)
                    {
                        int scrX = status[winLine[k].F][winLine[k].S].X;
                        int scrY = status[winLine[k].F][winLine[k].S].Y;
                        Console::gotoXY(scrX - 1, scrY);
                        Console::setColor(getVal(k) == 1 ? 4 : 1, 15);
                        cout << " " << (getVal(k) == 1 ? 'X' : 'O') << " ";
                    }
                    Sleep(500);
                    for (int k = i; k <= j; k++)
                    {
                        int scrX = status[winLine[k].F][winLine[k].S].X;
                        int scrY = status[winLine[k].F][winLine[k].S].Y;
                        Console::gotoXY(scrX - 1, scrY);
                        Console::setColor(15, getVal(k) == 1 ? 4 : 1);
                        cout << " " << (getVal(k) == 1 ? 'X' : 'O') << " ";
                    }
                    Sleep(300);
                }
                return;
            }
        }
    }
}

void Game::startGame(bool vsBot, bool isNewGame, int XX, int YY, string name1, string name2, vector<ii> Data, string fileName, int Xscore, int Oscore)
{
    playAgain:
    srand(time(0));
    system("cls");
    
    int x, y;
    Cache.clear();
    Console::showCursor(1);

    // NOTE: This drawBoard call needs to initialize status[i][j].X/Y/opt.
    // We pass *this to Graphics.
    // However, the original code relied on drawBoard updating the global status array.
    // We need to pass our status array to drawBoard or let Graphics update it.
    // Refactoring: Graphics should probably take Game&
    drawBoard(XX, YY, name1, name2, Xscore, Oscore, fileName, *this);

    if (isNewGame)
    {
        Turn = 1;
        x = 8, y = 8;
        moveTo(x, y);
    } else {
        Turn = 1;
        for (ii tmp : Data) {
            makeMove(Turn, tmp.F, tmp.S);
            Turn *= -1;
        } 
        
        Cache = Data;
        if (Data.empty()) x = y = 8;
        else {
            x = Data.back().F;
            y = Data.back().S;
        }
    }

    while (abs(evaluation(1)) < 1e8)
    {
        updateNeighbor();
        if (Turn == 1) {
            drawX(XX - 24 + 4 * BOARD_SIZE, YY + 3, 4);
            drawO(XX - 25 + 4 * BOARD_SIZE, YY + 18, 8);
        } else {
            drawO(XX - 25 + 4 * BOARD_SIZE, YY + 18, 1);
            drawX(XX - 24 + 4 * BOARD_SIZE, YY + 3, 8);
        } moveTo(x, y);

        if (Turn == -1 && vsBot) botMove(x, y);
        else
        {
            while (true)
            {
                int Key = Console::nextMove();
                if (Key == 0 && status[x][y].opt == 0) break; 
                if (Key == 1 && x > 1) x -= 1;
                if (Key == 2 && y > 1) y -= 1;
                if (Key == 3 && x < BOARD_SIZE) x += 1;
                if (Key == 4 && y < BOARD_SIZE) y += 1;
                if (Key == 5) { // exit game
                    drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 4);
                    while (true) {
                        char key = _getch();
                        if (key == 'N' || key == 'n') break;
                        else if (key == 'Y' || key == 'y') return;
                    } drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
                }
                if (Key == 6) // Undo
                {
                    for (int i = 0; i < (vsBot ? 2 : 1); i++) if(!Cache.empty())
                    {
                        x = Cache.back().F;
                        y = Cache.back().S;
                        Cache.pop_back();
                        makeMove(0, x, y);
                        Turn *= -1;
                        if (Turn == 1) {
                            drawX(XX - 24 + 4 * BOARD_SIZE, YY + 3, 4);
                            drawO(XX - 25 + 4 * BOARD_SIZE, YY + 18, 8);
                        }
                        else {
                            drawO(XX - 25 + 4 * BOARD_SIZE, YY + 18, 1);
                            drawX(XX - 24 + 4 * BOARD_SIZE, YY + 3, 8);
                        } moveTo(x, y);
                    }
                }
                if (Key == 7) { // save game
                    saveGame(XX, YY, Cache, Xscore, Oscore, name1, name2, fileName, vsBot);
                }
                moveTo(x, y);
            }
        }
        Cache.push_back({ x, y });
        makeMove(Turn, x, y);
        Turn *= -1;
        
        if (Cache.size() == BOARD_SIZE * BOARD_SIZE) {
            Turn = 0;
            break;
        }
    }

    Console::showCursor(0);
    displayWinLine(XX, YY);

    drawPopUp(XX - 27, YY + 3, 16, 74);
    Console::drawImage(XX - 24, YY + 3, "pixel_art/cup.txt"); // Note: capitalization might differ
    if (Turn == -1)
        drawX_WIN(XX + 6, YY + 7), Xscore++;    // X Wins
    else if(Turn == 1) 
        drawO_WIN(XX + 6, YY + 7), Oscore++;    // O Wins
    else drawDRAW(XX + 7, YY + 7);              // Draw

    Console::gotoXY(XX + 5 - (Turn == -1), YY + 13);
    for (int i = 0; i < 38; ++i)
        cout << char(196);

    Console::gotoXY(XX + 5 - (Turn == -1), YY + 14);
    Console::setColor(15, 8);  cout << "<< Press Y to continue or N to exit >>";
    Console::setColor(15, 0);
    
    // Check player want to play again
    while (true) {
        char key = _getch();
        if (key == 'N' || key == 'n') break;
        else if (key == 'Y' || key == 'y') {
            isNewGame = 1;
            goto playAgain;
        }
    }
}
