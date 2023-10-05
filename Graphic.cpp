#include "Graphic.h"
#define co_theme 15,0
const int BOARD_SIZE = 12;

void drawA(int XX, int YY) { // 6 * 8
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "     ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "       ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawB(int XX, int YY) { // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);
	
	gotoXY(XX, YY + 2);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(0, 0); for (int i = 0; i < 6; ++i) cout << " ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 5);
	cout << char(200);
	for (int i = 0; i < 5; ++i) cout << char(205);
	cout << char(188);
}

void drawC(int XX, int YY) { // 6 * 8
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme);
	cout << char(201);
	for (int i = 1; i <= 4; ++i) cout << char(205);
	cout << char(188);

	gotoXY(XX, YY + 2);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0);  cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0);  cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawO(int XX, int YY) { // 6 * 9
	gotoXY(XX + 1, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawR(int XX, int YY) { // 6 * 8
	gotoXY(XX, YY);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(201) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 4);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "  ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 5);
	cout << char(200) << char(205) << char(188) << "  " << char(200) << char(205) << char(188);
}

void drawU(int XX, int YY) { // 6 * 9
	gotoXY(XX, YY);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 2);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 3);
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186) << "   ";
	setColor(0, 0); cout << "  ";
	setColor(co_theme); cout << char(186);

	gotoXY(XX, YY + 4);
	cout << char(200);
	setColor(0, 0); cout << "      ";
	setColor(co_theme); cout << char(201) << char(188);

	gotoXY(XX + 1, YY + 5);
	cout << char(200);
	for (int i = 1; i <= 5; ++i) cout << char(205);
	cout << char(188);
}

void drawT(int XX, int YY) { // 6 * 9
	gotoXY(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		gotoXY(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
}

void drawL(int XX, int YY) { 
	gotoXY(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		gotoXY(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
	cout << "chu L";

}

void drawD(int XX, int YY) {
	gotoXY(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		gotoXY(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
	cout << "chu D";
}

void drawG(int XX, int YY) {
	gotoXY(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		gotoXY(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
	cout << "chu G";
}

void drawM(int XX, int YY) {
	gotoXY(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		gotoXY(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
	cout << "chu M";
}

void drawE(int XX, int YY) {
	gotoXY(XX, YY);
	setColor(0, 0);  cout << "        ";
	setColor(co_theme); cout << char(187);

	gotoXY(XX, YY + 1);
	cout << char(200) << char(205) << char(205);
	setColor(0, 0); cout << "  ";
	setColor(co_theme);  cout << char(201) << char(205) << char(205) << char(188);

	for (int i = 0; i < 3; ++i) {
		gotoXY(XX + 3, YY + 2 + i);
		setColor(0, 0); cout << "  ";
		setColor(co_theme); cout << char(186);
	}

	gotoXY(XX + 3, YY + 5);
	cout << char(200) << char(205) << char(188);
	cout << "chu E";
}

void drawCARO(int XX, int YY) {
	drawC(XX, YY);
	drawA(XX + 8, YY);
	drawR(XX + 16, YY);
	drawO(XX + 24, YY);
}

void drawABOUT(int XX, int YY) {
	drawA(XX, YY);
	drawB(XX + 8, YY);
	drawO(XX + 16, YY);
	drawU(XX + 25, YY);
	drawT(XX + 34, YY);
}

void drawLOADGAME(int XX, int YY) {
	drawL(XX, YY);
	drawO(XX + 10, YY);
	drawA(XX + 20, YY);
	drawD(XX + 30, YY);
	drawG(XX + 45, YY);
	drawA(XX + 60, YY);
	drawM(XX + 70, YY);
	drawE(XX + 80, YY);
}

void drawBoardMenu(int XX, int YY, int size, int b_color, string str) { // size * 3
	setColor(co_theme);

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
	setColor(co_theme);
}

void drawBoard(int startX, int startY) {  // V? b?ng Caro 12 * 12
	setColor(co_theme);
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

void drawBoardSize(int XX, int YY, int h, int w) { // h * w, v? b?ng vi?n b?
	setColor(co_theme);

	gotoXY(XX, YY); cout << char(201);
	for (int i = 0; i < w - 2; ++i) cout << char(205);
	cout << char(187);

	for (int i = 1; i < h - 1; ++i) {
		gotoXY(XX, YY + i); cout << char(186);
		gotoXY(XX + w - 1, YY + i); cout << char(186);
	}

	gotoXY(XX, YY + h - 1); cout << char(200);
	for (int i = 0; i < w - 2; ++i) cout << char(205);
	cout << char(188);
}