#include <iostream>
#include <iomanip>
using namespace std;

double x;

int32_t main() {

	cout << "Nhap so thuc x = "; cin >> x;
	cout << "A = " << fixed << setprecision(2) << 3.0 * x * x * x - 2 * x * x << "\n";

	return 0;
}

