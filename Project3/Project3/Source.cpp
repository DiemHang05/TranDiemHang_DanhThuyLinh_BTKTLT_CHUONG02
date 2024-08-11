// Hàm sắp xếp tăng theo phương pháp Interchange Sort
template <typename T>
void interchange_sort_asc(T arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] > arr[j]) {
				// Hoán đổi
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

// Hàm sắp xếp giảm theo phương pháp Interchange Sort
template <typename T>
void interchange_sort_desc(T arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i] < arr[j]) {
				// Hoán đổi
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}