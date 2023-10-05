#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
using namespace std;
	
void player1() {}
void player2() {}
	
void drawNewGameMenu(int XX, int YY) {
	struct _aboutMenu1 {
		int X1, Y1, size1, b_color1;
		string str1;

		void draw() {
			drawBoardMenu(X1, Y1, size1, b_color1, str1);
		}
	};

	_aboutMenu1 s1[2], s2[2];  // s3: phông thường, s4: phông highlight
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
		if (_in1 == 1) S = (S + 2) % 3;
		else if (_in1 == 3) S = (S + 1) % 3;
		else if (_in1 == 0) {
			if (S == 0) player1();
			else if (S == 1) player2();
			else assert(false);
			break;
		} else if (_in1 == 5)
			break;
	}
}



