#ifndef _GAMECONTROL_H_
#define _GAMECONTROL_H_
#include "library.h"
using namespace std;

struct _Point 
{
	int X, Y, opt; // tọa độ x, y trên màn hình và opt = 1 nếu là x, opt = -1 nếu là o
};

long long consecutiveScore(int len, int openEnds, bool currentTurn);
long long get_score(int a[],int player);
bool valid(int x, int y); // tọa độ có hợp lệ hay không
long long evaluation(int player); // trả về điểm trạng thái
long long minimax(int depth, long long alpha, long long beta, int player, int& x, int& y); // thuật minimax
void resetData(int startX, int startY); // reset bảng
void botMove(int& x, int& y); // nước đi của bot
void playerMove(int& x, int& y, int turn); // nước đi của người chơi
void loadGameBoardUpdate(int** a, int turn, int lastX, int lastY); // cập nhật bảng hiện tại nếu load game
// sửa lại bằng mảng động hoặc vector đều được

#endif