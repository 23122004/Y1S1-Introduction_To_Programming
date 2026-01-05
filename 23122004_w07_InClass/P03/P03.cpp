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

void Sort(int a[], int n) {
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			if (a[i] > a[j]) swap(a[i], a[j]);
}

void Divide(int a[], int n, int Odd[], int& n_O, int Even[], int& n_E) {
	for (int i = 0; i < n; ++i)
		if (a[i] & 1) Odd[n_O++] = a[i];
		else Even[n_E++] = a[i];
}

int32_t main() {
	int n, a[1000];
	NhapMang(a, n);
	XuatMang(a, n);

	Sort(a, n); 
	cout << "Sau sap xep, "; XuatMang(a, n);

	int n_O = 0, n_E = 0, Odd[1000], Even[1000];
	Divide(a, n, Odd, n_O, Even, n_E);

	cout << "Mang so chan, "; XuatMang(Even, n_E);
	cout << "Mang so le, "; XuatMang(Odd, n_O);

	return 0;
}
