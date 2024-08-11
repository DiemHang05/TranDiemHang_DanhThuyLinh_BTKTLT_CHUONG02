#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Hàm nhập/xuất mảng a
void inputArray(int a[], int n) {
	cout << "Nhập " << n << " phần tử của mảng: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void printArray(int a[], int n) {
	cout << "Mảng a: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// Tìm max/min của mảng a
int findMax(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int findMin(int a[], int n) {
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min) {
			min = a[i];
		}
	}
	return min;
}

// Đếm số phần tử chẵn/lẻ trong a
int countEven(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			count++;
		}
	}
	return count;
}

int countOdd(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			count++;
		}
	}
	return count;
}

// Tìm kiếm phần tử x trong a
int linearSearch(int a[], int n, int x) {
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

int binarySearch(int a[], int n, int x) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (a[mid] == x) {
			return mid;
		}
		else if (a[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;
}

// Đếm số lần xuất hiện của phần tử x
int countElement(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == x) {
			count++;
		}
	}
	return count;
}

// Đếm số phần tử lớn hơn x
int countGreaterThan(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > x) {
			count++;
		}
	}
	return count;
}

// Tính tổng các phần tử của a
int sumArray(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return sum;
}

// Xuất các số nguyên tố trong a
void printPrime(int a[], int n) {
	cout << "Các số nguyên tố trong mảng: ";
	for (int i = 0; i < n; i++) {
		if (a[i] < 2) {
			continue;
		}
		bool isPrime = true;
		for (int j = 2; j <= sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				isPrime = false;
				break;
			}
		}
		if (isPrime) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
}

// Xuất các số hoàn thiện trong a
void printPerfect(int a[], int n) {
	cout << "Các số hoàn thiện trong mảng: ";
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 1; j < a[i]; j++) {
			if (a[i] % j == 0) {
				sum += j;
			}
		}
		if (sum == a[i]) {
			cout << a[i] << " ";
		}
	}
	cout << endl;
}

// Xuất các phần tử ở vị trí chẵn/lẻ
void printEvenPositions(int a[], int n) {
	cout << "Các phần tử ở vị trí chẵn: ";
	for (int i = 0; i < n; i += 2) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void printOddPositions(int a[], int n) {
	cout << "Các phần tử ở vị trí lẻ: ";
	for (int i = 1; i < n; i += 2) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// Xuất giá trị max/min kèm theo vị trí
void printMaxMin(int a[], int n) {
	int max = findMax(a, n);
	int min = findMin(a, n);
	cout << "Giá trị max: " << max << " (vị trí: ";
	for (int i = 0; i < n; i++) {
		if (a[i] == max) {
			cout << i << " ";
		}
	}
	cout << ")" << endl;
	cout << "Giá trị min: " << min << " (vị trí: ";
	for (int i = 0; i < n; i++) {
		if (a[i] == min) {
			cout << i << " ";
		}
	}
	cout << ")" << endl;
}

// Ghép 2 dãy tăng dần b và c thành dãy a tăng dần
void mergeArrays(int b[], int m, int c[], int n, int a[], int& k) {
	int i = 0, j = 0, index = 0;
	while (i < m && j < n) {
		if (b[i] < c[j]) {
			a[index++] = b[i++];
		}
		else {
			a[index++] = c[j++];
		}
	}
	while (i < m) {
		a[index++] = b[i++];
	}
	while (j < n) {
		a[index++] = c[j++];
	}
	k = index;
}

int main() {
	int n, a[100];
	cout << "Nhập số phần tử của mảng: ";
	cin >> n;
	inputArray(a, n);
	printArray(a, n);

	cout << "Giá trị lớn nhất: " << findMax(a, n) << endl;
	cout << "Giá trị nhỏ nhất: " << findMin(a, n) << endl;
	cout << "Số phần tử chẵn: " << countEven(a, n) << endl;
	cout << "Số phần tử lẻ: " << countOdd(a, n) << endl;

	int x;
	cout << "Nhập phần tử cần tìm: ";
	cin >> x;
	int linearPos = linearSearch(a, n, x);
	if (linearPos == -1) {
		cout << "Không tìm thấy " << x << " trong mảng" << endl;
	}
	else {
		cout << "Tìm thấy " << x << " tại vị trí " << linearPos << " (tìm kiếm tuyến tính)" << endl;
	}
	int binaryPos = binarySearch(a, n, x);
	if (binaryPos == -1) {
		cout << "Không tìm thấy " << x << " trong mảng" << endl;
	}
	else {
		cout << "Tìm thấy " << x << " tại vị trí " << binaryPos << " (tìm kiếm nhị phân)" << endl;
	}
	cout << "Số lần xuất hiện của " << x << ": " << countElement(a, n, x) << endl;
	cout << "Số phần tử lớn hơn " << x << ": " << countGreaterThan(a, n, x) << endl;
	cout << "Tổng các phần tử: " << sumArray(a, n) << endl;
	printPrime(a, n);
	printPerfect(a, n);
	printEvenPositions(a, n);
	printOddPositions(a, n);
	printMaxMin(a, n);

	int b[100], c[100], k;
	cout << "Nhập số phần tử của dãy b: ";
	int m;
	cin >> m;
	cout << "Nhập " << m << " phần tử của dãy b: ";
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	cout << "Nhập số phần tử của dãy c: ";
	int p;
	cin >> p;
	cout << "Nhập " << p << " phần tử của dãy c: ";
	for (int i = 0; i < p; i++) {
		cin >> c[i];
	}
	mergeArrays(b, m, c, p, a, k);
	cout << "Mảng a sau khi ghép: ";
	for (int i = 0; i < k; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}