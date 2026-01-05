#include<iostream>
#include<string>
using namespace std;

int32_t main() {
	string s, tmp;
	cout << "Nhap chuoi: ";
	getline(cin, s);

	tmp = s;
	reverse(tmp.begin(), tmp.end());
	if (tmp == s) cout << "La chuoi doi xung\n";
	else cout << "Khong la chuoi doi xung\n";

	return 0;
}