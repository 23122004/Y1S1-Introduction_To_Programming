#include <iostream>
#include <algorithm>
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
	int n, cnt = 1, a[MAX_SIZE];
	
	NhapMang(a, n, "A");
	sort(a + 1, a + 1 + n);

	for (int i = 2; i <= n; ++i)
		if (a[i] == a[i - 1]) ++cnt;
		else {
			cout << "Tan suat cua " << a[i - 1] << " la: " << cnt << '\n';
			cnt = 1;
		}
	cout << "Tan suat cua " << a[n] << " la: " << cnt << '\n';

	return 0;
}