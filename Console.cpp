#include "Console.h"

void fixConsoleWindow(int WIDTH, int HEIGHT) {  // Cố định màn hình console
	system("COLOR f0");
	HWND consoleWindow = GetConsoleWindow();

	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	SMALL_RECT r;
	r.Top = r.Left = 0;
	r.Right = WIDTH;
	r.Bottom = HEIGHT;

	COORD NewSize;
	NewSize.X = WIDTH;
	NewSize.Y = HEIGHT;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleWindowInfo(Handle, TRUE, &r);
	SetConsoleScreenBufferSize(Handle, NewSize);
	ShowScrollBar(consoleWindow, SB_BOTH, 0);
}

void gotoXY(int x, int y) { // Di chuyển con trỏ đến vị trí (y, x)
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int background_color, int text_color) { // Chỉnh màu của con trỏ, background là màu nền, text là màu chữ
	HANDLE hconsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color_code = background_color * 16 + text_color;
	SetConsoleTextAttribute(hconsole, color_code);
}

void draw_square(int i, int j, int x, int y, int color)
{
	x = (x - 1) * 2 + 1;
	gotoXY(x + i, y + j);
	setColor(color, color);
	cout << "  ";
	setColor(15, 15);
}

void decorate_draw(int x, int y, const string& nameFile)
{
	ifstream file(nameFile.c_str());
	string s;
	int i = 0;
	while (getline(file, s))
	{
		i++;
		stringstream ss(s);
		int j = 0;
		while (!ss.eof())
		{
			j++;
			int color;
			ss >> color;
			draw_square(x, y, j, i, color);
		}
	}
}
void ShowCur(bool CursorVisibility) {  // Ẩn hiện con trỏ; 0: ẩn, 1: hiện
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
	SetConsoleCursorInfo(handle, &cursor);
}

void curr_coordinate(int& x, int& y) // lấy vị trí hiện tại của con trỏ
{
	CONSOLE_SCREEN_BUFFER_INFO curr;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curr);
	x = curr.dwCursorPosition.X;
	y = curr.dwCursorPosition.Y;
}

int nextMove() {  // Nhận các thao tác chức năng cơ bản
	while (true) {
		if (_kbhit()) {
			char c = _getch();

			if (c == 13 || c == ' ') return 0;
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