#include <iostream>
using namespace std;

bool checkLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int nDayOfMonth(int m, int y) {
    int isLeap = checkLeapYear(y);
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
        case 4: case 6: case 9: case 11: return 30;
        default:
            if (isLeap == 1) return 29;
            else return 28;
    }
}

void nextDay(int d, int m, int y) {
    cout << "Ngay hom sau cua ngay " << d << "/" << m << "/" << y << " la ngay: ";

    int nDay = nDayOfMonth(m, y);
    if (d < nDay) ++d;
    else if (m < 12) d = 1, ++m;
    else d = m = 1, ++y;

    cout << d << "/" << m << "/" << y << "\n";
}

void prevDay(int d, int m, int y) {
    cout << "Ngay hom truoc cua ngay " << d << "/" << m << "/" << y << " la ngay: ";

    if (d > 1) --d;
    else if (m > 1) d = nDayOfMonth(m - 1, y), --m;
    else d = 31, m = 12, --y;

    cout << d << "/" << m << "/" << y << "\n";
}

int32_t main() {
    int d, m, y, nDay;
    do {
        cout << "Nhap ngay, thang, nam: ";
        cin >> d >> m >> y;

        nDay = nDayOfMonth(m, y);
        if (d < 1 || d > nDay || m < 1 || m > 12)
            cout << "Du lieu khong hop le...\n";
    } while (d < 1 || d > nDay || m < 1 || m > 12);

    cout << "Thang " << m << " co: " << nDay << " ngay\n";
    nextDay(d, m, y);
    prevDay(d, m, y);

    return 0;
}