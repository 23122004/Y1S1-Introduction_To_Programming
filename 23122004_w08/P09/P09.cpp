#include <iostream>
#include <string>
using namespace std;

int32_t main() {
    cout << "Nhap chuoi: ";
    string str;
    getline(cin, str);

    int i, n;
    cout << "Nhap vi tri i = "; cin >> i; --i;
    cout << "Nhap so luong ky tu muon xoa: "; cin >> n;

    n = min(n, (int)str.size() - i);
    for (int j = i; j + n < str.size(); ++j)
        str[j] = str[j + n];

    while (n--) str.pop_back();
    cout << "Chuoi sau khi xoa: " << str << '\n';

    return 0;
}