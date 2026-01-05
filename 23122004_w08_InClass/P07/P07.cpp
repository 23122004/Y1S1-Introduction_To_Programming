#include<iostream>
#include<string>
using namespace std;

int32_t main() {
	string s;
	cout << "Nhap chuoi: ";
	getline(cin, s);

	reverse(s.begin(), s.end());
	cout << "Chuoi dao nguoc la: " << s;

	return 0;
}