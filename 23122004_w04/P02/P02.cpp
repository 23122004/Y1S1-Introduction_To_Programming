#include<iostream>
#define int long long
using namespace std;

char base16(int x) {
	if (x < 10) return char(x + '0');
	return char(x - 10 + 'A');
}

string covert_Base10_To_Base16(int x) {
	string str = "";
	while (x > 0) {
		str.push_back(base16(x % 16));
		x /= 16;
	} reverse(str.begin(), str.end());
	return str;
}

int base10(char x) {
	if (isdigit(x)) return x - '0';
	return 10 + x - 'A';
}

int covert_Base16_To_Base10(string s) {
	int mul = 1, res = 0;
	for (int i = (int)s.size() - 1; i >= 0; --i)
		res += mul * base10(s[i]), mul *= 16;
	return res;
}

int32_t main() {
	int n;
	cout << "Nhap so (he 10): "; cin >> n;
	cout << "-> So chuyen sang he 16: " << covert_Base10_To_Base16(n) << '\n';

	string s;
	cout << "Nhap so (he 16): "; cin >> s;
	cout << "-> So chuyen sang he 10: " << covert_Base16_To_Base10(s) << '\n';

	return 0;
}