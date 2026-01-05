#include <iostream>
using namespace std;

int n, res;
char opt;

int32_t main() {
    cout << "Nhap so ngay thue: "; cin >> n;
    cout << "Nhap loai phong muon thue: "; cin >> opt;

    if (opt == 'A') res = 400000 * n;
    if (opt == 'B') res = 300000 * n;
    if (opt == 'C') res = 250000 * n;

    if (n > 12) {
        if (opt == 'A') res = res * 9 / 10;
        else res = res * 92 / 100;
    } cout << "So tien phai tra: " << res << "\n";

    return 0;
}