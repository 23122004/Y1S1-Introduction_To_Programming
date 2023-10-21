#include "LoadGame.h"
#include "GameControl.h"
#include "Newgame.h"
#include "Graphic.h"


// vector fileNames include name of files that save the game
// each fileName have some particular information : 
// First line : turn, lastX, lastY
//       next : 2-dimensional matrix a
vector<string> fileNames;

void loadGame(int XX, int YY) {
	// new screen LoadGame
	system("cls");
	drawLOAD_GAME(XX - 26, YY - 9);
	drawBoard(XX - 41, YY + 8, "player1", "player2");

	fileNames.push_back("game1.txt");
	fileNames.push_back("game2.txt");
	fileNames.push_back("game3.txt");

	string Current_game = "game1.txt";
	
	CurrentGame(Current_game, 15, 20, 0);
	
	int index = 0;
	int move = 0;
	while ((move = nextMove()) != 5) {
		if (move == 1) {
			Current_game = fileNames[index];
			index = (index + 1) % fileNames.size();
			CurrentGame(Current_game, 15, 20, index);
			//check again 
			gotoXY(70, 20);
			cout << index ;
			gotoXY(70, 22);
			cout << fileNames[index];
			//
		}
		if (move == 3) {
			Current_game = fileNames[index];
			index = (fileNames.size() + index - 1) % fileNames.size();
			CurrentGame(Current_game, 15, 20, index);
			//check again 
			gotoXY(70, 20);
			cout << index;
			gotoXY(70, 22);
			cout << fileNames[index];
			//
		}
	}
	// press ESC to exit
}


void CurrentGame(string filename, int XX, int YY, int index_file_name) {
	//load filegame to a[i][j]
	int turn = 0, lastX = 0, lastY = 0;
	const int BOARD_SIZE_loadgame = 15;

	ifstream file(filename);

	// Read first line
	file >> turn;
	file >> lastX;
	file >> lastY;

	// Create // Dynamic allocation of 2-dimensional matrix a
	int** a = new int* [BOARD_SIZE_loadgame + 2];
	for (int i = 0; i < BOARD_SIZE_loadgame + 2; i++) {
		a[i] = new int[BOARD_SIZE_loadgame + 2];
	}

	// file >> matrix a
	for (int i = 1; i <= BOARD_SIZE_loadgame; i++) {
		for (int j = 1; j <= BOARD_SIZE_loadgame; j++) {
			file >> a[i][j];
		}
	}

	drawBoardWithValues(XX, YY, a);
	drawNameOfGame(90, 20, index_file_name);
	for (int i = 1; i <= BOARD_SIZE_loadgame; i++) {
		delete[] a[i];
	}
	delete[] a;
}


void drawNameOfGame(int XX, int YY, int index_file_name) {
	gotoXY(XX, YY);
	cout << fileNames[index_file_name];
}


void drawBoardWithValues(int XX, int YY, int** a) {
	// Assuming a[][] is a 2D array of size BOARD_SIZE_loadgame x BOARD_SIZE_loadgame (= 12)

	const int BOARD_SIZE_loadgame = 15;
	int cellWidth = 4;
	int cellHeight = 2;

	for (int i = 1; i <= BOARD_SIZE_loadgame; ++i) {
		for (int j = 1; j <= BOARD_SIZE_loadgame; ++j) {
			int centerX = XX + j * cellWidth + cellWidth / 2 - 4;
			int centerY = YY + i * cellHeight + cellHeight / 2 - 2;

			gotoXY(centerX, centerY);

			if (a[i][j] == 1) {
				setColor(15, 4);
				cout << 'X';  // Draw 'x' if a[i][j] is 1
			}
			else if (a[i][j] == -1) {
				setColor(15, 1);
				cout << 'O';  // Draw 'o' if a[i][j] is -1
			}
			else {
				cout << ' ';  // Draw '.' if a[i][j] is 0
			}
		}
	}
}



// OVERWRITE A NEW FILEGAME

// Step 1 :: Add new file game to DataBase (.txt)

void Add_NewFile_to_vector_fileNames(string fileName) {
	fileName += ".txt";
	fileNames.push_back(fileName);
	return;
}


// Step 2 :: Write history game to file : file name of game, matrix a, turn, lastX, lastY, BOARD_SIZE
void Overwrite_information_to_file(const std::string& fileName_with_txt, int** a, int turn, int lastX, int lastY, int BOARD_SIZE = 15) {
	std::ofstream file(fileName_with_txt, std::ios::trunc); // Open and Delete data of file.
	if (file.is_open()) {

		// WRITE turn, lastX, lastY into first line
		file << turn << " " << lastX << " " << lastY << '\n';

		// write matrix a into next lines
		for (int i = 1; i <= BOARD_SIZE; i++) {
			for (int j = 1; j <= BOARD_SIZE; j++) {
				file << a[i][j] << " ";
			}
			file << '\n';
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
	int** a = new int* [BOARD_SIZE_loadgame + 1];
	for (int i = 1; i <= BOARD_SIZE_loadgame; i++) {
		a[i] = new int[BOARD_SIZE_loadgame + 1];
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
