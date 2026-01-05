#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int32_t main() {
    cout << "Nhap xau S: ";
    string s; cin >> s;

    sort(s.begin(), s.end());
    cout << "Xau S sau khi sap xep: " << s << '\n';

    return 0;
}