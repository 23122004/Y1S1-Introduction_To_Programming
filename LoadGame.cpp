#include "LoadGame.h"
#include "Graphic.h"


void loadGame() {
	system("cls");
	cout << "TEST";
	drawLOADGAME(18, 3);


	while (nextMove() != 5); // press ESC to exit
}