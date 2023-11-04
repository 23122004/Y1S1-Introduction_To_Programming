#include "GameControl.h"
#include "Graphic.h"
#include "Newgame.h"
#include "LoadGame.h"

#define F first
#define S second
typedef pair<int, int> ii;
vector<ii> Cache;
set<ii> Neighbor;
const int BOARD_SIZE = 15;
_Point status[BOARD_SIZE + 5][BOARD_SIZE + 5];
int Turn;
int maxDepth = 3;
#define moveTo(x, y) gotoXY(status[x][y].X, status[x][y].Y)
vector<ii> winLine;

long long consecutiveScore(int len, int openEnds, bool currentTurn) // tính điểm
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

long long get_score(int a[], int player)
{
    int Size = BOARD_SIZE + 2;
    long long score = 0;
    for (int i = 1; i < Size - 1; i++) if (abs(a[i]) == 1) // đánh giá điểm
    {
        int j = i;
        while (j + 1 < Size - 1 && a[i] == a[j + 1]) j++;

        int len = j - i + 1;
        int openEnds = 2 - (a[i - 1] != 0) - (a[j + 1] != 0); // số ô mở hai bên
        score += 1ll * consecutiveScore(len, openEnds, player == a[i]) * a[i];
        i = j;
    }
    return score;
}

bool valid(int x, int y)
{
    return y > 0 && x > 0 && x <= BOARD_SIZE && y <= BOARD_SIZE;
}

long long evaluation(int player) // hàm đánh giá trạng thái
{
    long long score = 0;
    int* b = new int[BOARD_SIZE + 2];
    for (int i = 1; i <= BOARD_SIZE; i++) // đánh giá hàng ngang
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
            return score;
        }
    }

    for (int j = 1; j <= BOARD_SIZE; j++) // đánh giá hàng dọc
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
            return score;
        }
    }

    for (int i = 0; i <= BOARD_SIZE; i++) // đánh giá đường chéo chính
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
            return score;
        }
    }
    for (int j = 1; j <= BOARD_SIZE; j++) // đánh giá đường chéo chính
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
            return score;
        }
    }

    for (int i = 1; i <= BOARD_SIZE + 1; i++) // đánh giá đường chéo phụ
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
            return score;
        }
    }
    for (int j = 1; j <= BOARD_SIZE; j++) // đánh giá đường chéo phụ
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
            return score;
        }
    }
    return score;
}

