#include "Newgame.h"
using namespace std;

void startGame() {
	system("cls");
	resetData(0, 0);
	drawBoard(0, 0);


	_getch();
}

bool putname(int XX, int YY, string &str) {  // Insert name
	setColor(15, 0);
	while (true) {
		int x, y;
		char ch = _getch();

		if (ch == 13 && (int)str.size()) break;  // if "enter" then exit

		if (ch == 27) return 0;  // if "esc" then back to menu

		if (ch == '\b' && (int)str.size()) {  // nếu là ký tự backspace thì xóa
			str.pop_back();
			--XX; gotoXY(XX, YY); cout << " ";

		} else if ((int)str.size() < 8) {  // giới hạn 8 ký tự
			str.push_back(ch);
			gotoXY(XX, YY);
			cout << ch; ++XX;
		}
	} return 1;
}
	
void player2(int XX, int YY) {
	system("cls"); drawNEWGAME(25, 3);
	string name1, name2;

	drawBoardMenu(XX, YY, 27, 15, " NAME PLAYER 1: ");
	if (!putname(XX + 17, YY + 1, name1)) return;

	drawBoardMenu(XX, YY + 3, 27, 15, " NAME PLAYER 2: ");
	if (!putname(XX + 17, YY + 4, name2)) return;

	startGame();
}

void player1() {}
	
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
	s1[1] = { XX, YY + 3, 20, 15, "     2 PLAYER     " };

	s2[0] = { XX, YY, 20, 14, ">>   1 PLAYER   <<" };
	s2[1] = { XX, YY + 3, 20, 14, ">>   2 PLAYER  <<" };

	system("cls");
	int S = 0;  // Con trỏ hiển thị mục đang chọn

	while (true) {
		drawNEWGAME(23, 3);
		for (int i = 0; i < 2; ++i)
			s1[i].draw();
		s2[S].draw();

		int _in1 = nextMove();
		if (_in1 == 1 || _in1 == 3) S ^= 1;
		else if (_in1 == 0) {
			if (S == 0) player1();
			else if (S == 1) player2(XX - 2, YY);
			else assert(false);
			break;
		} else if (_in1 == 5)
			break;
	}
}



