#include <iostream>
#include <string>
#include <map>
using namespace std;

int32_t main() {
    cout << "Nhap chuoi: ";
    string str;
    getline(cin, str);

    map<char, int> cnt;
    char res; int d = 0;

    for(char c : str)
        if (++cnt[c] > d) {
            d = cnt[c];
            res = c;
        }

    cout << "Ky tu xuat hien nhat: " << res << '\n';
    cout << "So lan xuat hien: " << d << '\n';

    return 0;
}