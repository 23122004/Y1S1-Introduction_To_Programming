#include<iostream>
using namespace std;

const int MAX = 100;

int32_t main() {
	int n, k, a[MAX];

	cout << "Nhap so luong phan tu: ";
	cin >> n;

	cout << "Nhap mang:\n";
	for (int i = 1; i <= n; ++i) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	cout << "Nhap vi tri muon xoa k = "; cin >> k;
	for (int i = k; i < n; ++i)
		a[i] = a[i + 1];

	cout << "Mang sau khi xoa: ";
	for (int i = 1; i < n; ++i)
		cout << a[i] << ' ';

	return 0;
}