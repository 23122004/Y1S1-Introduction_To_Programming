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

double Average(int a[], int n) {
	int s = 0;
	for (int i = 0; i < n; ++i)
		s += a[i];
	return (double)s / n;
}

void FindMax(int a[], int n, int& mx_1, int& mx_2) {
	for(int i = 0; i < n; ++i)
		if (a[i] >= mx_1) {
			mx_2 = mx_1;
			mx_1 = a[i];
		} else if(a[i] > mx_2) 
			mx_2 = a[i];
}

int32_t main() {
	int n, s[1000];
	NhapMang(s, n);
	XuatMang(s, n);

	double tb = Average(s, n);
	int mx_1 = INT_MIN, mx_2 = INT_MIN;
	FindMax(s, n, mx_1, mx_2);

	cout << "Trung binh cua mang la: " << tb << '\n';
	cout << "So lon nhat trong mang la: " << mx_1 << '\n';

	cout << "So lon nhi trong mang la: ";
	if (n > 1) cout << mx_2 << '\n';
	else cout << "Khong co\n";

	return 0;
}
