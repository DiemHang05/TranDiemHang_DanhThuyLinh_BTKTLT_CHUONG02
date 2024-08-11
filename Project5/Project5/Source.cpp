#include <iostream>
#include <cmath>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

// Hàm đếm số phần tử là số nguyên tố
int countPrimes(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			count++;
		}
	}
	return count;
}

// Hàm tìm vị trí số lớn nhất (cuối cùng) trong mảng
int findLastMaxPosition(int a[], int n) {
	int maxPos = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] >= a[maxPos]) {
			maxPos = i;
		}
	}
	return maxPos;
}

// Hàm kiểm tra mảng có toàn số chẵn không
bool isAllEven(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			return false;
		}
	}
	return true;
}

// Hàm kiểm tra mảng có phải là dãy số chẵn lẻ xen kẽ không
bool isAlternatingEvenOdd(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if ((a[i - 1] % 2 == 0 && a[i] % 2 == 0) || (a[i - 1] % 2 != 0 && a[i] % 2 != 0)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n;

	cout << "Nhập số lượng phần tử của mảng: ";
	cin >> n;

	int a[n];
	cout << "Nhập các phần tử của mảng: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// Xuất các phần tử
	cout << "Các phần tử của mảng: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	// Đếm số phần tử là số nguyên tố
	int primeCount = countPrimes(a, n);
	cout << "Số lượng phần tử là số nguyên tố: " << primeCount << endl;

	// Tìm vị trí số lớn nhất (cuối cùng) của mảng
	int lastMaxPos = findLastMaxPosition(a, n);
	cout << "Vị trí số lớn nhất (cuối cùng) trong mảng: " << lastMaxPos << endl;

	// Kiểm tra mảng có toàn số chẵn không
	if (isAllEven(a, n)) {
		cout << "Mảng có toàn số chẵn." << endl;
	}
	else {
		cout << "Mảng không có toàn số chẵn." << endl;
	}

	// Kiểm tra mảng có phải là dãy số chẵn lẻ xen kẽ không
	if (isAlternatingEvenOdd(a, n)) {
		cout << "Mảng là dãy số chẵn lẻ xen kẽ." << endl;
	}
	else {
		cout << "Mảng không phải là dãy số chẵn lẻ xen kẽ." << endl;
	}

	return 0;
}
