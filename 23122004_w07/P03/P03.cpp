#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void nhapMang(int a[], int& n) {
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    cout << "Nhap cac phan tu cua mang:\n";
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }
}

void xuatMang(int a[], int n) {
    cout << "Mang da nhap la: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool chuaSoDuong(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            return true;
        }
    }
    return false;
}

bool toanSoDuong(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 0) {
            return false;
        }
    }
    return true;
}

void doiSoDuongThanhAm(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0) {
            a[i] = -a[i];
        }
    }
}

int main() {
    int n, a[MAX_SIZE];

    nhapMang(a, n);
    xuatMang(a, n);

    if (chuaSoDuong(a, n)) cout << "a) Mang chua so duong.\n";
    else cout << "a) Mang khong chua so duong.\n";

    if (toanSoDuong(a, n)) cout << "b) Mang toan so duong.\n";
    else {
        cout << "b) Mang khong toan so duong.\n";
        doiSoDuongThanhAm(a, n);
        cout << "c) Mang sau khi doi so duong thanh so am:\n";
        xuatMang(a, n);
    }

    return 0;
}
