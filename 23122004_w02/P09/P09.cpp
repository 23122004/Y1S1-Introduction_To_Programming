#include <iostream>
using namespace std;

int n;

int32_t main() {
    do {
        cout << "Nhap thang: "; cin >> n;
        if (n < 1 || n > 12) cout << "Khong hop le...\n";
    } while (n < 1 || n > 12);

    if (2 <= n && n <= 4) cout << "Mua xuan\n";
    else if (5 <= n && n <= 7) cout << "Mua ha\n";
    else if (8 <= n && n <= 10) cout << "Mua thu\n";
    else cout << "Mua dong";

    return 0;
}