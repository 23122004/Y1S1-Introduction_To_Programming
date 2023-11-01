#include "Console.h"

void fixConsoleWindow(int WIDTH, int HEIGHT) {  // Cố định màn hình console
	system("COLOR f0");

	HWND console = GetConsoleWindow();

	// Lấy thông tin về màn hình
	RECT r;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &r, 0);
	int consoleWidth = r.right / 2 - WIDTH / 2;
	int consoleHeight = r.bottom / 2 - HEIGHT / 2;

	// Di chuyển cửa sổ console đến vị trí mới
	MoveWindow(console, consoleWidth, consoleHeight, WIDTH, HEIGHT, TRUE);

	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, WIDTH, HEIGHT, TRUE);

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(consoleHandle, &info);
	COORD new_size = {
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(consoleHandle, new_size);
	HWND consoleWindow = GetConsoleWindow();
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