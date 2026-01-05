#include <iostream>
using namespace std;

double a, b, c;

int32_t main() {
    cout << "Nhap vao do dai 3 canh a, b, c: ";
    cin >> a >> b >> c;

    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);

    if (a + b - c <= 0.0) cout << "Khong tao thanh tam giac\n";
    else {
        if (a == b && b == c) cout << "Tam giac deu\n";
        else {
            bool checkVuong = 0, checkCan = 0;
            if (abs(a * a + b * b - c * c) < 1e-4) checkVuong = 1;
            if (a == b || b == c) checkCan = 1;

            if (checkCan && checkVuong) cout << "Tam giac vuong can\n";
            else if (checkCan) cout << "Tam giac can\n";
            else if (checkVuong) cout << "Tam giac vuong\n";
            else cout << "Tam giac thuong\n";
        }
    }

    return 0;
}