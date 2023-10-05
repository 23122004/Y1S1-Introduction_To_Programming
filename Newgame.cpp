#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
using namespace std;
	
	void player2() {}
	void player1() {}
	void home() {}
	
	void drawNewGameMenu(int XX, int YY) {
		struct _aboutMenu1 {
			int X1, Y1, size1, b_color1;
			string str1;

			void draw() {
				drawBoardMenu(X1, Y1, size1, b_color1, str1);
			}
		};

		_aboutMenu1 s3[3], s4[3];  // s3: phông thường, s4: phông highlight
		s3[0] = { XX, YY, 20, 15, "     2 PLAYER     " };
		s3[1] = { XX, YY + 3, 20, 15, "     1 PLAYER     " };
		s3[2] = { XX, YY + 6, 20, 15, "       HOME      " };
		

		s4[0] = { XX, YY, 20, 14, ">>   2 PLAYER   <<" };
		s4[1] = { XX, YY + 3, 20, 14, ">>   1 PLAYER  <<" };
		s4[2] = { XX, YY + 6, 20, 14, ">>     HOME    <<" };
;

		int S1 = 0;  // Con trỏ hiển thị mục đang chọn
		while (true) {
			drawCARO(40, 3);
			for (int i = 0; i < 3; ++i)
				s3[i].draw();
			s4[S1].draw();

			int _in1 = nextMove();
			if (_in1 == 1) S1 = (S1 + 2) % 3;
			else if (_in1 == 3) S1 = (S1 + 1) % 3;
			else if (_in1 == 0) {
				if (S1 == 0) player2();
				else if (S1 == 1) player1();
				else if (S1 == 2) home();
				else assert(false);
				system("cls");
			}
		}
	}



