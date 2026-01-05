#include<iostream>
#include<string>
using namespace std;

int32_t main() {
	string s, a, b, c;
	cout << "Nhap chuoi: ";
	getline(cin, s);

	a = s;
	for (int i = 0; i < a.size(); ++i)
		a[i] = tolower(a[i]);

	cout << "a) Chuoi dang chu thuong: " << a << '\n';

	b = s;
	for (int i = 0; i < b.size(); ++i)
		b[i] = toupper(b[i]);

	cout << "b) Chuoi dang chu hoa: " << b << '\n';

	c = s;
	bool ok = 1;

	for (int i = 0; i < c.size(); ++i) {
		if (c[i] == ' ') ok = 1;
		else if (ok) c[i] = toupper(c[i]), ok = 0;
		else c[i] = tolower(c[i]);
	}

	cout << "c) Chuoi dang chu Title Case: " << c << '\n';

	return 0;
}