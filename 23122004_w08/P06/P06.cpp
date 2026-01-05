#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
void NhapMang(int a[], int& n, string s) {
	cout << "Nhap so luong phan tu cua mang " << s << ": ";
	cin >> n;

	cout << "Nhap phan tu cua mang " << s << ":\n";
	for (int i = 1; i <= n; ++i) {
		cout << '\t' << s << "[" << i << "]: ";
		cin >> a[i];
	}
}

void XuatMang(int a[], int n) {
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " \n"[i == n];
}

int32_t main() {
	int n, m, a[MAX_SIZE], LIS[MAX_SIZE];

	NhapMang(a, n, "A");
	
	m = 0;
	for (int i = 1; i <= n; ++i) {
		int k = lower_bound(LIS + 1, LIS + 1 + m, a[i]) - LIS;
		LIS[k] = a[i], m = max(m, k);
	}

	cout << "Mang con tang dan dai nhat: ";
	XuatMang(LIS, m);

	return 0;
}