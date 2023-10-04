#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
using namespace std;

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
int32_t main() {
	fixConsoleWindow(1100, 710);

	ShowCur(0);
	drawCARO(40, 3);
	drawMenu(46, 12);

	//drawBoard(5, 5);

	_getch();

	return 0;
}


