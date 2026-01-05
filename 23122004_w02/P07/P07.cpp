#include <iostream>
using namespace std;

int TinhTien(double L, double R) {
    double sum = 0;
    if (0.0 <= L && L <= 7.0) {
         if (R <= 7.0) sum += (R - L) * 3000 * ((R - L) > 2.0 ? 0.85 : 1.0);
         else if(R <= 17.0) sum += (7.0 - L) * 3000 * ((7.0 - L) > 2.0 ? 0.85 : 1.0) + (R - 7.0) * 6000 * ((R - 7.0) > 6.0 ? 0.9 : 1.0);
         else sum += (7.0 - L) * 3000 * ((7.0 - L) > 2.0 ? 0.85 : 1.0) + 54000 + (R - 17.0) * 4500 * ((R - 17.0) > 4.0 ? 0.88 : 1.0);
    }

    if (7.0 <= L && L <= 17.0) {
        if (R <= 17.0) sum += (R - L) * 6000 * ((R - L) > 6.0 ? 0.9 : 1.0);
        else sum += (17.0 - L) * 6000 * ((17.0 - L) > 6.0 ? 0.9 : 1.0) + (R - 17.0) * 4500 * ((R - 17.0) > 4.0 ? 0.88 : 1.0);
    }

    if (17.0 <= L && L <= 24.0) 
        sum += (R - L) * 4500 * ((R - L) > 4.0 ? 0.88 : 1.0);    
    return sum;
}

int32_t main() {
    double L, R;
    cout << "Nhap gio bat dau: "; cin >> L;
    cout << "Nhap gio ket thuc: "; cin >> R;

    cout << "So tien phai tra: "; 
    if (L <= R) cout << TinhTien(L, R) << "\n";
    else cout << TinhTien(L, 24) + TinhTien(0, R) << "\n";

    return 0;
}