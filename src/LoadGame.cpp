#include "../include/LoadGame.h"
#include "../include/Game.h"
#include "../include/Newgame.h"
#include "../include/Graphic.h"
#include "../include/Console.h"
#include "../include/library.h"

using namespace std;

#define co_theme 15,0

const int BOARD_SIZE = 15;
vector<string> fileNames;

void loadGame(int XX, int YY) {
	struct _aboutMenu {
		int X, Y, size, b_color;
		string str;

		void draw() {
			Graphics::drawBoardMenu(X, Y, size, b_color, str);
		}
	};

	/*------------------ DECOR ---------------------------*/
	int sz = min((int)fileNames.size() - 1, 14);  
	_aboutMenu s1[15], s2[15]; 
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
	Console::drawImage(5, 15, "pixel_art/Octopus.txt");
	Console::drawImage(117, 15, "pixel_art/Octopus.txt");
	Console::drawImage(20, 32, "pixel_art/Turtle.txt");
	Console::drawImage(60, 32, "pixel_art/Turtle.txt");
	Console::drawImage(100, 32, "pixel_art/Turtle.txt");
	Graphics::drawLOAD_GAME(XX - 26, YY - 9);
	Graphics::drawPopUp(XX - 33, YY - 1, 20, 86);
	/*----------------------------------------------------*/

	int S = min(0, sz);		// Pointer
	while (true) {
		for (int i = 0; i < 15; ++i)
			s1[i].draw();
		if (S != -1) s2[S].draw();

		Console::setColor(co_theme);
		Console::gotoXY(XX - 29, YY + 15); cout << "                                                                               ";
		Console::gotoXY(XX - 29, YY + 16); cout << "                                                                               ";
		Console::gotoXY(XX - 29, YY + 17); cout << "                                                                               ";
		Console::gotoXY(XX - 3, YY + 16); Console::setColor(11, 0);
		cout << " << Press ESC to exit >> ";
		Console::setColor(co_theme);

		int _in = Console::nextMove();
		if (_in == 5) break;			// Esc
		else if (S == -1) continue;		// No files were saved

		if (_in == 0) {
			_aboutMenu s3[3], s4[3];	// s3: unselect, s4: select
			s3[0] = { XX - 12, YY + 15, 16, 15, "     PLAY     " };
			s3[1] = { XX + 8, YY + 15, 16, 15,  "    DELETE    " };
			s3[2] = { XX + 28, YY + 15, 16, 15, "    RENAME    " };

			s4[0] = { XX - 12, YY + 15, 16, 14, ">>   PLAY   <<" };
			s4[1] = { XX + 8, YY + 15, 16, 14,  ">>  DELETE  <<" };
			s4[2] = { XX + 28, YY + 15, 16, 14, ">>  RENAME  <<" };

			// Display: choose the operation
			s1[S].draw();
			Console::gotoXY(XX - 30, YY + 16); Console::setColor(co_theme);
			cout << "                                                                                 ";
			Console::gotoXY(XX - 24, YY + 16); Console::setColor(11, 0); cout << " Choose: ";

			int Sj = 0;
			while (true) {
				// Display: choose the operation
				Console::gotoXY(XX - 30, YY + 16); Console::setColor(co_theme);
				cout << "                                                                                 ";
				Console::gotoXY(XX - 24, YY + 16); Console::setColor(11, 0); cout << " Choose: ";

				for (int j = 0; j < 3; ++j)
					s3[j].draw();
				s4[Sj].draw();

				int _in = Console::nextMove();
				if (_in == 5) break;					// Esc
				else if (_in == 2) Sj = (Sj + 2) % 3;	// Left
				else if (_in == 4) Sj = (Sj + 1) % 3;	// Right
				else if (_in == 0) {					// Enter
					if (Sj == 0) {		// Load file and play
						vector<ii> Cache;
						int Xscore, Oscore;
						string name1, name2;
						bool vsBot;

						loadFromFile(fileNames[S], Cache, Xscore, Oscore, name1, name2, vsBot);
                        Game game;
						game.startGame(vsBot, 0, XX, YY, name1, name2, Cache, fileNames[S], Xscore, Oscore);
						return;
					}

					if (Sj == 1) {		// Delete file
						deleteFile(fileNames[S]);
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

					} else {			// Rename file
						Console::setColor(co_theme);
						Console::gotoXY(XX - 29, YY + 15); cout << "                                                                               ";
						Console::gotoXY(XX - 29, YY + 16); cout << "                                                                               ";
						Console::gotoXY(XX - 29, YY + 17); cout << "                                                                               ";

						// Import new name
						renameFile:
						string tmp;
						Console::gotoXY(XX - 24, YY + 16); cout << " New Name:                                                         ";
						if (!putname(XX - 13, YY + 16, tmp = fileNames[S])) continue;

						// Check the same name
						bool checkSame = 0;
						for (int t = 0; t <= sz; ++t)
							if (t != S && fileNames[t] == tmp)
								checkSame = 1;

						if (checkSame) {
							Console::gotoXY(XX - 24, YY + 16); cout << ">> It already exists, do you want to change another name? Press Y/N";
							while (true) {
								char key = _getch();
								if (key == 'N' || key == 'n') break;
								else if (key == 'Y' || key == 'y') goto renameFile;
							} break;
						}

						// Process rename
						string old_name = "resources/" + fileNames[S] + ".txt"; // NOTE: Should use resources path?
						string new_name = "resources/" + tmp + ".txt"; // Or just assume relative to cwd

                        // The load/save functions seem to rely on current working directory or specific path.
                        // I should verify where files are saved.
                        // Originally "ListNameFiles.txt" lists names.
                        // `saveGame` opens `nameFile + ".txt"`.
                        // If I moved `pixel_art` to `resources`, I didn't move save files.
                        // So assuming save files are in root is safest for now.
                        // Reverting "resources/" prefix for user save files.

                        old_name = fileNames[S] + ".txt";
                        new_name = tmp + ".txt";
						rename(old_name.c_str(), new_name.c_str());

						fileNames[S] = tmp;
						int siz = 14 - (int)tmp.size();

						for (int t = 1; 2 * t <= siz; ++t)
							tmp = ' ' + tmp + ' ';
						if (siz & 1) tmp += ' ';

						s1[S].str = "  " + tmp + "  ";
						s2[S].str = ">>" + tmp + "<<";
					} 
					pushList();
					break;
				}
			} if (S != -1) s2[S].draw();

		} else {
			int col = S / 5, nxt_S;
			if (_in == 1) nxt_S = (S + 4) % 5 + col * 5;		// Up
			else if (_in == 2) nxt_S = (S + 10) % 15;			// Left
			else if (_in == 3) nxt_S = (S + 1) % 5 + col * 5;	// Down
			else if (_in == 4) nxt_S = (S + 5) % 15;			// Right
			if (nxt_S <= sz) S = nxt_S;		// The pointer mustn't be out of stock
		}
	}
}

