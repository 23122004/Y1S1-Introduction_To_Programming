#include <Windows.h>
#include <conio.h>
#include "library.h"
#include "GameControl.h"
using namespace std;

cout << "hihi";
// Console
void fixConsoleWindow(int WIDTH, int HEIGHT) {
	HWND consoleWindow = GetConsoleWindow();
	system("COLOR f0");

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	RECT r;
	GetWindowRect(consoleWindow, &r);
	MoveWindow(consoleWindow, 0, 0, WIDTH, HEIGHT, TRUE);
}

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int background_color, int text_color) {
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = background_color * 16 + text_color;
	SetConsoleTextAttribute(hconsole, color_code);
}

void ShowCur(bool CursorVisibility)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

// Control
int nextMove() {
	while (true) {
		if (_kbhit()) {
			char c = _getch();

			if (c == 13) return 0;
			if (c == 27) return 5;

			if (c == -32) {
				c = _getch();

				if (c == 72) return 1;
				if (c == 75) return 2;
				if (c == 80) return 3;
				if (c == 77) return 4;
			}

			if (c == 'W' || c == 'w') return 1;
			if (c == 'A' || c == 'a') return 2;
			if (c == 'S' || c == 's') return 3;
			if (c == 'D' || c == 'd') return 4;

			if (c == 'U' || c == 'u') return 6;
			if (c == 'I' || c == 'i') return 7;
		} 
	}
}
const int BOARD_SIZE = 12;
// DrawBoard
void drawBoard(int startX, int startY) {
	setColor(15, 0);
	for (int y = 0; y <= 2 * BOARD_SIZE; ++y) {
		for (int x = 0; x <= 4 * BOARD_SIZE; ++x) {
			gotoXY(startX + x, startY + y);

			if (x == 0 && y == 0) cout << char(218);
			else if (x == 0 && y == 2 * BOARD_SIZE) cout << char(192);
			else if (x == 4 * BOARD_SIZE && y == 0) cout << char(191);
			else if (x == 4 * BOARD_SIZE && y == 2 * BOARD_SIZE) cout << char(217);

			else if (x % 4 == 0 && y == 0) cout << char(194);
			else if (x % 4 == 0 && y == 2 * BOARD_SIZE) cout << char(193);
			else if (x == 0 && y % 2 == 0) cout << char(195);
			else if (x == 4 * BOARD_SIZE && y % 2 == 0) cout << char(180);

			else if (x % 4 == 0 && y % 2 == 0) cout << char(197);
			else if (x % 4 == 0) cout << char(179);
			else if (y % 2 == 0) cout << char(196);
			else cout << " ";
		} cout << "\n";
	}	
}

void startGame() {
	system("cls");
	resetData(0, 0);
	drawBoard(0, 0);
}

// Menu
void newGame() {

}

void loadGame() {

}

void about() {

}

void help() {

}

void exit() {
	system("cls");
	exit(0);
}

// Graphic
void drawC(int XX, int YY) { // 6 * 8
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX, YY + 1); 
	setColor(0, 0);  cout << "  ";
	setColor(15, 0); 
		cout << char(201);
		for (int i = 1; i <= 4; ++i) cout << char(205);
		cout << char(188);

	gotoXY(XX, YY + 2);
	setColor(0, 0);  cout << "  ";
	setColor(15, 0); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0);  cout << "  ";
	setColor(15, 0); cout << char(186);

	gotoXY(XX, YY + 4);
		cout << char(200);
	setColor(0, 0);  cout << "      ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX + 1, YY + 5);
		cout << char(200);
		for (int i = 1; i <= 5; ++i) cout << char(205);
		cout << char(188);
}

