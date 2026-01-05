#include <iostream>
using namespace std;

struct PhanSo {
    int tu, mau;
};

int gcd(int a, int b) {
    int r;
    while (b != 0) {
        r = a % b;
        a = b, b = r;
    } return a;
}

PhanSo modify(PhanSo& a) {
    int sign = 1;
    if (a.tu < 0) sign *= -1, a.tu *= -1;
    if (a.mau < 0) sign *= -1, a.mau *= -1;

    int g = gcd(a.tu, a.mau);
    a.tu /= g * sign, a.mau /= g;
    return a;
}

void NhapPhanSo(PhanSo& a) {
    cout << "    Tu: "; cin >> a.tu;
    cout << "    Mau: "; cin >> a.mau;
    modify(a); cout << "\n";
}

void XuatPhanSo(PhanSo a) {
    cout << a.tu << '/' << a.mau << '\n';
}

PhanSo operator +(const PhanSo& a, const PhanSo& b) {
    PhanSo res = { a.tu * b.mau + b.tu * a.mau, a.mau * b.mau };
    return modify(res);
}

PhanSo operator -(const PhanSo& a, const PhanSo& b) {
    PhanSo res = { a.tu * b.mau - b.tu * a.mau, a.mau * b.mau };
    return modify(res);
}
PhanSo operator *(const PhanSo& a, const PhanSo& b) {
    PhanSo res = { a.tu * b.tu, a.mau * b.mau };
    return modify(res);
}
PhanSo operator /(const PhanSo& a, const PhanSo& b) {
    PhanSo res = { a.tu * b.mau, a.mau * b.tu };
    return modify(res);
}

int32_t main() {
    PhanSo a, b;
    cout << "Nhap phan so 1:\n";
    NhapPhanSo(a);

    cout << "Nhap phan so 2:\n";
    NhapPhanSo(b);

    cout << "Tong: "; XuatPhanSo(a + b);
    cout << "Hieu: "; XuatPhanSo(a - b);
    cout << "Tich: "; XuatPhanSo(a * b);
    cout << "Thuong: "; XuatPhanSo(a / b);

    return 0;
}

