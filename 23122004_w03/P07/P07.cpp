#include <iostream>
#include <string>
using namespace std;

int n;
string s;

bool check1() {
    int S1 = 0, S2 = 1;
    for (char c : s) {
        S1 += (c - '0');
        S2 *= (c - '0');
    } return S1 == S2;
}

bool check2() {
    bool ok1 = 1, ok2 = 1;
    int pre = -1;

    for (char c : s)
        if (pre == -1) pre = c - '0';
        else {
            int cur = c - '0';
            if (cur >= pre) ok1 = 0;
            else ok2 = 0;
        }
    return ok1 || ok2;
}

bool check3() {
    int sz = (int)s.size();
    for (int i = 0; i * 2 <= sz; ++i)
        if (s[i] != s[sz - i - 1]) return 0;
    return 1;
}

bool check4() {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return 0;
    return 1;
}

bool check5() {
    int Sum = 0;
    for(int i = 2; i * i <= n; ++i)
        if (n % i == 0) {
            Sum += i;
            if (i * i != n)
                Sum += n / i;
        }
    return (Sum + 1) == n;
}

int32_t main() {
    cout << "Nhap so nguyen n = ";
    cin >> n; s = to_string(n);

    if (check1()) cout << "Tong cac chu so bang tich\n";
    else cout << "Tong cac chu so khong bang tich\n";

    if (check2()) cout << "Cac chu so co tang/giam dan\n";
    else cout << "Cac chu so khong co tang/giam dan\n";

    if (check3()) cout << "So nay doi xung\n";
    else cout << "Khong phai la so doi xung\n";

    if (check4()) cout << "So nguyen to\n";
    else cout << "Khong phai la so nguyen to\n";

    if (check5()) cout << "So hoan chinh\n";
    else cout << "Khong phai la so hoan chinh\n";

    return 0;
}