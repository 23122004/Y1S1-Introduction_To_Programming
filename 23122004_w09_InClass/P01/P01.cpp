#include <time.h>
#include <iostream>
using namespace std;

#define max_dong 100
#define max_cot 100

void NhapMaTran(int a[max_dong][max_cot], int n, int m);
void XuatMaTran(int a[max_dong][max_cot], int n, int m);
void XuatGiaTriChan(int a[max_dong][max_cot], int n, int m);

int32_t main() {
	int n = 10, m = 10;
	int a[max_dong][max_cot];

	NhapMaTran(a, n, m);
	XuatMaTran(a, n, m);

	XuatGiaTriChan(a, n, m);
	
	return 0;
}

void NhapMaTran(int a[max_dong][max_cot], int n, int m) {
	srand((unsigned int)time(NULL));
	cout << '\n' << "Random:" << '\n';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = rand() % 90 - 40;
}

void XuatMaTran(int a[max_dong][max_cot], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << " " << a[i][j];
		cout << '\n';
	}
}

void XuatGiaTriChan(int a[max_dong][max_cot], int n, int m) {
	cout << "Cac gia tri chan trong ma tran: ";
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			if(a[i][j] % 2 == 0) cout << a[i][j] << ' ';
}
