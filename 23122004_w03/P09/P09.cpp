#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b, b = tmp;
    } return a;
}

int32_t main() {
    cout << "Nhap 2 so nguyen duong m, n: ";
    int m, n; cin >> m >> n;
    
    cout << "Uoc chung lon nhat la: ";
    cout << gcd(m, n);

    return 0;
}