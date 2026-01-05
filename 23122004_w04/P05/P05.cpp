#include<iostream>
using namespace std;

int32_t main() {
	int n, k;
	cout << "Nhap n = "; cin >> n;
	cout << "Nhap k = "; cin >> k;
	
	if (n == 0) {
		if (k == 1) cout << "So thu tu thu k cua n tu ben phai la: 0";
		else cout << "Khong co ket qua thoa man";
	} else {
		while (n > 0) {
			if (--k == 0) {
				cout << "So thu tu thu k cua n tu ben phai la: " << n % 10;
				return 0;
			} n /= 10;
		} cout << "Khong co ket qua thoa man";
	}

	return 0;
}