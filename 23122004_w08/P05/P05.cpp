#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
void NhapMang(int a[], int& n, string s) {
	cout << "Nhap phan tu cua mang " << s << ":\n";
	for (int i = 1; i <= n; ++i) {
		cout << '\t' << s << "[" << i << "]: ";
		cin >> a[i];
	}
}

void XuatMang(int a[], int n) {
	for (int i = 1; i <= n; ++i)
		cout << a[i] << " \n"[i == n];
}

void XoaMang(int a[], int& n, int x) {
	for (int i = x; i < n; ++i)
		a[i] = a[i + 1];
	--n;
}

int32_t main() {
	int n, na, nb, a[MAX_SIZE], b[MAX_SIZE];
	cout << "Nhap so luong phan tu: ";
	cin >> n;

	NhapMang(a, n, "A");
	NhapMang(b, n, "B");

	na = nb = n;
	while (true) {
		bool ok = 1;
		int cur = -1;

		for (int i = 1; i <= na; ++i) {
			for (int j = 1; j <= nb; ++j)
				if (a[i] == b[j]) {
					cur = a[i], ok = 0;
					break;
				}
			if (!ok) break;
		}
			
		for (int i = na - 1; i > 0; --i) 
			if (a[i] == cur) XoaMang(a, na, i);
		
		for (int i = nb - 1; i > 0; --i)
			if (b[i] == cur) XoaMang(b, nb, i);

		if (ok) break;
	}

	cout << "Sau khi xoa phan tu trung nhau cua 2 mang A va B.\n";
	cout << "Mang A: "; XuatMang(a, na); 
	cout << "Mang B: "; XuatMang(b, nb); 

	return 0;
}