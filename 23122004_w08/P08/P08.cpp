#include <iostream>
#include <string>
using namespace std;

int32_t main() {
    cout << "Nhap ho ten: ";
    string str;
    getline(cin, str);

    bool ok = 1;
    string res = "";

    for (char c : str) {
        if (c == ' ') {
            if (ok) continue;
            ok = 1;
        } else if (ok) {
            c = toupper(c);
            ok = 0;
        } else c = tolower(c);
        res.push_back(c);
    }

    if (!res.empty() && res.back() == ' ')
        res.pop_back();

    cout << "Ho ten sau khi chuan hoa: " << res << "\n";

    return 0;
}