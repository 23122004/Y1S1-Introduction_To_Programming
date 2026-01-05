#include <iostream>
using namespace std;

double a, b, c;

int32_t main() {

	cout << "Nhap do dai chieu cao, chieu sau va chieu rong cua khoi hop: "; cin >> a >> b >> c;
	cout << "Dien tich be mat cua khoi hop: " << (b + c) * 2.0 * a + 2.0 * b * c << "\n";
	cout << "The tich cua khoi hop: " << a * b * c << "\n\n";

	cout << "Nhap do dai canh cua khoi lap phuong: "; cin >> a;
	cout << "Dien tich be mat cua khoi lap phuong: " << 6 * a * a << "\n";
	cout << "The tich cua khoi lap phuong: " << a * a * a << "\n\n";

	cout << "Nhap do dai ban kinh, chieu cao cua khoi tru tron: "; cin >> a >> b;
	cout << "Dien tich be mat cua khoi tru tron: " << 6.28 * a * (a + b) << "\n";
	cout << "The tich cua khoi tru tron: " << 3.14 * a * a * b << "\n";

	return 0;
}