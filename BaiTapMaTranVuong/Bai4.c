//#include <stdio.h>
//
//#define MAX 100 // Giới hạn kích thước ma trận
//
//// Hàm tính tổng các phần tử nằm phía trên đường chéo phụ
//int tinhTongTrenDuongCheoPhu(int maTran[MAX][MAX], int n) {
//	int tong = 0;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - 1 - i; j++) {
//			tong += maTran[i][j];
//		}
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
//	printf("Nhap cac phan tu cua ma tran:\n");
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("maTran[%d][%d] = ", i, j);
//			scanf("%d", &maTran[i][j]);
//		}
//	}
//
//	// Tính tổng các phần tử nằm phía trên đường chéo phụ
//	int tong = tinhTongTrenDuongCheoPhu(maTran, n);
//
//	// In kết quả
//	printf("Tong cac phan tu tren phia tren duong cheo phu la: %d\n", tong);
//
//	return 0;
//}
