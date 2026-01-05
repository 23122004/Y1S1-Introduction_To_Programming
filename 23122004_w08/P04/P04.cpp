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
	int n, x, k, a[MAX_SIZE];

	NhapMang(a, n, "A");
	cout << "Nhap vi tri x = ";	cin >> x;
	cout << "Nhap so luong phan tu muon xoa: "; cin >> k;

	for (int i = x; i + k <= n; ++i)
		a[i] = a[i + k];

	cout << "Mang A sau khi xoa " << k << " phan tu bat dau tu vi tri " << x << " la: \n\t";
	XuatMang(a, n - k);

	return 0;
}