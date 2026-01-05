#include<iostream>
#define int long long
using namespace std;

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
	int n;
	cout << "Nhap so (he 10): "; cin >> n;
	cout << "-> So chuyen sang he 2: " << covert_Base10_To_Base2(n) << '\n';
	
	string s;
	cout << "Nhap so (he 2): "; cin >> s;
	cout << "-> So chuyen sang he 10: " << covert_Base2_To_Base10(s) << '\n';

	return 0;
}