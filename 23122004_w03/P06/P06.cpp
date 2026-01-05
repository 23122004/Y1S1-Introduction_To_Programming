#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

int n;

int32_t main() {
    cout << "Nhap so giay: ";
    cin >> n;

    while (n--) {
        time_t cur = time(0);
        tm dir;
        localtime_s(&dir, &cur);

        int S = dir.tm_sec;
        int M = dir.tm_min;
        int H = dir.tm_hour;
        bool AM = 1;

        if (H > 12) {
            H -= 12;
            AM = 0;
        }

        cout << "Gio hien tai: " << H << ":" << M << ":" << S << " ";
        if (AM) cout << "AM\n"; else cout << "PM\n";
        if(S == 0) Beep(523, 1000);
        
        if (_kbhit())
        {
            char ch = _getch();
            if (ch == 27) break;
        }

        if (S == 0) Sleep(0);
        else Sleep(1000);
    }

    return(0);
}