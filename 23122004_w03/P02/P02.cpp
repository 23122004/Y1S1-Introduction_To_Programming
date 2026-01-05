#include <iostream>
using namespace std;

const double M = -123.45;
double n, mx = -DBL_MAX, mn = -1, res = 1;

int32_t main() {
    while (true) {
        cin >> n;
        if (n == 0.0) break;

        mx = max(mx, n);
        if (n > 0.0) {
            if (mn == -1) mn = n;
            else mn = min(mn, n);
        }

        if (n < 0.0) {
            if (res == 1) res = n;
            else if (abs(res - M) > abs(n - M))
                res = n;
        }
    }

    if (mx == -DBL_MAX) cout << "Khong ton tai so lon nhat\n";
    else cout << "So lon nhat: " << mx << "\n";

    if (mn == -1) cout << "Khong ton tai so thuc duong nho nhat\n";
    else cout << "So thuc duong nho nhat: " << mn << "\n";

    if (res == 1) cout << "Khong ton tai so thuc am gan voi -123.45";
    else cout << "So thuc am gan voi -123.45 nhat: " << res << "\n";

    return 0;
}
