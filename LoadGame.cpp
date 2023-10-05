#include "LoadGame.h"


void loadGame() {
	system("cls");
	cout << "TEST";
	drawLOADGAME(18, 3);


	while (true) {
		if (nextMove() == 5)
			return;
	}
}