// 
void saveGame(int XX, int YY, vector<ii> Cache, int Xscore, int Oscore, string name1, string name2, string& nameFile, bool vsBot) {
	if (nameFile == "") {
		insertName:
		Graphics::drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 2);
		if (!putname(XX - 18, YY + 2 * BOARD_SIZE - 1, nameFile)) {
			Graphics::drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
			return;
		} if (nameFile == "") goto insertName;
	}

	bool checkSame = 0;
	for (string tmp : fileNames)
		if (tmp == nameFile) checkSame = 1;

	if (checkSame) {
		Graphics::drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 3);
		while (true) {
			char key = _getch();
			if (key == 'N' || key == 'n') {
				Graphics::drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
				nameFile = "";
				return;
			} else if (key == 'Y' || key == 'y') break;
		} 
	} else {
		while ((int)fileNames.size() >= 15)
			fileNames.erase(fileNames.begin());
		fileNames.push_back(nameFile);
	}
	
	Graphics::drawStatus(XX - 31, YY + 2 * BOARD_SIZE - 1, 1);
	Graphics::drawName_Board(XX + 4 * BOARD_SIZE - 33, YY + 2 * BOARD_SIZE - 1, nameFile);
	pushList();

	// Save game to PC
	ofstream File(nameFile + ".txt");
	File << int(vsBot) << " " << Xscore << " " << Oscore << '\n';
	File << name1 << " " << name2 << '\n';

	for (const auto& tmp : Cache) {
		File << tmp.first << " " << tmp.second << "\n";
	} File.close();
}

void loadFromFile(string nameFile, vector<ii>& Cache, int& Xscore, int& Oscore, string& name1, string& name2, bool& vsBot) {	// Load data from file is saved
	Cache.clear();
	nameFile += ".txt";
	ifstream file(nameFile);
	int x, y;

	file >> vsBot >> Xscore >> Oscore >> name1 >> name2;
	while (file >> x >> y) Cache.emplace_back(x, y);
	file.close();
}

void pullList() {		// Update list file is saved to fileNames
	string s; fileNames.clear();
	ifstream file("resources/ListNameFiles.txt"); // Updated path
	while (file >> s) fileNames.emplace_back(s);
	file.close();
}
	
void pushList() {		// Update list file is saved in fileNames to PC
	ofstream File("resources/ListNameFiles.txt"); // Updated path
	for (string s : fileNames) File << s << '\n';
	File.close();
}

void deleteFile(string nameFile) {	// Delete File
	nameFile += ".txt";
	remove(nameFile.c_str());
}