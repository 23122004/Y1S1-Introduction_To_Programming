#include <iostream>
using namespace std;

int32_t main() {
    int a = 0, b = 1, c = 1, k;
    cout << "Nhap so nguyen duong k: ";
    cin >> k;

    if (k == 0) c = a;
    else while (k > 1) {
        c = a + b;
        a = b, b = c;
        --k;
    }

    cout << "Phan tu thu k cua day Fibo la: ";
    cout << c;

    return 0;
}