void drawA(int XX, int YY) { // 6 * 8
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "     ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(15, 0); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawR(int XX, int YY) {
	gotoXY(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(15, 0); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawO(int XX, int YY) {
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(201) << char(205) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(15, 0); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(15, 0); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
		cout << char(200);
		for (int i = 1; i <= 5; ++i) cout << char(205);
		cout << char(188);
}

void drawCARO(int XX, int YY) {
	drawC(XX, YY);
	drawA(XX + 8, YY);
	drawR(XX + 16, YY);
	drawO(XX + 24, YY);
}

void drawBoardMenu(int XX, int YY, int size, int b_color, string str) { // size * 3
	setColor(15, 0);

	gotoXY(XX, YY); cout << char(201);
	for (int i = 0; i < size - 2; ++i) cout << char(205);
	cout << char(187);

	gotoXY(XX, YY + 1); cout << char(186);
	gotoXY(XX + size - 1, YY + 1); cout << char(186);

	gotoXY(XX, YY + 2); cout << char(200);
	for (int i = 0; i < size - 2; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX + 1, YY + 1);
	setColor(b_color, 0);  cout << str;
	setColor(15, 0);
}

void drawMenu(int XX, int YY) { 
	/*
		drawBoardMenu(XX, YY, 20, 15, "NEW GAME");
		drawBoardMenu(XX, YY + 3, 20, 15, "LOAD GAME");
		drawBoardMenu(XX, YY + 6, 20, 15, "ABOUT");
		drawBoardMenu(XX, YY + 9, 20, 15, "HELP");
		drawBoardMenu(XX, YY + 12, 20, 15, "EXIT");

		drawBoardMenu(XX, YY, 20, 14, ">>   NEW GAME   <<");
		drawBoardMenu(XX, YY + 3, 20, 14, ">>   LOAD GAME  <<");
		drawBoardMenu(XX, YY + 6, 20, 14, ">>     ABOUT    <<");
		drawBoardMenu(XX, YY + 9, 20, 14, ">>     HELP     <<");
		drawBoardMenu(XX, YY + 12, 20, 14, ">>     EXIT     <<");
	*/

	struct _aboutMenu {
		int X, Y, size, b_color;
		string str;

		void draw() {
			drawBoardMenu(X, Y, size, b_color, str);
		}
	};
	
	_aboutMenu s1[5], s2[5];
	s1[0] = { XX, YY, 20, 15, "     NEW GAME     " };
	s1[1] = { XX, YY + 3, 20, 15, "     LOAD GAME    " };
	s1[2] = { XX, YY + 6, 20, 15, "       ABOUT      " };
	s1[3] = { XX, YY + 9, 20, 15, "       HELP       " };
	s1[4] = { XX, YY + 12, 20, 15, "       EXIT       " };

	s2[0] = { XX, YY, 20, 14, ">>   NEW GAME   <<" };
	s2[1] = { XX, YY + 3, 20, 14, ">>   LOAD GAME  <<"};
	s2[2] = { XX, YY + 6, 20, 14, ">>     ABOUT    <<"};
	s2[3] = { XX, YY + 9, 20, 14, ">>     HELP     <<" };
	s2[4] = { XX, YY + 12, 20, 14, ">>     EXIT     <<" };
	
	int S = 0;
	while (true) {
		for (int i = 0; i < 5; ++i)
			s1[i].draw();
		s2[S].draw();

		int _in = nextMove();
		if (_in == 1) S = (S + 4) % 5;
		else if (_in == 3) S = (S + 1) % 5;
		else if (_in == 0) {
			if (S == 0) newGame();
			else if (S == 1) loadGame();
			else if (S == 2) about();
			else if (S == 3) help();
			else if (S == 4) exit();
			else assert(false);
		}
	}

}

// Main
int32_t main() {
	fixConsoleWindow(1100, 710);

	ShowCur(0);
	drawCARO(40, 3);
	drawMenu(46, 12);

	//drawBoard(5, 5);

	_getch();

	return 0;
}

/*
		0 = Black          8 = Gray
		1 = Blue           9 = Light Blue
		2 = Green          10 = Light Green
		3 = Aqua           11 = Light Aqua
		4 = Red            12 = Light Red
		5 = Purple         13 = Light Purple
		6 = Yellow         14 = Light Yellow
		7 = White          15 = Bright White
*/

/*
		16 : ►
		17 : ◄
		30 : ▲
		31 : ▼
		28 : ∟
		179 : │
		180 : ┤
		191 : ┐
		192 : └
		193 : ┴
		194 : ┬
		195 : ├
		196 : ─
		197 : ┼
		217 : ┘
		218 : ┌
		186 : ║
		187 : ╗
		188 : ╝
		200 : ╚
		201 : ╔
		205 : ═
*/

/* 
		0: Enter
		1 : MoveUp
		2 : MoveLeft
		3 : MoveDown
		4 : MoveRight
		5 : Esc
		6 : Undo
		7 : Save
*/
