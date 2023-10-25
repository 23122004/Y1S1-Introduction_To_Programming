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
vector<string> fileNames = { "game1" , "game2", "game3" };

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
						bool vsBot; bool isNewGame; string name1, name2; vector<ii> Data;
						// Play Game (open file filesNames[S])
						loadFromFile(fileNames[S], vsBot, name1, name2, Data);
						vector<pair<int, int>> tmp = { {3, 2}, {3, 3}, {5, 5}, {6, 6}, {7, 6}, }; // demo
						startGame(1, 0, XX, YY, name1, name2, Data, fileNames[S]);					
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


void drawNameOfGame(int XX, int YY, int index_file_name) {
	gotoXY(XX, YY);
	cout << fileNames[index_file_name];
}


// SAVE A NEWGAME

// Step 1 :: Add new file game to DataBase 

// Step 2 :: Write history game to file : filename, name1, name2, vector<pair<int,int>> Data

void Write_File(string fileName, bool vsBot, string name1, string name2, vector<ii> Data) {
	fileNames.push_back(fileName);
	fileName += ".txt";
	
	ofstream File(fileName); 

	// Ghi dữ liệu vào file
	File << int(vsBot) << "\n";
	File << name1 << " " << name2;
	
	for (const auto& pair : Data) {
		File << pair.first << " " << pair.second << " ";
	}

	File.close();
	
}


// LOAD GAME FROM FILE

void loadFromFile(string filename, bool& vsBot, string& name1, string& name2, vector<ii>& Data) {
	/*
	Play Game (open file filesNames[S])
	vector<pair<int, int>> tmp = { {3, 2}, {3, 3}, {5, 5}, {6, 6}, {7, 6}, }; // demo
	startGame(1, 0, XX, YY, "trung", "khoa", tmp, "file1");					// demo
	*/
	filename += ".txt";
	
	ifstream file(filename);

	// Read first line
	file >> vsBot;
	//file >> isNewGame;
	file >> name1;
	file >> name2;
	int first, second;
	while (file >> first >> second) {
		Data.emplace_back(first, second);
	}
	file.close();
}
