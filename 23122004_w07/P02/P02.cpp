#include <iostream>
#include <cmath>
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

int tongSoChinhPhuong(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int sqrtVal = sqrt(a[i]);
        if (sqrtVal * sqrtVal == a[i]) {
            sum += a[i];
        }
    }
    return sum;
}

int tongSoHoanChinh(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int temp = 1;
        for (int j = 2; j * j <= a[i]; ++j) {
            if (a[i] % j == 0) {
                temp += j;
                if (j * j != a[i])
                    temp += a[i] / j;
            }
        }
        if (temp == a[i]) {
            sum += a[i];
        }
    }
    return sum;
}

bool kiemTraSoNguyenTo(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int tongSoNguyenTo(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (kiemTraSoNguyenTo(a[i])) {
            sum += a[i];
        }
    }
    return sum;
}

bool kiemTraSoDuongDoiXung(int num) {
    int reversedNum = 0, originalNum = num;
    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }
    return originalNum == reversedNum;
}

int tongSoDuongDoiXung(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > 0 && kiemTraSoDuongDoiXung(a[i])) {
            sum += a[i];
        }
    }
    return sum;
}

int main() {
    int n, a[MAX_SIZE];

    nhapMang(a, n);
    xuatMang(a, n);

    cout << "a) Tong cac so chinh phuong la: " << tongSoChinhPhuong(a, n) << endl;
    cout << "b) Tong cac so hoan chinh la: " << tongSoHoanChinh(a, n) << endl;
    cout << "c) Tong cac so nguyen to la: " << tongSoNguyenTo(a, n) << endl;
    cout << "d) Tong cac so duong doi xung la: " << tongSoDuongDoiXung(a, n) << endl;

    return 0;
}
