#include<iostream>
#include <iomanip>
using namespace std;

int32_t main() {
	cout << "Nhap so can lam tron: ";
	double n; cin >> n;

	cout << "So chu so thap phan co nghia sau khi lam tron: ";
	int k; cin >> k;

	cout << "Ket qua la: " << fixed << setprecision(k) << n;

	return 0;
}