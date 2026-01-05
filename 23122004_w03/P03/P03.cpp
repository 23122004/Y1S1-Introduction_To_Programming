#include <iostream>
#define int long long
using namespace std;

int n, cnt = 0;

int32_t main() {
    cout << "Luu y: 500k tuc la 500000 VND, tuong tu voi 200k, 100k, 50k\n";
    cout << "Nhap so tien muon rut (don vi: VND): ";
    cin >> n; 
    
    for (int a = 0; a <= n / 500000; ++a) {
        int Sum_a = n - a * 500000;
        for (int b = 0; b <= Sum_a / 200000; ++b) {
            int Sum_b = Sum_a - b * 200000;
            for (int c = 0; c <= Sum_b / 100000; ++c) {
                int Sum_c = Sum_b - c * 100000;
                if (Sum_c % 50000 != 0) continue;

                int d = Sum_c / 50000;
                cout << "#" << ++cnt << ": ";
                if (a > 0) cout << a << " to 500K, ";
                if (b > 0) cout << b << " to 200K, ";
                if (c > 0) cout << c << " to 100K, ";
                if (d > 0) cout << d << " to 50K, ";
                cout << "\n";        
            }
        }
    } if (cnt == 0) cout << "Khong co phuong an rut tien.";

    return 0;
}