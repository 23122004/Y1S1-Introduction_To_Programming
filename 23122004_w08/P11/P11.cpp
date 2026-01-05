#include <iostream>
#include <string>
#include <vector>
using namespace std;

int32_t main() {
    string s1, s2;
    cout << "Nhap chuoi S1: "; cin >> s1;
    cout << "Nhap chuoi S2: "; cin >> s2;
    
    int n = s1.size();
    vector<int> res;

    for (int i = 0; i <= s2.size() - n; ++i) {
        string tmp = s2.substr(i, n);
        if (s1 == tmp) res.push_back(i + 1);
    }

    cout << "S1 xuat hien trong S2 " << res.size() << " lan.\n";
    cout << "Tai cac vi tri: ";
    for (int x : res) cout << x << " ";

    return 0;
}