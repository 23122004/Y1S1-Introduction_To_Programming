#include <iostream>
using namespace std;

int pt1(int a, int b, double &x) {
    if (a == 0) {
        if (b != 0) return -1;
        else return 0;
    }

    x = (double)(-b) / a;
    return 1;
} // -1: VN , 0: VSN , 1: Co 1 ng

int pt2(int a, int b, int c, double& x1, double& x2) {
    if (a == 0) return pt1(b, c, x1);

    double delta = sqrt(b * b - 4 * a * c);
    if (delta < 0) return -1;
    else if (delta == 0) {
        x1 = double(-b) / (2.0 * a);
        return 1;
    } else {
        x1 = (double(-b) - delta) / (2.0 * a);
        x2 = (double(-b) + delta) / (2.0 * a);
        return 2;
    }

} // -1: VN , 0: VSN , 1: Co 1 ng , 2: Co 2 ng

void sol1(int a, int b, int c) {
    double x1, x2;
    pt2(a, b, c, x1, x2);
    if (x1 > x2) swap(x1, x2);

    cout << "Bat phuong trinh co nghiem: ";
    if (a > 0) cout << "x < " << x1 << ", " << x2 << " < x\n";
    else cout << x1 << " < x < " << x2 << "\n";
}

void sol2(int a, int b, int c) {
    double x1, x2;
    pt2(a, b, c, x1, x2);
    if (x1 > x2) swap(x1, x2);

    cout << "Bat phuong trinh co nghiem: ";
    if (a < 0) cout << "x < " << x1 << ", " << x2 << " < x\n";
    else cout << x1 << " < x < " << x2 << "\n";
}

void sol3(int a, int b, int c) {
    double x1, x2;
    int cnt = pt2(a, b, c, x1, x2);

    if (cnt == -1) cout << "Phuong trinh vo nghiem";
    else if (cnt == 0) cout << "Phuong trinh vo so nghiem";
    else if (cnt == 1) cout << "Phuong trinh co 1 nghiem: x = " << x1;
    else cout << "Phuong trinh co 2 nghiem: x1 = " << x1 << ", x2 = " << x2;
}

int32_t main() {
    cout << "Nhap 3 so nguyen a, b, c: ";
    int a, b, c; cin >> a >> b >> c;

    if (a < b && b < c) sol1(a, b, c);
    else if (a > b && b > c) sol2(a, b, c);
    else sol3(a, b, c);

    return 0;
}