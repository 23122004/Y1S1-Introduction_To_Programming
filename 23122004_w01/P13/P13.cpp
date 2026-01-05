#include <iostream>
using namespace std;

int n;
double x;

int32_t main() {

	cout << "Nhap so nguyen duong n = "; cin >> n;
	cout << "Nhap so nguyen thuc x = "; cin >> x;
	cout << "Ket qua la: " << pow(x * x + 1, n) << "\n";

	return 0;
}