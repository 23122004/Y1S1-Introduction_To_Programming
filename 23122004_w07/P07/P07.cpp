#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

void nhapMang(int a[], int b[], int& n) {
    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    cout << "Nhap cac phan tu cua mang A:\n";
    for (int i = 0; i < n; ++i) {
        cout << "a[" << i << "] = ";
        cin >> a[i];
    }

    cout << "Nhap cac phan tu cua mang B:\n";
    for (int i = 0; i < n; ++i) {
        cout << "b[" << i << "] = ";
        cin >> b[i];
    }
}

void xuatMang(int a[], int n, string chr) {
    cout << "Mang " << chr << " da nhap la: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
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

void tronHaiMang(int aA[], int aB[], int n, int aC[], int& nC) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < n) {
        if (aA[i] < aB[j]) {
            aC[k++] = aA[i++];
        }
        else {
            aC[k++] = aB[j++];
        }
    }

    while (i < n) {
        aC[k++] = aA[i++];
    }

    while (j < n) {
        aC[k++] = aB[j++];
    }

    nC = k;
}

int main() {
    int aA[MAX_SIZE], aB[MAX_SIZE], aC[2 * MAX_SIZE];
    int n, nC;

    cout << "a) ";
    nhapMang(aA, aB, n);
    xuatMang(aA, n, "A");
    xuatMang(aB, n, "B");
    
    sapXepTangDan(aA, n);
    xuatMang(aA, n, "A sau khi sap xep tang dan");

    sapXepTangDan(aB, n);
    xuatMang(aB, n, "B sau khi sap xep tang dan");

    tronHaiMang(aA, aB, n, aC, nC);
    xuatMang(aC, nC, "C sau khi tron va sap xep tang dan");

    return 0;
}
