#include<iostream>
using namespace std;

const int MAX = 100;

bool isPrime(int x) {
	if (x < 2) return 0;
	for (int i = 2; i * i <= x; ++i)
		if (x % i == 0) return 0;
	return 1;
}

void Sort(int a[], int n) {
	for (int i = 1; i < n; ++i)
		for (int j = i + 1; j <= n; ++j)
			if (a[i] > a[j]) swap(a[i], a[j]);
}

int32_t main() {
	int n, m, a[MAX], b[MAX];

	cout << "Nhap so luong phan tu: ";
	cin >> n;

	cout << "Nhap mang:\n";
	for (int i = 1; i <= n; ++i) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
		
	m = 0;
	for (int i = 1; i <= n; ++i)
		if (isPrime(a[i])) b[++m] = a[i];

	Sort(b, m);
	cout << "Mang so nguyen to sau khi sap xep: ";
	for (int i = 1; i <= m; ++i)
		cout << b[i] << " ";


	return 0;
}