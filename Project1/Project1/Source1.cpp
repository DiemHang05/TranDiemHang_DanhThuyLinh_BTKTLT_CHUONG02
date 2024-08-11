#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n == 2 || n == 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6) {
		if (n % i == 0 || n % (i + 2) == 0) return false;
	}
	return true;
}

// Hàm kiểm tra mảng có chứa toàn bộ số nguyên tố hay không
bool isAllPrime(const vector<int>& arr) {
	for (int num : arr) {
		if (!isPrime(num)) return false;
	}
	return true;
}

// Hàm kiểm tra mảng có đối xứng hay không
bool isSymmetric(const vector<int>& arr) {
	int n = arr.size();
	for (int i = 0; i < n / 2; ++i) {
		if (arr[i] != arr[n - 1 - i]) return false;
	}
	return true;
}

// Hàm kiểm tra mảng có tăng dần hay không
bool isAscending(const vector<int>& arr) {
	for (size_t i = 1; i < arr.size(); ++i) {
		if (arr[i] < arr[i - 1]) return false;
	}
	return true;
}

// Hàm kiểm tra mảng có giảm dần hay không
bool isDescending(const vector<int>& arr) {
	for (size_t i = 1; i < arr.size(); ++i) {
		if (arr[i] > arr[i - 1]) return false;
	}
	return true;
}

// Hàm kiểm tra mảng không tăng không giảm
bool isNotIncreasingNotDecreasing(const vector<int>& arr) {
	bool increasing = false;
	bool decreasing = false;
	for (size_t i = 1; i < arr.size(); ++i) {
		if (arr[i] > arr[i - 1]) increasing = true;
		if (arr[i] < arr[i - 1]) decreasing = true;
	}
	return !increasing || !decreasing;
}

int main() {
	// Khai báo mảng và nhập dữ liệu
	vector<int> arr = { 3, 5, 7, 11, 13 }; // Ví dụ mảng
	// vector<int> arr = {3, 5, 7, 11, 2}; // Thay đổi mảng để kiểm tra

	// Kiểm tra mảng có chứa toàn bộ số nguyên tố
	if (isAllPrime(arr)) {
		cout << "Mang chua toan bo so nguyen to." << endl;
	}
	else {
		cout << "Mang khong chua toan bo so nguyen to." << endl;
	}

	// Kiểm tra mảng có đối xứng
	if (isSymmetric(arr)) {
		cout << "Mang doi xung." << endl;
	}
	else {
		cout << "Mang khong doi xung." << endl;
	}

	// Kiểm tra mảng có tăng dần
	if (isAscending(arr)) {
		cout << "Mang tang dan." << endl;
	}
	else if (isDescending(arr)) {
		cout << "Mang giam dan." << endl;
	}
	else if (isNotIncreasingNotDecreasing(arr)) {
		cout << "Mang khong tang khong giam." << endl;
	}
	else {
		cout << "Mang khong xac dinh duoc tinh chat." << endl;
	}

	return 0;
}
