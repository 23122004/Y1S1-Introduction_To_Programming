#include "LoadGame.h"
#include "GameControl.h"
#include "Newgame.h"
#include "Graphic.h"


void loadGame() {
	system("cls");
	drawLOADGAME(20, 3);

	while (nextMove() != 5); // press ESC to exit
}

// vector fileNames include name of files that save the game
// each fileName have some particular information : 
// First line : turn, lastX, lastY
//       next : 2-dimensional matrix a

vector<string> fileNames;

// OVERWRITE A NEW FILEGAME

// Step 1 :: Add new file game to DataBase (.txt)
void Add_NewFile_to_vector_fileNames(string fileName) {
	fileName += ".txt";
	fileNames.push_back(fileName);
	return;
}


// Step 2 :: Write history game to file : file name of game, matrix a, turn, lastX, lastY, BOARD_SIZE
void Overwrite_information_to_file(const std::string& fileName_with_txt, int** a, int turn, int lastX, int lastY, int BOARD_SIZE) {
	std::ofstream file(fileName_with_txt, std::ios::trunc); // Open and Delete data of file.
	if (file.is_open()) {

		// WRITE turn, lastX, lastY into first line
		file << turn << " " << lastX << " " << lastY << std::endl;

		// write matrix a into next lines
		for (int i = 1; i <= BOARD_SIZE; i++) {
			for (int j = 1; j <= BOARD_SIZE; j++) {
				file << a[i][j] << " ";
			}
			file << std::endl;
		}

		file.close();
	}
}



// LOAD GAME FROM FILE

void loadFromFile(string filename) {

	int turn = 0, lastX = 0, lastY = 0;
	const int BOARD_SIZE_loadgame = 12;

	ifstream file(filename);

	// Read first line
	file >> turn;
	file >> lastX;
	file >> lastY;

	// Create // Dynamic allocation of 2-dimensional matrix a
	int** a = new int*[BOARD_SIZE_loadgame];
	for (int i = 1; i <= BOARD_SIZE_loadgame; i++) {
		a[i] = new int[BOARD_SIZE_loadgame];
	}

	// file >> matrix a
	for (int i = 1; i <= BOARD_SIZE_loadgame; i++) {
		for (int j = 1; j <= BOARD_SIZE_loadgame; j++) {
			file >> a[i][j];
		}
	}

	// Load DATA from file =>> GameControl :: loadGameBoardUpdate
	loadGameBoardUpdate(a, turn, lastX, lastY);

	// Delete memory - 
	for (int i = 1; i <= BOARD_SIZE_loadgame + 2; i++) {
		delete[] a[i];
	}
	delete[] a;

}