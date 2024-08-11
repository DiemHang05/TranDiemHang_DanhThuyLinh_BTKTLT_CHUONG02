#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100 // Gi?i h?n kích thu?c ma tr?n

// Hàm tính t?ng các ph?n t? trên du?ng chéo chính
int tinhTongDuongCheoChinh(int maTran[MAX][MAX], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += maTran[i][i];
	}
	return tong;
}
// Hàm tính t?ng các ph?n t? trên du?ng chéo ph?
int tinhTongDuongCheoPhu(int maTran[MAX][MAX], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		tong += maTran[i][n - 1 - i];
	}
	return tong;
}
// Hàm tính t?ng các ph?n t? n?m phía trên du?ng chéo chính
int tinhTongTrenDuongCheoChinh(int maTran[MAX][MAX], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			tong += maTran[i][j];
		}
	}
	return tong;
}
// Hàm tính t?ng các ph?n t? n?m phía trên du?ng chéo ph?
int tinhTongTrenDuongCheoPhu(int maTran[MAX][MAX], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			tong += maTran[i][j];
		}
	}
	return tong;
}
void Menu()
{
	printf("\n=========================================================");
	printf("\n0.Thoat");
	printf("\n1.Tinh tong cac phan tu nam tren duong cheo chinh");
	printf("\n2.Tinh tong cac phan tu nam tren duong cheo phu");
	printf("\n3.Tinh tong cac phan tu nam phia tren duong cheo chinh");
	printf("\n4.Tinh tong cac phan tu nam phia tren duong cheo phu");
	printf("\n=========================================================");
}
int main() {
	int n;
	int maTran[MAX][MAX];
	int chon;

	// Nh?p kích thu?c c?a ma tr?n
	printf("Nhap kich thuoc ma tran vuong (n x n): ");
	scanf_s("%d", &n);

	// Ki?m tra kích thu?c h?p l?
	if (n < 1 || n > MAX) {
		printf("Kich thuoc ma tran khong hop le.\n");
		return 1;
	}

	// Nh?p các ph?n t? c?a ma tr?n
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// Sinh s? ng?u nhiên trong kho?ng [0, 100]
			maTran[i][j] = (rand() % (100 - 0 + 1)) + 0;
		}
	}
	printf("\nMang 2 chieu: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%4d ", maTran[i][j]);
		}
		printf("\n");
	}
	do
	{
		Menu();
		printf("\nChon cac chuc nang tren: ");
		scanf_s("%d", &chon);
		switch (chon){
		case 1:
		{
				  int tong;
				  tong = tinhTongDuongCheoChinh(maTran, n);
				  printf("Tong cac phan tu tren duong cheo chinh la: %d", tong);
				  break;
		}
		case 2:
		{
				  int tong;
				  tong = tinhTongDuongCheoPhu(maTran, n);
				  printf("Tong cac phan tu tren duong cheo phu la: %d", tong);
				  break;
		}
		case 3:
		{
				  int tong;
				  tong = tinhTongTrenDuongCheoChinh(maTran, n);
				  printf("Tong cac phan tu nam tren duong cheo chinh: %d", tong);
				  break;
		}
		case 4:
		{
				  int tong;
				  tong = tinhTongTrenDuongCheoPhu(maTran, n);
				  printf("Tong cac phan tu nam tren duong cheo phu: %d", tong);
				  break;
		}
		}
	} while (chon != 0);
	return 0;
}

