#include "library.h"
#include "Menu.h"
#include "Console.h"

using namespace std;

int32_t main() {
	fixConsoleWindow(140, 45);						  // Fix window size
	SetConsoleTitle(L"GameCaro - 23TNT1 - Group 5");  // Console's title

	ShowCur(0);
	drawMenu(61, 12);

	return 0;
}
