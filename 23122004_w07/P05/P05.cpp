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

bool kiemTraMangTangGiam(int a[], int n) {
    bool ok1 = 1, ok2 = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) ok1 = 0;
        if (a[i] < a[i + 1]) ok2 = 0;
    }
    return ok1 || ok2;
}

void sapXepTangDan(int a[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
}

int main() {
    int n, a[MAX_SIZE];

    nhapMang(a, n);
    xuatMang(a, n);

    if (kiemTraMangTangGiam(a, n)) cout << "a) Mang co thu tu tang/giam.\n";
    else {
        cout << "a) Mang khong co thu tu tang/giam.\n";
        sapXepTangDan(a, n);
        cout << "b) Mang sau khi sap xep tang dan:\n";
        xuatMang(a, n);
    }

    return 0;
}
