#include<iostream>
using namespace std;

const int MAX = 100;

int32_t main() {
	int n, a[MAX];

	cout << "Nhap so luong phan tu: ";
	cin >> n;

	cout << "Nhap mang:\n";
	for (int i = 1; i <= n; ++i) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}

	int mx = 1, mn = 1;
	for (int i = 2; i <= n; ++i) {
		if (a[mx] < a[i]) mx = i;
		if (a[mn] > a[i]) mn = i;
	}

	cout << "a) Vi tri lon nhat: " << mx << '\n';
	cout << "b) Vi tri nho nhat: " << mn << '\n';

	return 0;
}