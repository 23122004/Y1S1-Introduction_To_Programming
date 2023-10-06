#include "library.h"
#include "GameControl.h"
#include "Console.h"
#include "Graphic.h"
using namespace std;
    //dienten 
void play() {}
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
void player2(int XX, int YY, string nameplayer1, string nameplayer2)
{
	system("cls");
	drawBoardMenu(XX, YY, 23, 15, "NAME PLAYER 1:    ");
	int X_1 = XX + 14; //toa do ten nguoi dung 
	putname(X_1, YY, nameplayer1);
	drawBoardMenu(XX, YY + 3, 23, 15, "NAME PLAYER 2:      ");
	putname(X_1, YY, nameplayer2);
	while (true) {
		if (_kbhit()) {
			char c = _getch();

			if (c == 13) play();


		}
	}
}

	void player1() {}
	void home() {}
	
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
		string name1, name2; 
		while (true) {
			drawNEWGAME(XX, YY);
			for (int i = 0; i < 2; ++i)
				s1[i].draw();
			s2[S].draw();

		int _in1 = nextMove();
		if (_in1 == 1 || _in1 == 3) S ^= 1;
		else if (_in1 == 0) {
			if (S == 0) player1();
			else if (S == 1) player2();
			else assert(false);
			break;
		} else if (_in1 == 5)
			break;
	}
}



