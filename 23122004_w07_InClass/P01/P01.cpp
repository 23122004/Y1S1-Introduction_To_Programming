#include <iostream>
using namespace std;

void NhapMang(int a[], int& n) {
	cout << "Nhap so phan tu: ";
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cout << "Phan tu a[" << i << "]: ";
		cin >> a[i];
	}
}

void XuatMang(int a[], int n) {
	cout << "Cac phan tu cua mang: ";
	for (int i = 0; i < n; ++i)
		cout << a[i] << " \n"[i == n - 1];
}

void Find(int a[], int n, int x) {
	bool isHave = 0;
	cout << "Cac vi tri chua phan tu x: ";

	for(int i = 0; i < n; ++i)
		if (a[i] == x) {
			cout << i << ' ';
			isHave = 1;
		}

	if (!isHave) 
		cout << "Khong co";
}

int32_t main() {
	int n, a[1000];
	NhapMang(a, n);
	XuatMang(a, n);

	cout << "Nhap x = ";
	int x; cin >> x;
	Find(a, n, x);

	return 0;
}
