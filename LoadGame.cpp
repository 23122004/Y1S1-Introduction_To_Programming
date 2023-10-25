#include "LoadGame.h"
#include "GameControl.h"
#include "Newgame.h"
#include "Graphic.h"
#include "library.h"
#define co_theme 15,0

// vector fileNames include name of files that save the game
// each fileName have some particular information : 
// First line : turn, lastX, lastY
//       next : 2-dimensional matrix a
vector<string> fileNames = { "day1" , "day2", "day1" , "day2", "day1" , "day2", "day1" , "day2", "day1" , "day2"};

void loadGame(int XX, int YY) {
	struct _aboutMenu {
		int X, Y, size, b_color;
		string str;

		void draw() {
			drawBoardMenu(X, Y, size, b_color, str);
		}
	};

	int sz = min((int)fileNames.size() - 1, 14);  // Con trỏ hiển thị mục đang chọn
	_aboutMenu s1[15], s2[15];  // s1: phông thường, s2: phông highlight
	for (int i = 0; i < 15; ++i) {
		s1[i] = { XX - 30 + 30 * (i / 5), YY + (i % 5) * 3, 20, 12, "      EMPTY       "};
		s2[i] = { XX - 30 + 30 * (i / 5), YY + (i % 5) * 3, 20, 14, "" };
		
		if (i <= sz) {
			string tmp = fileNames[i];
			int siz = 14 - (int)tmp.size();

			for (int j = 1; 2 * j <= siz; ++j)
				tmp = ' ' + tmp + ' ';
			if (siz & 1) tmp += ' ';

			s1[i].str = "  " + tmp + "  ";
			s2[i].str = ">>" + tmp + "<<";
			s1[i].b_color = 15;
		}
	}

	system("cls");
	drawLOAD_GAME(XX - 26, YY - 9);
	drawPopUp(XX - 33, YY - 1, 20, 86);

	int S = min(0, sz);
	while (true) {
		for (int i = 0; i < 15; ++i)
			s1[i].draw();
		if (S != -1) s2[S].draw();

		setColor(co_theme);
		gotoXY(XX - 29, YY + 15); cout << "                                                                               ";
		gotoXY(XX - 29, YY + 16); cout << "                                                                               ";
		gotoXY(XX - 29, YY + 17); cout << "                                                                               ";
		gotoXY(XX - 3, YY + 16); setColor(11, 0);
		cout << " << Press ESC to exit >> ";
		setColor(co_theme);

		int _in = nextMove();
		if (_in == 5) break;
		else if (S == -1) continue;

		if (_in == 0) {
			_aboutMenu s3[3], s4[3]; 
			s3[0] = { XX - 12, YY + 15, 16, 15, "     PLAY     " };
			s3[1] = { XX + 8, YY + 15, 16, 15,  "    DELETE    " };
			s3[2] = { XX + 28, YY + 15, 16, 15, "    RENAME    " };

			s4[0] = { XX - 12, YY + 15, 16, 14, ">>   PLAY   <<" };
			s4[1] = { XX + 8, YY + 15, 16, 14,  ">>  DELETE  <<" };
			s4[2] = { XX + 28, YY + 15, 16, 14, ">>  RENAME  <<" };

			s1[S].draw();
			gotoXY(XX - 30, YY + 16); setColor(co_theme);
			cout << "                                                                                 ";
			gotoXY(XX - 24, YY + 16); setColor(11, 0); cout << " Choose: ";

			int Sj = 0;
			while (true) {
				gotoXY(XX - 30, YY + 16); setColor(co_theme);
				cout << "                                                                                 ";
				gotoXY(XX - 24, YY + 16); setColor(11, 0); cout << " Choose: ";

				for (int j = 0; j < 3; ++j)
					s3[j].draw();
				s4[Sj].draw();

				int _in = nextMove();
				if (_in == 5) break;
				else if (_in == 2) Sj = (Sj + 2) % 3;
				else if (_in == 4) Sj = (Sj + 1) % 3;
				else if (_in == 0) {
					if (Sj == 0) {
						// Play Game (open file filesNames[S])
						vector<pair<int, int>> tmp = { {3, 2}, {3, 3}, {5, 5}, {6, 6} }; // demo
						startGame(1, 0, XX, YY, "trung", "khoa", tmp, "file1");					// demo
						return;
					}

					if (Sj == 1) {
						// DELETE
						for (int t = S + 1; t <= sz; ++t) {
							fileNames[t - 1] = fileNames[t];
							s1[t - 1].str = s1[t].str;
							s2[t - 1].str = s2[t].str;
						} 
						
						fileNames.pop_back();
						s1[sz].str = "      EMPTY       ";
						s1[sz].b_color = 12;
						s2[sz].str = "";
						--sz;  S = min(S, sz);

					} else {
						// Nhớ cập nhật lại fileNames vào file .txt
						setColor(co_theme);
						gotoXY(XX - 29, YY + 15); cout << "                                                                               ";
						gotoXY(XX - 29, YY + 16); cout << "                                                                               ";
						gotoXY(XX - 29, YY + 17); cout << "                                                                               ";

						string tmp;
						gotoXY(XX - 24, YY + 16); cout << " New Name: ";
						if (!putname(XX - 13, YY + 16, tmp = fileNames[S])) continue;

						fileNames[S] = tmp;
						int siz = 14 - (int)tmp.size();

						for (int t = 1; 2 * t <= siz; ++t)
							tmp = ' ' + tmp + ' ';
						if (siz & 1) tmp += ' ';

						s1[S].str = "  " + tmp + "  ";
						s2[S].str = ">>" + tmp + "<<";
					} break;
				}
			} if (S != -1) s2[S].draw();

		} else {
			int col = S / 5, nxt_S;
			if (_in == 1) nxt_S = (S + 4) % 5 + col * 5;
			else if (_in == 2) nxt_S = (S + 10) % 15;
			else if (_in == 3) nxt_S = (S + 1) % 5 + col * 5;
			else if (_in == 4) nxt_S = (S + 5) % 15;
			if (nxt_S <= sz) S = nxt_S;
		}
	}
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
