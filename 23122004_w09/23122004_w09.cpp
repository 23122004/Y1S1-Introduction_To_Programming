#include <iostream>
#include <time.h>
#include <string>
#include <map>
using namespace std;

const int N = 100;
int RAND() {
	return rand() % 90 - 35;
}

void NhapMaTran(int a[N][N], int& n, int& m) {
	cout << "Nhap so dong n = "; cin >> n;
	cout << "Nhap so dong m = "; cin >> m;

	cout << '\n' << "Random:" << '\n';
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			a[i][j] = RAND();
}

void XuatMaTran(int a[N][N], int n, int m) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			cout << " " << a[i][j];
		cout << '\n';
	}
}

int SoDuongNhoNhat(int a[N][N], int n, int m) {
	int mn = INT_MAX;
	for (int i = 0; i < n; ++i) 
		for (int j = 0; j < m; ++j)
			mn = min(mn, a[i][j]);
	return mn;
}

int SoMaxBien(int a[N][N], int n, int m) {
	int mx = a[0][0];
	for (int i = 0; i < n; ++i)
		mx = max({ mx, a[i][0], a[i][m - 1] });

	for (int j = 0; j < n; ++j)
		mx = max({ mx, a[0][j], a[n - 1][j] });
	return mx;
}

void LietKeDongChan(int a[N][N], int n, int m) {
	bool ok = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (a[i][j] & 1) break;
			if (j == m - 1) {
				cout << i << ' ';
				ok = 1;
			}
		}
	if (!ok) cout << "Khong ton tai!";
}

bool LaSoDuongDoiXung(int x) {
	if (x <= 0) return 0;
	string s = to_string(x), t = s;
	reverse(t.begin(), t.end());
	return s == t;
}

int TinhTongSDDXCC(int a[N][N], int n, int m) {
	int s = 0;
	for (int i = 0; i < n; ++i)
		if (LaSoDuongDoiXung(a[i][i]))
			s += a[i][i];
	return s;
}

int DemSoLuongSDDXCP(int a[N][N], int n, int m) {
	int cnt = 0;
	for (int i = 0; i < n; ++i)
		cnt += LaSoDuongDoiXung(a[i][m - 1 - i]);
	return cnt;
}

bool LaChinhPhuong(int x) {
	int tmp = sqrt(x);
	return tmp * tmp == x;
}

int TinhTongChinhPhuong(int a[N][N], int n, int m) {
	int s = 0, i;
	for (i = 0; i * 2 < n; ++i)
		if (LaChinhPhuong(a[i][i])) s += a[i][i];

	for(; i < n; ++i)
		if (LaChinhPhuong(a[i][m - 1 - i])) s += a[i][i];
	return s;
}

int PhanTuXuatHienNhieuNhat(int a[N][N], int n, int m) {
	int res = 0;
	map<int, int> cnt;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (++cnt[a[i][j]] > cnt[res]) res = a[i][j];
	return res;
}

int32_t main() {
	srand((unsigned int)time(NULL));
	int n, m, a[N][N];
	NhapMaTran(a, n, m);
	XuatMaTran(a, n, m);

	cout << "1. So duong nho nhat: " << SoDuongNhoNhat(a, n, m) << '\n';
	cout << "2. So lon nhat tren bien: " << SoMaxBien(a, n, m) << '\n'; 
	cout << "3. Liet ke dong chua toan so chan: "; LietKeDongChan(a, n, m);  cout << '\n';
	cout << "4. Tong so duong doi xung tren duong cheo chinh: " << TinhTongSDDXCC(a, n, m) << '\n';
	cout << "5. So luong so doi xung tren duong cheo phu: " << DemSoLuongSDDXCP(a, n, m) << '\n';
	cout << "6. Tong cac so chinh phuong: " << TinhTongChinhPhuong(a, n, m) << '\n';
	cout << "10. Phan tu xuat nhieu nhieu nhat: " << PhanTuXuatHienNhieuNhat(a, n, m) << '\n';

	return 0;
}