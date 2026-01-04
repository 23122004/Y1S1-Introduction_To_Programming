#include "../include/library.h"
#include "../include/Menu.h"
#include "../include/Console.h"

using namespace std;

int32_t main() {
	Console::fixConsoleWindow(140, 45);						  // Fix window size
	SetConsoleTitle(L"GameCaro - 23TNT1 - Group 5");  // Console's title

	Console::showCursor(0);
	Menu::drawMenu(61, 12);

	return 0;
}
