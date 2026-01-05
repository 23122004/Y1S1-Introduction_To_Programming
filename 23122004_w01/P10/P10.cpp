#include <iostream>
using namespace std;

double P, a, b;

int32_t main() {

	cout << "Nhap chu vi cua hinh chu nhat: "; cin >> P;
	b = P / 5.0, a = b * 1.5;
	cout << "Dien tich: " << a * b << "\n";

	return 0;
}