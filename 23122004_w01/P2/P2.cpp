#include <iostream>
using namespace std;

int a, b;

int32_t main() {

	cout << "Nhap 2 so nguyen a va b: ";
	cin >> a >> b;

	cout << a << " + " << b << " = " << a + b << "\n";
	cout << a << " - " << b << " = " << a - b << "\n";
	cout << a << " * " << b << " = " << a * b << "\n";
	cout << a << " / " << b << " = " << (double)a / b << "\n";

	return 0;
}

