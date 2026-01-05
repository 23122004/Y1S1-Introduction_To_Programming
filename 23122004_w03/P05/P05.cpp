#include <iostream>
using namespace std;

double n, l, r;

int32_t main() {
    cout << "Nhap so thuc n = ";
    cin >> n;

    l = 0, r = n;
    while (l <= r) {
        double m = (l + r) / 2.0;
        double S = m * m * m;

        if (abs(S - n) <= 0.0000001) {
            cout << "Can bac 3 cua n la: " << m;
            exit(0);
        }

        if (S > n) r = m;
        else l = m;
    }

    return 0;
}