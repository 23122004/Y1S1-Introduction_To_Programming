#include <iostream>
using namespace std;

char c;

int32_t main() {
    cout << "Nhap mot chu cai: ";
    cin >> c;

    cout << "Ket qua la: ";
    if (65 <= c && c <= 96) cout << char(c + 32) << "\n";
    else cout << char(c - 32) << "\n";

    return 0;
}