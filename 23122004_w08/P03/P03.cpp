#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
void NhapMang(int a[], int& n, string s) {
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
	int n, a[MAX_SIZE], b[MAX_SIZE];
	cout << "Nhap so luong phan tu: ";
	cin >> n;

	NhapMang(a, n, "A");
	NhapMang(b, n, "B");

	for (int i = 1; i <= n; ++i)
		a[i] += b[i];

	cout << "Mang sau khi tron mang A va B la:\n\t";
	XuatMang(a, n);

	return 0;
}