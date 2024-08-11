#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#define MAX_SIZE 100

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
	if (num <= 1) return false;
	if (num == 2) return true;
	if (num % 2 == 0) return false;
	for (int i = 3; i * i <= num; i += 2) {
		if (num % i == 0) return false;
	}
	return true;
}

// Hàm kiểm tra số hoàn thiện
bool isPerfect(int num) {
	if (num <= 1) return false;
	int sum = 1;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			sum += i;
			if (i != num / i) {
				sum += num / i;
			}
		}
	}
	return sum == num;
}

// Bài 1: Liệt kê các cột có tổng nhỏ nhất
void listColumnsWithMinSum(int arr[][MAX_SIZE], int m, int n) {
	int minSum = INT_MAX;
	int sum[MAX_SIZE] = { 0 }; // Initialize with 0

	for (int j = 0; j < n; j++) {
		sum[j] = 0;
		for (int i = 0; i < m; i++) {
			sum[j] += arr[i][j];
		}
		if (sum[j] < minSum) {
			minSum = sum[j];
		}
	}

	printf("Cac cot co tong nho nhat:\n");

	for (int j = 0; j < n; j++) {
		if (sum[j] == minSum) {
			printf("%d ", j);
		}
	}
	printf("\n");
}

// Bài 2: Liệt kê các dòng có nhiều số hoàn thiện nhất
void listRowsWithMostPerfectNumbers(int arr[][MAX_SIZE], int m, int n) {
	int perfectCounts[MAX_SIZE] = { 0 }; // Initialize with 0

	for (int i = 0; i < m; i++) {
		perfectCounts[i] = 0;
		for (int j = 0; j < n; j++) {
			if (isPerfect(arr[i][j])) {
				perfectCounts[i]++;
			}
		}
	}

	int maxCount = INT_MIN;
	for (int i = 0; i < m; i++) {
		if (perfectCounts[i] > maxCount) {
			maxCount = perfectCounts[i];
		}
	}

	printf("Cac dong co nhieu so hoan thien nhat:\n");
	for (int i = 0; i < m; i++) {
		if (perfectCounts[i] == maxCount) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

// Bài 3: Liệt kê chỉ số các dòng chứa toàn giá trị chẵn
void listRowsWithAllEvenNumbers(int arr[][MAX_SIZE], int m, int n) {
	printf("Cac dong chua toan gia tri chan:\n");
	for (int i = 0; i < m; i++) {
		bool allEven = true;
		for (int j = 0; j < n; j++) {
			if (arr[i][j] % 2 != 0) {
				allEven = false;
				break;
			}
		}
		if (allEven) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

// Bài 4: Tìm giá trị xuất hiện nhiều nhất
void findMostFrequentValue(int arr[][MAX_SIZE], int m, int n) {
	int frequency[10000] = { 0 }; // Giả sử các giá trị trong mảng nằm trong khoảng [-5000, 5000]
	int mostFrequentValue = arr[0][0];
	int maxFrequency = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			frequency[arr[i][j] + 5000]++;
			if (frequency[arr[i][j] + 5000] > maxFrequency) {
				maxFrequency = frequency[arr[i][j] + 5000];
				mostFrequentValue = arr[i][j];
			}
		}
	}

	printf("Gia tri xuat hien nhieu nhat: %d\n", mostFrequentValue);
}

// Bài 5: Tìm số nguyên tố nhỏ nhất trong ma trận
void findSmallestPrime(int arr[][MAX_SIZE], int m, int n) {
	int minPrime = INT_MAX;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (isPrime(arr[i][j]) && arr[i][j] < minPrime) {
				minPrime = arr[i][j];
			}
		}
	}

	if (minPrime == INT_MAX) {
		printf("Khong co so nguyen to trong ma tran.\n");
	}
	else {
		printf("So nguyen to nho nhat: %d\n", minPrime);
	}
}

// Bài 6: Tìm phần tử lớn (nhỏ) nhất trong dòng thứ k
void findLargestSmallestInRow(int arr[][MAX_SIZE], int m, int n, int k, bool findLargest) {
	if (k >= m || k < 0) {
		printf("Chi so dong %d khong hop le.\n", k);
		return;
	}

	int value = arr[k][0];
	for (int j = 1; j < n; j++) {
		if (findLargest) {
			if (arr[k][j] > value) {
				value = arr[k][j];
			}
		}
		else {
			if (arr[k][j] < value) {
				value = arr[k][j];
			}
		}
	}
	printf("Phan tu %s nhat trong dong %d: %d\n", findLargest ? "lon" : "nho", k, value);
}

