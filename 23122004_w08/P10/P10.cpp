#include <iostream>
#include <string>
#define int long long
using namespace std;

int32_t main() {
    cout << "Nhap so nguyen: ";
    int n; cin >> n;

    bool sign = 0;
    if (n < 0) sign = 1;

    string res = "";
    while (n >= 1000) {
        res = ',' + to_string(n % 1000) + res;
        n /= 1000;
    } 
    
    res = to_string(n) + res;
    if (sign) res = '-' + res;
    cout << "Ket qua la: " << res << '\n';

    return 0;
}