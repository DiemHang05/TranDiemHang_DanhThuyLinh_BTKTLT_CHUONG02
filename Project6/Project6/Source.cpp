#include <iostream>
#include <vector>
#include <cmath>
#include <limits.h>

using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int n) {
	if (n <= 1) return false;
	if (n <= 3) return true;
	if (n % 2 == 0 || n % 3 == 0) return false;
	for (int i = 5; i * i <= n; i += 6)
	if (n % i == 0 || n % (i + 2) == 0)
		return false;
	return true;
}

// Hàm kiểm tra số hoàn thiện
bool isPerfect(int n) {
	if (n <= 1) return false;
	int sum = 1;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			sum += i;
			if (i != n / i)
				sum += n / i;
		}
	}
	return sum == n;
}

// Đếm các phần tử lớn hơn x
int countGreaterThanX(const vector<int>& a, int x) {
	int count = 0;
	for (int num : a) {
		if (num > x)
			count++;
	}
	return count;
}

// Tính tổng các phần tử của a
int sumArray(const vector<int>& a) {
	int sum = 0;
	for (int num : a) {
		sum += num;
	}
	return sum;
}

// Xuất các số nguyên tố trong a
void printPrimes(const vector<int>& a) {
	cout << "Prime numbers in array: ";
	for (int num : a) {
		if (isPrime(num)) {
			cout << num << " ";
		}
	}
	cout << endl;
}

// Xuất các số hoàn thiện trong a
void printPerfectNumbers(const vector<int>& a) {
	cout << "Perfect numbers in array: ";
	for (int num : a) {
		if (isPerfect(num)) {
			cout << num << " ";
		}
	}
	cout << endl;
}

// Xuất các phần tử ở vị trí chẵn
void printEvenPositions(const vector<int>& a) {
	cout << "Elements at even positions: ";
	for (size_t i = 0; i < a.size(); i += 2) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// Xuất các phần tử ở vị trí lẻ
void printOddPositions(const vector<int>& a) {
	cout << "Elements at odd positions: ";
	for (size_t i = 1; i < a.size(); i += 2) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// Xuất giá trị max và min kèm theo vị trí
void printMaxMinWithPositions(const vector<int>& a) {
	int maxVal = INT_MIN, minVal = INT_MAX;
	int maxPos = -1, minPos = -1;

	for (size_t i = 0; i < a.size(); i++) {
		if (a[i] > maxVal) {
			maxVal = a[i];
			maxPos = i;
		}
		if (a[i] < minVal) {
			minVal = a[i];
			minPos = i;
		}
	}

	cout << "Max value: " << maxVal << " at position " << maxPos << endl;
	cout << "Min value: " << minVal << " at position " << minPos << endl;
}

// Ghép hai dãy tăng dần b và c thành dãy a tăng dần
vector<int> mergeSortedArrays(const vector<int>& b, const vector<int>& c) {
	vector<int> a;
	size_t i = 0, j = 0;

	while (i < b.size() && j < c.size()) {
		if (b[i] < c[j]) {
			a.push_back(b[i]);
			i++;
		}
		else {
			a.push_back(c[j]);
			j++;
		}
	}

	// Thêm các phần tử còn lại
	while (i < b.size()) {
		a.push_back(b[i]);
		i++;
	}

	while (j < c.size()) {
		a.push_back(c[j]);
		j++;
	}

	return a;
}

int main() {
	vector<int> a = { 1, 2, 3, 28, 6, 7, 10, 15, 17 };
	int x = 5;

	cout << "Count of elements greater than " << x << ": " << countGreaterThanX(a, x) << endl;
	cout << "Sum of array elements: " << sumArray(a) << endl;

	printPrimes(a);
	printPerfectNumbers(a);
	printEvenPositions(a);
	printOddPositions(a);
	printMaxMinWithPositions(a);

	vector<int> b = { 1, 3, 5, 7 };
	vector<int> c = { 2, 4, 6, 8, 9 };
	vector<int> mergedArray = mergeSortedArrays(b, c);

	cout << "Merged sorted array: ";
	for (int num : mergedArray) {
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