// Bài 7: Tìm phần tử lớn (nhỏ) nhất trong cột thứ k
void findLargestSmallestInColumn(int arr[][MAX_SIZE], int m, int n, int k, bool findLargest) {
	if (k >= n || k < 0) {
		printf("Chi so cot %d khong hop le.\n", k);
		return;
	}

	int value = arr[0][k];
	for (int i = 1; i < m; i++) {
		if (findLargest) {
			if (arr[i][k] > value) {
				value = arr[i][k];
			}
		}
		else {
			if (arr[i][k] < value) {
				value = arr[i][k];
			}
		}
	}
	printf("Phan tu %s nhat trong cot %d: %d\n", findLargest ? "lon" : "nho", k, value);
}

void Menu()
{
	printf("\n=========================================================");
	printf("\n0.Thoat");
	printf("\n1.Liet ke cac cot co tong nho nhat trong ma tran");
	printf("\n2.Liet ke cac dong co nhieu so hoan thien nhat trong ma tran");
	printf("\n3.Liet ke chi so cac dong chua toan gia tri chan");
	printf("\n4.Tim gia tri xuat hien nhieu nhat trong ma tran");
	printf("\n5.Tim so nguyen to nho nhat trong ma tran");
	printf("\n6.Tim phan tu lon (nho) nhat trong dong thu k");
	printf("\n7.Tim phan tu lon (nho) nhat trong cot thu k");
	printf("\n=========================================================");
}

	int main() {
		int m, n;
		int arr[MAX_SIZE][MAX_SIZE]; // Giới hạn kích thước ma trận

		// Nhập kích thước ma trận
		printf("Nhap so dong m: ");
		scanf_s("%d", &m);
		printf("Nhap so cot n: ");
		scanf_s("%d", &n);

		// Kiểm tra kích thước hợp lệ
		if (m < 1 || m > MAX_SIZE || n < 1 || n > MAX_SIZE) {
			printf("Kich thuoc ma tran khong hop le.\n");
			return 1;
		}

		// Nhập ma trận
		srand((unsigned int)time(NULL));

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// Sinh s? ng?u nhiên trong kho?ng [0, 100]
				arr[i][j] = (rand() % (100 - 0 + 1)) + 0;
			}
		}
		printf("\nMang 2 chieu: \n");
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				printf("%4d ", arr[i][j]);
			}
			printf("\n");
		}
		int chon;
		do{
			Menu();
			printf("\nChon cac chuc nang tren: ");
			scanf_s("%d", &chon);
			switch (chon){
			case 1:
			{
					  listColumnsWithMinSum(arr, m, n);
					  break;
			}
			case 2:
			{
					  listRowsWithMostPerfectNumbers(arr, m, n);
					  break;
			}
			case 3:
			{
					  listRowsWithAllEvenNumbers(arr, m, n);
					  break;
			}
			case 4:
			{
					  findMostFrequentValue(arr, m, n);
					  break;
			}
			case 5:
			{
					  findSmallestPrime(arr, m, n);
					  break;
			}
			case 6:
			{
					  int k;
					  printf("Nhap chi so cot k: ");
					  scanf_s("%d", &k);
					  if (k >= 0 && k < n) {
						  findLargestSmallestInRow(arr, m, n, k, true); // Tìm phần tử lớn nhất trong cột thứ k
						  findLargestSmallestInRow(arr, m, n, k, false); // Tìm phần tử nhỏ nhất trong cột thứ k
					  }
					  else {
						  printf("Chi so cot %d khong hop le.\n", k);
					  }
					  
					  break;
			}
			case 7:
			{
					  int k;
					  printf("Nhap chi so cot k: ");
					  scanf_s("%d", &k);
					  if (k >= 0 && k < n) {
						  findLargestSmallestInColumn(arr, m, n, k, true); // Tìm phần tử lớn nhất trong cột thứ k
						  findLargestSmallestInColumn(arr, m, n, k, false); // Tìm phần tử nhỏ nhất trong cột thứ k
					  }
					  else {
						  printf("Chi so cot %d khong hop le.\n", k);
					  }

					  break;
					  break;
			}

			}
		} while (chon != 0);
		// Gọi các hàm với các yêu cầu cụ thể
		listColumnsWithMinSum(arr, m, n);
		listRowsWithMostPerfectNumbers(arr, m, n);
		listRowsWithAllEvenNumbers(arr, m, n);
		findMostFrequentValue(arr, m, n);
		findSmallestPrime(arr, m, n);

		// Ví dụ với số nguyên tố nhỏ nhất
		int k;

		// Tìm phần tử lớn nhất và nhỏ nhất trong dòng thứ k
		printf("Nhap chi so dong k: ");
		scanf_s("%d", &k);
		if (k >= 0 && k < m) {
			findLargestSmallestInRow(arr, m, n, k, true); // Tìm phần tử lớn nhất trong dòng thứ k
			findLargestSmallestInRow(arr, m, n, k, false); // Tìm phần tử nhỏ nhất trong dòng thứ k
		}
		else {
			printf("Chi so dong %d khong hop le.\n", k);
		}

		// Tìm phần tử lớn nhất và nhỏ nhất trong cột thứ k
		

		return 0;
	}
	

