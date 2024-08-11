#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// Hàm kiểm tra mảng có chứa toàn bộ số nguyên tố hay không
bool allPrime(const vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		if (!isPrime(a[i])) return false;
	}
	return true;
}

// Hàm kiểm tra mảng có đối xứng hay không
bool isSymmetric(const vector<int>& a) {
	for (int i = 0; i < a.size() / 2; i++) {
		if (a[i] != a[a.size() - 1 - i]) return false;
	}
	return true;
}

// Hàm kiểm tra mảng có tăng dần/giảm dần/không tăng không giảm
int checkOrder(const vector<int>& a) {
	bool increasing = true;
	bool decreasing = true;
	for (int i = 1; i < a.size(); i++) {
		if (a[i] < a[i - 1]) increasing = false;
		if (a[i] > a[i - 1]) decreasing = false;
	}
	if (increasing) return 1; // Tăng dần
	if (decreasing) return -1; // Giảm dần
	return 0; // Không tăng không giảm
}

int main() {
	int n;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;

	vector<int> a(n);

	cout << "Nhap cac phan tu cua mang: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Kiểm tra mảng có chứa toàn bộ số nguyên tố hay không
	if (allPrime(a)) {
		cout << "Mang chua toan bo so nguyen to" << endl;
	}
	else {
		cout << "Mang khong chua toan bo so nguyen to" << endl;
	}

	// Kiểm tra mảng có đối xứng hay không
	if (isSymmetric(a)) {
		cout << "Mang doi xung" << endl;
	}
	else {
		cout << "Mang khong doi xung" << endl;
	}

	// Kiểm tra mảng có tăng dần/giảm dần/không tăng không giảm
	int order = checkOrder(a);
	if (order == 1) {
		cout << "Mang tang dan" << endl;
	}
	else if (order == -1) {
		cout << "Mang giam dan" << endl;
	}
	else {
		cout << "Mang khong tang khong giam" << endl;
	}

	return 0;
}