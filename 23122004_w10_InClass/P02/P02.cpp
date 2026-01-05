#include <iostream>
#include <time.h>
#include<fstream>
using namespace std;

const int MAX = 100;
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

void NhapPhanSo(PhanSo a[], int n) {
    for (int i = 0; i < n; ++i) {
        a[i].tu = rand() % 40 + 10;
        a[i].mau = a[i].tu + max(rand() % a[i].tu, 1);
        modify(a[i]);
    }
}

void XuatPhanSo(PhanSo a[], int n) {
    cout << "Mang phan so luu vao tap tin:\n" << n << '\n';
    for (int i = 0; i < n; ++i) 
        cout << a[i].tu << '/' << a[i].mau << ' ';
}

void PhanSo_to_textfile(ofstream& fout, PhanSo a[], int n) {
    fout << n << '\n';
    for (int i = 0; i < n; ++i)
        fout << a[i].tu << '/' << a[i].mau << ' ';
}

bool PhanSo_textfile(PhanSo a[], int n) {
    ofstream fout;
    fout.open("Mang PS toi gian.txt");

    if (!fout) {
        cout << "\n\nLoi tao tep tin...";
        return false;
    } else PhanSo_to_textfile(fout, a, n);
    return true;
}

int32_t main() {
    srand((unsigned int)time(NULL));
    PhanSo a[MAX];
    int n;

    cout << "Nhap N = ";
    cin >> n;
    
    NhapPhanSo(a, n);
    if(PhanSo_textfile(a, n))
        cout << "Da luu mang phan so toi gian vao Mang PS toi gian.txt\n";

    return 0;
}

