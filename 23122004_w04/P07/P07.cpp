#include <iostream>
#define int long long
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int c = a % b;
		a = b, b = c;
	} return a;
}

void rutgon(int &x, int &y) {
	int sign = 1;
	if (x < 0) sign *= -1, x = -x;
	if (y < 0) sign *= -1, y = -y;

	int U = gcd(x, y);
	x /= U, y /= U;
	x *= sign;
}

int32_t main() {
	cout << "Nhap tu va mau so cua phan so 1: ";
	int x1, y1; cin >> x1 >> y1;

	cout << "Nhap tu va mau so cua phan so 2: ";
	int x2, y2; cin >> x2 >> y2;

	rutgon(x1, y1);
	cout << "Phan so 1 sau khi rut gon: " << x1 << "/" << y1 << "\n";

	rutgon(x2, y2);
	cout << "Phan so 2 sau khi rut gon: " << x2 << "/" << y2 << "\n";

	int res1_x = x1 * y2 + x2 * y1, res1_y = y1 * y2;
	rutgon(res1_x, res1_y);
	cout << "Tong 2 phan so la: " << res1_x << "/" << res1_y << "\n";

	int res2_x = x1 * y2 - x2 * y1, res2_y = y1 * y2;
	rutgon(res2_x, res2_y);
	cout << "Hieu 2 phan so la: " << res2_x << "/" << res2_y << "\n";

	return 0;
}