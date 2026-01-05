#include<iostream>
#define int long long
using namespace std;

int32_t main() {
	int n, res = 1;
	cout << "Nhap n = "; cin >> n;

	for (int i = 2 - (n & 1); i <= n; i += 2)
		res *= i;
	cout << n << "!! = " << res;

	return 0;
}