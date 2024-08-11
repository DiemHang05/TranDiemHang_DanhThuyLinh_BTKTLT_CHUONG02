#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 50

typedef struct {
	int numerator;   // Tử số
	int denominator; // Mẫu số
} Fraction;

// Hàm tính GCD (UCLN) của hai số
int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

// Hàm nhập danh sách các phân số
void inputFractions(Fraction arr[], int *n) {
	printf("Nhập số lượng phân số: ");
	scanf_s("%d", n);
	if (*n <= 0 || *n > MAX_SIZE) {
		printf("Số lượng phân số không hợp lệ. Phải nằm trong khoảng từ 1 đến %d.\n", MAX_SIZE);
		return;
	}
	for (int i = 0; i < *n; i++) {
		printf("Nhập tử số và mẫu số cho phân số %d: ", i + 1);
		scanf_s("%d %d", &arr[i].numerator, &arr[i].denominator);
		// Đảm bảo mẫu số không phải là 0
		while (arr[i].denominator == 0) {
			printf("Mẫu số không thể là 0. Nhập lại: ");
			scanf_s("%d", &arr[i].denominator);
		}
	}
}

// Hàm xuất danh sách các phân số
void printFractions(Fraction arr[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d/%d ", arr[i].numerator, arr[i].denominator);
	}
	printf("\n");
}

// Hàm tính giá trị của phân số
float value(Fraction f) {
	return (float)f.numerator / f.denominator;
}

// Hàm tìm phân số có giá trị lớn nhất và nhỏ nhất
void findMinMax(Fraction arr[], int n, Fraction *min, Fraction *max) {
	*min = *max = arr[0];
	for (int i = 1; i < n; i++) {
		if (value(arr[i]) < value(*min)) {
			*min = arr[i];
		}
		if (value(arr[i]) > value(*max)) {
			*max = arr[i];
		}
	}
}

// Hàm tính tổng các phân số
Fraction addFractions(Fraction arr[], int n) {
	Fraction result = { 0, 1 }; // Khởi tạo phân số 0/1
	for (int i = 0; i < n; i++) {
		result.numerator = result.numerator * arr[i].denominator + arr[i].numerator * result.denominator;
		result.denominator *= arr[i].denominator;
		// Rút gọn phân số
		int divisor = gcd(result.numerator, result.denominator);
		result.numerator /= divisor;
		result.denominator /= divisor;
	}
	return result;
}

// Hàm tính tích các phân số
Fraction multiplyFractions(Fraction arr[], int n) {
	Fraction result = { 1, 1 }; // Khởi tạo phân số 1/1
	for (int i = 0; i < n; i++) {
		result.numerator *= arr[i].numerator;
		result.denominator *= arr[i].denominator;
		// Rút gọn phân số
		int divisor = gcd(result.numerator, result.denominator);
		result.numerator /= divisor;
		result.denominator /= divisor;
	}
	return result;
}

// Hàm tính nghịch đảo của phân số
void invertFractions(Fraction arr[], int n) {
	for (int i = 0; i < n; i++) {
		int temp = arr[i].numerator;
		arr[i].numerator = arr[i].denominator;
		arr[i].denominator = temp;
	}
}

// Hàm so sánh hai phân số
int compareFractions(Fraction f1, Fraction f2) {
	return value(f1) > value(f2) ? 1 : (value(f1) < value(f2) ? -1 : 0);
}

// Hàm sắp xếp mảng phân số theo thứ tự tăng dần
void sortFractionsAscending(Fraction arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (compareFractions(arr[i], arr[j]) > 0) {
				Fraction temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Hàm sắp xếp mảng phân số theo thứ tự giảm dần
void sortFractionsDescending(Fraction arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (compareFractions(arr[i], arr[j]) < 0) {
				Fraction temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	Fraction fractions[MAX_SIZE];
	int n;

	inputFractions(fractions, &n);

	printf("Danh sách phân số: ");
	printFractions(fractions, n);

	Fraction min, max;
	findMinMax(fractions, n, &min, &max);
	printf("Phân số nhỏ nhất: %d/%d\n", min.numerator, min.denominator);
	printf("Phân số lớn nhất: %d/%d\n", max.numerator, max.denominator);

	Fraction sum = addFractions(fractions, n);
	printf("Tổng các phân số: %d/%d\n", sum.numerator, sum.denominator);

	Fraction product = multiplyFractions(fractions, n);
	printf("Tích các phân số: %d/%d\n", product.numerator, product.denominator);

	invertFractions(fractions, n);
	printf("Nghịch đảo các phân số: ");
	printFractions(fractions, n);

	sortFractionsAscending(fractions, n);
	printf("Danh sách phân số sắp xếp theo thứ tự tăng dần: ");
	printFractions(fractions, n);

	sortFractionsDescending(fractions, n);
	printf("Danh sách phân số sắp xếp theo thứ tự giảm dần: ");
	printFractions(fractions, n);

	return 0;
}
