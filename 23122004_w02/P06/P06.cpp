#include <iostream>
#include <string>
using namespace std;

string name;
double T, L, H, tb;

int32_t main() {
    cout << "Nhap ten: ";
    getline(cin, name);

    cout << "Nhap diem Toan, Ly, Hoa: ";
    cin >> T >> L >> H;

    cout << "Hoc sinh " << name << " dat hoc luc: ";
    tb = T + L + H;
    
    if (tb >= 27.0) cout << "Xuat sac";
    else if (tb >= 24.0) cout << "Gioi";
    else if (tb >= 19.5) cout << "Kha";
    else if (tb >= 15.0) cout << "Trung binh";
    else if (tb >= 9.0) cout << "Yeu";
    else cout << "Kem";
    cout << "\n";

    return 0;
}