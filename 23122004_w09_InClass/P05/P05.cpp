#include <time.h>
#include <iostream>
using namespace std;

#define max_dong 100
#define max_cot 100

void NhapMaTran(int a[max_dong][max_cot], int n, int m);
void XuatMaTran(int a[max_dong][max_cot], int n, int m);
void SapXepTang(int a[max_dong][max_cot], int n, int m);
void SapXepGiam(int a[max_dong][max_cot], int n, int m);

int32_t main() {
	int n, m;
	int a[max_dong][max_cot];

	cout << "Nhap so dong: n = ";
	cin >> n;

	cout << "Nhap so cot: m = ";
	cin >> m;

	NhapMaTran(a, n, m);
	XuatMaTran(a, n, m);

	SapXepTang(a, n, m);
	cout << "a) Tang dan tu tren xuong duoi:\n";
	XuatMaTran(a, n, m);

	SapXepGiam(a, n, m);
	cout << "b) Giam dan tu tren xuong duoi:\n";
	XuatMaTran(a, n, m);

	return 0;
}

void NhapMaTran(int a[max_dong][max_cot], int n, int m) {
	srand((unsigned int)time(NULL));
	cout << '\n' << "Random:" << '\n';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = rand() % 90 + 10;
}

void XuatMaTran(int a[max_dong][max_cot], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << " " << a[i][j];
		cout << '\n';
	}
}

void SapXepTang(int a[max_dong][max_cot], int n, int m) {
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][i] > a[j][j]) swap(a[i][i], a[j][j]);
}

void SapXepGiam(int a[max_dong][max_cot], int n, int m) {
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i][i] < a[j][j]) swap(a[i][i], a[j][j]);
}


