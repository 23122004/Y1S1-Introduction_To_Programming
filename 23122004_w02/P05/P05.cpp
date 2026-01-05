#include <iostream>
using namespace std;

double n, res = 0;

int32_t main() {
    cout << "Nhap so km: "; 
    cin >> n;

    if (n <= 1) res = n * 15000;
    else if (n <= 5) res = 15000.0 + (n - 1.0) * 13500;
    else res = 69000.0 + (n - 5.0) * 11000;

    if (n >= 120) res *= 0.9;
    cout << "So tien phai tra: " << (int)res << "\n";

    return 0;
}