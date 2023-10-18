#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
#include "Newgame.h"
#include "LoadGame.h"

#define co_theme 15, 0
using namespace std;

// Menu
void newGame(int XX,int YY ) {
	drawNewGameMenu(XX, YY);	
}

void about() {
	system("cls");
	drawABOUT(36, 3);
	int XX = 40, YY = 13;

	drawPopUp(XX - 9, YY - 2, 17, 52);
	gotoXY(XX, YY);      cout << "HCMUS - 23TNT1 - Group 5:";
	gotoXY(XX, YY + 2);  cout << "   23122001 - Dinh Duc Anh Khoa";
	gotoXY(XX, YY + 4);  cout << "   23122002 - Nguyen Dinh Ha Duong";
	gotoXY(XX, YY + 6);  cout << "   23122013 - Dinh Duc Tai";
	gotoXY(XX, YY + 8);  cout << "   23122004 - Nguyen Le Hoang Trung";
	gotoXY(XX, YY + 10); cout << "Advisor: Dr.Truong Toan Thinh";

	setColor(14, 0);
	gotoXY(XX + 6, YY + 12); cout << "<< Press ESC to exit >>";
	setColor(co_theme);

	while (nextMove() != 5);
}

void help() {
	system("cls");
	drawHELP(41, 3);

	int XX = 19, YY = 11;
	int h = 16, w = 76;

	drawPopUp(XX, YY, h, w);
	setColor(co_theme);
	for (int i = 1; i < h - 4; ++i) {
		gotoXY(XX + 37, YY + i); 
		cout << "|";
	}

	setColor(11, 0);
	gotoXY(XX + 12, YY + 1);
	cout << "KEYBOARD GUIDE";

	gotoXY(XX + 53, YY + 1);
	cout << "RUDE";

	setColor(co_theme);
	gotoXY(XX + 14, YY + 3);
	cout << "Player 1    Player 2";
	gotoXY(XX + 3, YY + 4);
	cout << "Go up:        W           " << char(30);
	gotoXY(XX + 3, YY + 5);
	cout << "Go left:      A           " << char(17);
	gotoXY(XX + 3, YY + 6);
	cout << "Go down:      S           " << char(31);
	gotoXY(XX + 3, YY + 7);
	cout << "Go right:     D           " << char(16);
	gotoXY(XX + 3, YY + 8);
	cout << "Mark    :   Space       Enter";
	gotoXY(XX + 6, YY + 10);
	cout << "         Other";
	gotoXY(XX + 3, YY + 11);
	cout << "Undo: U    Save: I    Exit: Esc";

	gotoXY(XX + 39, YY + 3);
	cout << "  Players alternate turns putting";
	gotoXY(XX + 39, YY + 4);
	cout << "their marks on an empty intersection";
	gotoXY(XX + 39, YY + 5);
	cout << "  X plays first. The winner is the";
	gotoXY(XX + 39, YY + 6);
	cout << "  first player to form an unbroken";
	gotoXY(XX + 39, YY + 7);
	cout << "   line of 5 marks horizontally,";
	gotoXY(XX + 39, YY + 8);
	cout << " vertically, or diagonally. If the";
	gotoXY(XX + 39, YY + 9);
	cout << " board is completely filled and no";
	gotoXY(XX + 39, YY + 10);
	cout << "  one can make a line of 5 marks,";
	gotoXY(XX + 39, YY + 11);
	cout << "   then the game ends in a draw.";
	

	setColor(14, 0);
	gotoXY(XX + 27, YY + 13); cout << "<< Press ESC to exit >>";
	setColor(co_theme);

	while (nextMove() != 5);
}

void exit() {
	system("cls");
	exit(0);
}

// Main
void drawMenu(int XX, int YY) { 
	struct _aboutMenu {
		int X, Y, size, b_color;
		string str;

		void draw() {
			drawBoardMenu(X, Y, size, b_color, str);
		}
	};
	
	_aboutMenu s1[5], s2[5];  // s1: phông thường, s2: phông highlight
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
	
	int S = 0;  // Con trỏ hiển thị mục đang chọn
	while (true) {
		drawCARO(40, 3);
		for (int i = 0; i < 5; ++i)
			s1[i].draw();
		s2[S].draw();

		int _in = nextMove();
		if (_in == 1) S = (S + 4) % 5;
		else if (_in == 3) S = (S + 1) % 5;
		else if (_in == 0) {
			if (S == 0) newGame(XX,YY);
			else if (S == 1) loadGame();
			else if (S == 2) about();
			else if (S == 3) help();
			else if (S == 4) exit();
			else assert(false);
			system("cls");
		}
	}
}

int32_t main() {
	fixConsoleWindow(1100, 710);
	SetConsoleTitle(L"GameCaro - 23TNT1 - Group 5");

	ShowCur(0);
	drawMenu(46, 12);

	_getch();

	return 0;
}


