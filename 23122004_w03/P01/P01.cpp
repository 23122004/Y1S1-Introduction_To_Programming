#include <iostream>
#define int long long
using namespace std;

int n, k, gt[20];
double S1, S2, S3;

int32_t main() {
    cout << "Nhap so nguyen n = "; cin >> n;
    cout << "Nhap so nguyen k = "; cin >> k;

    gt[0] = 1;
    for (int i = 1; i < 20; ++i)
        gt[i] = gt[i - 1] * i;

    for (int i = 1; i <= n; ++i)
        S1 += 1.0 / i;

    for (int i = 2; i <= 2 * n + 1; ++i)
        if(i & 1) S2 -= (double)(i) / gt[i - 1];
        else S2 += (double)(i) / gt[i - 1];

    S3 = (double)(gt[n] / gt[k]) / gt[n - k];

    cout << "S1 = " << S1 << "\n";
    cout << "S2 = " << S2 << "\n";
    cout << "S3 = " << S3 << "\n";

    return 0;
}