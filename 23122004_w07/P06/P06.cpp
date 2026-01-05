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

bool kiemTraXTrongMang(int a[], int n, int X) {
    for (int i = 0; i < n; ++i) {
        if (a[i] == X) {
            return true;
        }
    }
    return false;
}

void chenXVaoMang(int a[], int& n, int X) {
    for (int i = n - 1; i > 0; --i) {
        a[i + 1] = a[i];
    } a[1] = X, ++n;
}

int main() {
    int a[MAX_SIZE];
    int n, X;

    nhapMang(a, n);
    xuatMang(a, n);

    cout << "Nhap gia tri X can kiem tra va chen: ";
    cin >> X;

    if (kiemTraXTrongMang(a, n, X)) cout << "a) Gia tri " << X << " co trong mang.\n";
    else {
        cout << "a) Gia tri " << X << " khong co trong mang.\n";
        chenXVaoMang(a, n, X);
        cout << "b) Mang sau khi chen " << X << ":\n";
        xuatMang(a, n);
    }

    return 0;
}
