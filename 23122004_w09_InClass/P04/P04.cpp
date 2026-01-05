#include <time.h>
#include <iostream>
using namespace std;

#define max_dong 100
#define max_cot 100

void NhapMaTran(int a[max_dong][max_cot], int n, int m);
void XuatMaTran(int a[max_dong][max_cot], int n, int m);
int FindMaxCC(int a[max_dong][max_cot], int n, int m);
int FindMaxCP(int a[max_dong][max_cot], int n, int m);

int32_t main() {
	int n, m;
	int a[max_dong][max_cot];

	cout << "Nhap so dong: n = ";
	cin >> n;

	cout << "Nhap so cot: m = ";
	cin >> m;

	NhapMaTran(a, n, m);
	XuatMaTran(a, n, m);

	cout << "a) Gia tri lon nhat tren duong cheo chinh: " << FindMaxCC(a, n, m) << '\n';
	cout << "b) Gia tri lon nhat tren duong cheo phu: " << FindMaxCP(a, n, m) << '\n';

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

int FindMaxCC(int a[max_dong][max_cot], int n, int m) {
	int mx = a[0][0];
	for (int i = 1; i < n; ++i)
		mx = max(mx, a[i][i]);
	return mx;
}

int FindMaxCP(int a[max_dong][max_cot], int n, int m) {
	int mx = a[0][m - 1];
	for (int i = 1; i < n; ++i)
		mx = max(mx, a[i][m - 1 - i]);
	return mx;
}

