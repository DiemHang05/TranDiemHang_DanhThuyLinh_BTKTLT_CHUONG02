//#include <stdio.h>
//#include <time.h>
//#define MAX 100 // Giới hạn kích thước ma trận
//
//// Hàm tính tổng các phần tử trên đường chéo phụ
//int tinhTongDuongCheoPhu(int maTran[MAX][MAX], int n) {
//	int tong = 0;
//	for (int i = 0; i < n; i++) {
//		tong += maTran[i][n - 1 - i];
//	}
//	return tong;
//}
//
//int main() {
//	int n;
//	int maTran[MAX][MAX];
//
//	// Nhập kích thước của ma trận
//	printf("Nhap kich thuoc ma tran vuong (n x n): ");
//	scanf("%d", &n);
//
//	// Kiểm tra kích thước hợp lệ
//	if (n < 1 || n > MAX) {
//		printf("Kich thuoc ma tran khong hop le.\n");
//		return 1;
//	}
//
//	// Nhập các phần tử của ma trận
//	srand((unsigned int)time(NULL));
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			// Sinh số ngẫu nhiên trong khoảng [0, 100]
//			maTran[i][j] = (rand() % (100 - 0 + 1)) + 0;
//		}
//	}
//	printf("\nMang 2 chieu: \n");
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%4d ", maTran[i][j]);
//		}
//		printf("\n");
//	}
//	// Tính tổng các phần tử trên đường chéo phụ
//	int tong = tinhTongDuongCheoPhu(maTran, n);
//
//	// In kết quả
//	printf("Tong cac phan tu tren duong cheo phu la: %d\n", tong);
//
//	return 0;
//}
