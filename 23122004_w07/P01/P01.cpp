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

int tongPhanTuKhongAm(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 0) {
            sum += a[i];
        }
    }
    return sum;
}

int tongPhanTuChiaHetCho3(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 3 == 0) {
            sum += a[i];
        }
    }
    return sum;
}

int tongPhanTuChuSoLe(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int firstDigit = abs(a[i]);
        while (firstDigit > 9) firstDigit /= 10;
        if (firstDigit % 2 != 0) {
            sum += a[i];
        }
    }
    return sum;
}

int main() {
    int n, a[MAX_SIZE];

    nhapMang(a, n);
    xuatMang(a, n);

    cout << "a) Tong cac phan tu khong am la: " << tongPhanTuKhongAm(a, n) << endl;
    cout << "b) Tong cac phan tu chia het cho 3 la: " << tongPhanTuChiaHetCho3(a, n) << endl;
    cout << "c) Tong cac phan tu co chu so dau tien la so le la: " << tongPhanTuChuSoLe(a, n) << endl;

    return 0;
}
