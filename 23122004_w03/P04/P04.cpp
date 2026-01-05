#include <iostream>
using namespace std;

int32_t main() {
    int n;
    while (true) {
        cout << "Nhap vao so nguyen duong: ";
        cin >> n;

        if (n == 0) break;
        int S1 = 0, S2 = 1;

        while (n > 0) {
            S1 += n % 10;
            S2 *= n % 10;
            n /= 10;
        }

        if (S1 == S2) cout << "Tong cac chu so bang tich\n";
        else cout << "Tong cac chu so khong bang tich\n";
    }

    return 0;
}