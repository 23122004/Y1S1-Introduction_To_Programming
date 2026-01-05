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
    cout << "Mang da nhap la:\n";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool kiemTraMangDoiXung(int a[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        if (a[i] != a[n - i - 1]) {
            return false;
        }
    }
    return true;
}

bool kiemTraMangDanXenAmDuong(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if ((a[i] >= 0 && a[i + 1] >= 0) || (a[i] < 0 && a[i + 1] < 0)) {
            return false;
        }
    }
    return true;
}

bool kiemTraMangCacCapPhanTuKhacNhau(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] == a[i + 1]) {
            return false;
        }
    }
    return true;
}

bool kiemTraMangCapSoCong(int a[], int n) {
    if (n <= 2) {
        return true;
    }

    int diff = a[1] - a[0];

    for (int i = 2; i < n; ++i) {
        if (a[i] - a[i - 1] != diff) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, a[MAX_SIZE];

    nhapMang(a, n);
    xuatMang(a, n);

    if (kiemTraMangDoiXung(a, n)) cout << "a) Mang doi xung.\n";
    else cout << "a) Mang khong doi xung.\n";

    if (kiemTraMangDoiXung(a, n)) cout << "b) Mang dan xen am duong.\n";
    else cout << "b) Mang khong dan xen am duong.\n";

    if (kiemTraMangCacCapPhanTuKhacNhau(a, n)) cout << "c) Mang co tat ca cac cap phan tu khac nhau.\n";
    else cout << "c) Mang co cap phan tu lien tiep giong nhau.\n";

    if (kiemTraMangCapSoCong(a, n)) cout << "d) Mang lap thanh cap so cong.\n";
    else cout << "d) Mang khong lap thanh cap so cong.\n";

    return 0;
}
