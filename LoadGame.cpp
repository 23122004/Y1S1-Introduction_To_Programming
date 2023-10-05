#include "LoadGame.h"
#include "Graphic.h"


void loadGame() {
	system("cls");
	drawLOADGAME(18, 3);

	while (nextMove() != 5); // press ESC to exit
}