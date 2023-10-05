#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
using namespace std;
    //dienten 
void putname(int XX, int YY, string  &a) 
{
	char ch = '`';
	

	while (1)
	{
		int x, y;
		ch = _getch();
		if (ch == 13 || ch == 10) // kiểm tra nếu nhấn enter thì dừng
		{
			cout<<"\n";
			break;
		}
		if (ch == '\b' && a.size()) // nếu là ký tự backspace thì xóa
		{
			a.pop_back();
			curr_coordinate(x, y);
			x--;
			gotoXY(XX , YY);
			cout << " ";
			curr_coordinate(x, y);
			x--;
			gotoXY(XX, YY);
		}
		else if (a.size() < 10) // giới hạn 10 ký tự
		{
			a.push_back(ch);
			cout << ch;
		}
	}
	cout << a; // a hiện tại là tên
	
}
	
	//dientenhainguoichoi
    void player2(int XX, int YY)
	{
		system("cls");
		string nameplayer1; 
	    drawBoardMenu(XX, YY, 20, 15, "NAME PLAYER 1: ");
		drawBoardMenu(XX, YY, 25, 14, ">>NAME PLAYER 1: << ");
		int X_1 = XX + 14; //toa do ten nguoi dung 
			putname(X_1, YY, nameplayer1);
		string nameplayer2;
		drawBoardMenu(XX, YY+ 3 , 20, 15, "NAME PLAYER 2: ");
		drawBoardMenu(XX, YY + 3 , 20, 14, ">>NAME PLAYER 2: << ");
		putname(X_1, YY , nameplayer2);
		

	}
	void player1() {}
	void home() {}
	
	void drawNewGameMenu(int XX, int YY) {
		system("cls");
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
				if (S1 == 0) player2(XX,YY);
				else if (S1 == 1) player1();
				else if (S1 == 2) home();
				else assert(false);
				system("cls");
			}
		}
	}



