#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
#include "Newgame.h"
#include "LoadGame.h"

#define co_theme 15, 0
using namespace std;

void startGame() {
	system("cls");
	resetData(0, 0);
	drawBoard(0, 0);
}

// Menu
void newGame(int XX,int YY ) {
	drawNewGameMenu(XX, YY);	
}


void about() {
	system("cls");
	drawABOUT(36, 3);
	
	setColor(co_theme);
	int XX = 40, YY = 13;

	drawBoardSize(XX - 4, YY - 2, 17, 43);
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

	//drawD(10, 10);
	_getch();

	return 0;
}


