#include <iostream>
#include <cstdlib> // abs

using namespace std;

// Khai báo cấu trúc PhanSo
struct PhanSo {
	int tuSo;
	int mauSo;
};

// Hàm tự định nghĩa tính GCD
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return abs(a);
}

// Hàm nhập phân số
void nhapPhanSo(PhanSo &ps) {
	cout << "Nhập tử số: ";
	cin >> ps.tuSo;
	do {
		cout << "Nhập mẫu số (khác 0): ";
		cin >> ps.mauSo;
		if (ps.mauSo == 0) {
			cout << "Mẫu số không thể bằng 0. Vui lòng nhập lại." << endl;
		}
	} while (ps.mauSo == 0);
}

// Hàm xuất phân số
void xuatPhanSo(const PhanSo &ps) {
	cout << ps.tuSo << "/" << ps.mauSo;
}

// Hàm tối giản phân số
void toiGianPhanSo(PhanSo &ps) {
	int gcdValue = gcd(abs(ps.tuSo), abs(ps.mauSo));
	ps.tuSo /= gcdValue;
	ps.mauSo /= gcdValue;
	// Đảm bảo mẫu số dương
	if (ps.mauSo < 0) {
		ps.tuSo = -ps.tuSo;
		ps.mauSo = -ps.mauSo;
	}
}

// Hàm cộng hai phân số
PhanSo tongPhanSo(const PhanSo &ps1, const PhanSo &ps2) {
	PhanSo kq;
	kq.tuSo = ps1.tuSo * ps2.mauSo + ps2.tuSo * ps1.mauSo;
	kq.mauSo = ps1.mauSo * ps2.mauSo;
	toiGianPhanSo(kq);
	return kq;
}

// Hàm trừ hai phân số
PhanSo hieuPhanSo(const PhanSo &ps1, const PhanSo &ps2) {
	PhanSo kq;
	kq.tuSo = ps1.tuSo * ps2.mauSo - ps2.tuSo * ps1.mauSo;
	kq.mauSo = ps1.mauSo * ps2.mauSo;
	toiGianPhanSo(kq);
	return kq;
}

// Hàm nhân hai phân số
PhanSo tichPhanSo(const PhanSo &ps1, const PhanSo &ps2) {
	PhanSo kq;
	kq.tuSo = ps1.tuSo * ps2.tuSo;
	kq.mauSo = ps1.mauSo * ps2.mauSo;
	toiGianPhanSo(kq);
	return kq;
}

// Hàm chia hai phân số
PhanSo thuongPhanSo(const PhanSo &ps1, const PhanSo &ps2) {
	PhanSo kq;
	kq.tuSo = ps1.tuSo * ps2.mauSo;
	kq.mauSo = ps1.mauSo * ps2.tuSo;
	toiGianPhanSo(kq);
	return kq;
}

int main() {
	PhanSo ps1, ps2;

	cout << "Nhập phân số thứ nhất:" << endl;
	nhapPhanSo(ps1);
	cout << "Nhập phân số thứ hai:" << endl;
	nhapPhanSo(ps2);

	cout << "Phân số thứ nhất: ";
	xuatPhanSo(ps1);
	cout << "\nPhân số thứ hai: ";
	xuatPhanSo(ps2);
	cout << endl;

	PhanSo tong = tongPhanSo(ps1, ps2);
	cout << "Tổng: ";
	xuatPhanSo(tong);
	cout << endl;

	PhanSo hieu = hieuPhanSo(ps1, ps2);
	cout << "Hiệu: ";
	xuatPhanSo(hieu);
	cout << endl;

	PhanSo tich = tichPhanSo(ps1, ps2);
	cout << "Tích: ";
	xuatPhanSo(tich);
	cout << endl;

	PhanSo thuong = thuongPhanSo(ps1, ps2);
	cout << "Thương: ";
	xuatPhanSo(thuong);
	cout << endl;

	return 0;
}
