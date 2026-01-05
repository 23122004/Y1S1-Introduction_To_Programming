#include <time.h>
#include <iostream>
using namespace std;

#define max_dong 100
#define max_cot 100

void NhapMaTran(int a[max_dong][max_cot], int n, int m);
void XuatMaTran(int a[max_dong][max_cot], int n, int m);
void LietKeDong(int a[max_dong][max_cot], int n, int m);

int32_t main() {
	int n, m;
	int a[max_dong][max_cot];

	cout << "Nhap so dong: n = ";
	cin >> n;

	cout << "Nhap so cot: m = ";
	cin >> m;

	NhapMaTran(a, n, m);
	XuatMaTran(a, n, m);

	cout << "Cac dong co gia tri am: ";
	LietKeDong(a, n, m);
	cout << '\n';

	return 0;
}

void NhapMaTran(int a[max_dong][max_cot], int n, int m) {
	srand((unsigned int)time(NULL));
	cout << '\n' << "Random:" << '\n';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = rand() % 90 - 20;
}

void XuatMaTran(int a[max_dong][max_cot], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << " " << a[i][j];
		cout << '\n';
	}
}

void LietKeDong(int a[max_dong][max_cot], int n, int m) {
	for (int i = 0; i < n; ++i) 
		for(int j = 0; j < m; ++j)
			if (a[i][j] < 0) {
				cout << i + 1 << " ";
				break;
			}
}


