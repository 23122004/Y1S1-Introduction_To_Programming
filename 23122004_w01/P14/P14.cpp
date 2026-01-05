#include <iostream>
using namespace std;

int n;
double q, M;

int32_t main() {

	cout << "Nhap so tien gui M = "; cin >> M;
	cout << "Nhap so thang gui n = "; cin >> n;
	cout << "Nhap so lai suat q = "; cin >> q;
	cout << "So tien lai sau " << n << " thang la: " << M * (pow(1 + q, n) - 1) << "\n";

	return 0;
}