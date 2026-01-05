#include<iostream>
using namespace std;

const int MAX = 100;

int32_t main() {
	int n, x, k, a[MAX];

	cout << "Nhap so luong phan tu: ";
	cin >> n;

	cout << "Nhap mang:\n";
	for (int i = 1; i <= n; ++i) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	cout << "Nhap gia tri x = "; cin >> x;
	cout << "Nhap vi tri muon chen k = "; cin >> k;

	for (int i = n; i >= k; --i)
		a[i + 1] = a[i];
	a[k] = x;

	cout << "Mang sau khi chen: ";
	for (int i = 1; i <= n + 1; ++i)
		cout << a[i] << ' ';

	return 0;
}