long long minimax(int depth, long long alpha, long long beta, int player, int& x, int& y)
{
    long long val = evaluation(player); // tính trạng thái bàn cờ hiện tại nếu đến lượt người chơi "player"
    if (depth == 0 || abs(val) >= 1e8) // kiểm tra xuống độ sâu cuối cùng hoặc một trong hai thắng
        return val; // trả về đánh giá trạng thái

    // đặt cho người chơi (Max)
    if (player == 1)
    {
        long long maxEval = (long long)-1e11;
        vector<ii> a(Neighbor.begin(), Neighbor.end());
        for (const ii& tmp : a)
        {
            int i = tmp.F, j = tmp.S;
            if (status[i][j].opt == 0)
            {
                status[i][j].opt = 1; // đánh thử x vào ô i, j
                long long eval = minimax(depth - 1, alpha, beta, -1, x, y); // gọi đệ quy minimax
                status[i][j].opt = 0;
                if (maxEval < eval)
                {
                    maxEval = eval;
                    if (depth == maxDepth) x = i, y = j;
                }
                if (alpha < eval) alpha = eval;
                if (beta <= alpha) // alpha-beta pruning
                    break;
            }
        }
        return maxEval;
    }
    else // đặt cho máy tương tự như cho người chơi (Min)
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

void botMove(int& x, int& y) // đưa vào tọa độ cuối cùng của người chơi
// máy chơi trả về tham chiếu x, y là tọa độ vừa được đặt
{
    ShowCur(0);
    if (Cache.size() == 1) // nước đi đầu tiên của bot là random
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
    ShowCur(1);
    // bot mặc định là o
}

void addNeighbor(int x, int y)
{
    if (Neighbor.count({ x, y })) Neighbor.erase({ x, y });
    int radius = 3;
    int Upx = x - radius, Upy = y - radius, Lowx = x + radius, Lowy = y + radius;
    for (int i = Upx; i <= Lowx; i++)
        for (int j = Upy; j <= Lowy; j++)
            if (valid(i, j) && status[i][j].opt == 0)
                Neighbor.insert({ i, j });
}

void makeMove(int Turn, int x, int y)
{
    status[x][y].opt = Turn;
    
    moveTo(x, y);
    
    if (Turn == 1)
    {
        setColor(15, 4);
        cout << 'X';
    }
    else if(Turn == -1)
    {
        setColor(15, 1);
        cout << 'O';
    }
    else
    {
        setColor(15, 15);
        cout << " ";
    }
    moveTo(x, y);
}

void updateNeighbor() // thêm các tọa độ lân cận cho bot tính toán
{
    Neighbor.clear();
    for(int i = 1; i <= BOARD_SIZE; i++)
        for(int j = 1; j <= BOARD_SIZE; j++)
            if (status[i][j].opt != 0) addNeighbor(i, j);
    /*for (auto x : Neighbor)
    {
        moveTo(x.F, x.S);
        cout << '.';
    }*/
}

void displayWinLine() // nháy nháy chỗ thắng 
{
#define getVal(i) status[winLine[i].F][winLine[i].S].opt
    
    for (int i = 0; i < winLine.size(); i++)
    {
        if (abs(getVal(i)) == 1) 
        {
            int j = i;
            while (j + 1 < (int)winLine.size() - 1 && getVal(i) == getVal(j + 1)) j++;
            int len = j - i + 1;
            if (len >= 5) // nếu đủ 5 để thắng thì đi nháy nháy
            {
                for (int T = 0; T < 3; T++) // nháy 3 lần
                {
                    for (int k = i; k <= j; k++) // tô ký tự vàng 
                    {
                        int XX = status[winLine[k].F][winLine[k].S].X;
                        int YY = status[winLine[k].F][winLine[k].S].Y;
                        gotoXY(XX - 1, YY);
                        setColor(getVal(k) == 1 ? 4 : 1, 15);
                        cout << " " << (getVal(k) == 1 ? 'X' : 'O') << " ";
                    }
                    Sleep(500);
                    for (int k = i; k <= j; k++) // tô lại mặc định
                    {
                        int XX = status[winLine[k].F][winLine[k].S].X;
                        int YY = status[winLine[k].F][winLine[k].S].Y;
                        gotoXY(XX - 1, YY);
                        setColor(15, getVal(k) == 1 ? 4 : 1);
                        cout << " " << (getVal(k) == 1 ? 'X' : 'O') << " ";
                    }
                    Sleep(300);
                }
                return;
            }
        }
    }
}

void startGame(bool vsBot, bool isNewGame, int XX, int YY, string name1, string name2, vector<ii> Data, string fileName, int Xscore, int Oscore)
{
    playAgain:
    srand(time(0));
    system("cls");
    
    int x, y;
    Cache.clear();
    ShowCur(1);
    drawBoard(XX, YY, name1, name2, Xscore, Oscore, fileName);
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
                int Key = nextMove();
                if (Key == 0 && status[x][y].opt == 0) break; 
                if (Key == 1 && x > 1) x -= 1;
                if (Key == 2 && y > 1) y -= 1;
                if (Key == 3 && x < BOARD_SIZE) x += 1;
                if (Key == 4 && y < BOARD_SIZE) y += 1;
                if (Key == 5) {
                    drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 4);
                    while (true) {
                        char key = _getch();
                        if (key == 'N' || key == 'n') break;
                        else if (key == 'Y' || key == 'y') return;
                    } drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
                }
                if (Key == 6) // undo
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
                if (Key == 7) {
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

    ShowCur(0);
    displayWinLine(); // nháy nháy các thứ

    drawPopUp(XX - 14, YY + 5, 11, 49);
    if (Turn == -1)
        drawX_WIN(XX - 7, YY + 7), Xscore++;
    else if(Turn == 1) 
        drawO_WIN(XX - 7, YY + 7), Oscore++;
    else drawDRAW(XX - 6, YY + 7);

    gotoXY(XX - 8, YY + 14);
    setColor(15, 8);  cout << "<< Press Y to continue or N to exit >>";
    setColor(15, 0);
    
    while (true) {
        char key = _getch();
        if (key == 'N' || key == 'n') break;
        else if (key == 'Y' || key == 'y') {
            isNewGame = 1;
            goto playAgain;
        }
    }
}