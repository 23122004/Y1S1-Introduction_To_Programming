#include <iostream>
using namespace std;

int a, b, c;
double delta;

int32_t main() {
    cout << "Nhap vao 3 so nguyen a, b, c: ";
    cin >> a >> b >> c;
    cout << "Phuong trinh bac 2: " << a << "x^2 + " << b << "x + " << c << " = 0, ";

    if (a == 0) {
        if (b == 0) {
            if (c == 0) cout << "Vo so nghiem\n";
            else cout << "Vo nghiem\n";
        }
        else cout << "Co mot nghiem x = " << (double)(-c) / b << "\n";
    }
    else {
        delta = b * b - 4 * a * c;
        if (delta < 0) cout << "Vo nghiem";
        else if (delta == 0) cout << "Co mot nghiem x = " << (double)(-b) / (2 * a) << "\n";
        else {
            delta = sqrt(delta);
            cout << "Co hai nghiem x1 = " << (double)(delta - b) / (2 * a);
            cout << " va x2 = " << (double)(-delta - b) / (2 * a) << "\n";
        }
    }

    return 0;
}