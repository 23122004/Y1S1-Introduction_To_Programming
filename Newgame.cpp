#include "Newgame.h"
#include "GameControl.h"
using namespace std;

bool putname(int XX, int YY, string &str) {  // Insert name
	setColor(15, 0);
	string tmp = str;
	str = "";

	while (true) {
		char ch = _getch();

		if (ch == 13) break;  // if "enter" then exit

		if (ch == 27) return 0;  // if "esc" then back to menu

		if (ch == '\b' && (int)str.size()) {  // nếu là ký tự backspace thì xóa
			str.pop_back();
			--XX; gotoXY(XX, YY); cout << " ";

		} else if ((int)str.size() < 10) {  // giới hạn 10 ký tự
			str.push_back(ch);
			gotoXY(XX, YY);
			cout << ch; ++XX;
		}
	} 
	
	if (!(int)str.size()) {
		str = tmp;
		gotoXY(XX, YY);
		cout << str;
	} return 1;
}
	
void player2(int XX, int YY) {
	system("cls"); drawNEW_GAME(XX - 20, YY - 9);
	string name1, name2;

	drawBoardMenu(XX, YY, 29, 15, " NAME PLAYER 1: ");
	if (!putname(XX + 17, YY + 1, name1 = "[player1]")) return;

	drawBoardMenu(XX, YY + 3, 29, 15, " NAME PLAYER 2: ");
	if (!putname(XX + 17, YY + 4, name2 = "[player2]")) return;
	startGame(false, true);

	resetData(0, 0);
	startGame(false, XX + 3, YY);
}

void player1(int XX, int YY) {
	system("cls"); drawNEW_GAME(XX - 21, YY - 9);
	string name;

	drawBoardMenu(XX, YY, 27, 15, " NAME PLAYER:   ");
	if (!putname(XX + 15, YY + 1, name = "[player]")) return;
	startGame(true, true);

	resetData(0, 0);
	startGame(true, XX + 2, YY);
}
	
void drawNewGameMenu(int XX, int YY) {
	struct _aboutMenu1 {
		int X1, Y1, size1, b_color1;
		string str1;

		void draw() {
			drawBoardMenu(X1, Y1, size1, b_color1, str1);
		}
	};

	_aboutMenu1 s1[2], s2[2];  // s1: phông thường, s2: phông highlight
	s1[0] = { XX, YY, 20, 15, "     1 PLAYER     " };
	s1[1] = { XX, YY + 3, 20, 15, "     2 PLAYERS    " };

	s2[0] = { XX, YY, 20, 14, ">>   1 PLAYER   <<" };
	s2[1] = { XX, YY + 3, 20, 14, ">>   2 PLAYERS  <<" };

	system("cls");
	int S = 0;  // Con trỏ hiển thị mục đang chọn

	while (true) {
		drawNEW_GAME(XX - 23, YY - 9);
		for (int i = 0; i < 2; ++i)
			s1[i].draw();
		s2[S].draw();

		int _in1 = nextMove();
		if (_in1 == 1 || _in1 == 3) S ^= 1;
		else if (_in1 == 0) {
			if (S == 0) player1(XX - 2, YY);
			else if (S == 1) player2(XX - 3, YY);
			else assert(false);
			break;
		} else if (_in1 == 5)
			break;
	}
}



