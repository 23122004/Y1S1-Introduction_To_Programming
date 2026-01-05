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

string covert_Base10_To_Base2(int x) {
	string str = "";
	while (x > 0) {
		str.push_back(char(x % 2 + '0'));
		x /= 2;
	} reverse(str.begin(), str.end());
	return str;
}

int covert_Base2_To_Base10(string s) {
	int mul = 1, res = 0;
	for (int i = (int)s.size() - 1; i >= 0; --i)
		res += mul * (s[i] - '0'), mul *= 2;
	return res;
}

int32_t main() {
	string t;
	cout << "Nhap so (he 2): "; cin >> t;
	cout << "-> So chuyen sang he 16: " << covert_Base10_To_Base16(covert_Base2_To_Base10(t)) << '\n';

	string s;
	cout << "Nhap so (he 16): "; cin >> s;
	cout << "-> So chuyen sang he 2: " << covert_Base10_To_Base2(covert_Base16_To_Base10(s)) << '\n';

	return 0;
}