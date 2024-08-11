#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define PASSING_GRADE 5.0 // Điểm tối thiểu để đạt yêu cầu

typedef struct {
	int id;                // Số thứ tự
	char studentId[15];    // Mã số sinh viên
	char name[50];         // Họ tên sinh viên
	float essayScore;      // Điểm tiểu luận
	float finalExamScore;  // Điểm thi kết thúc môn
	float finalScore;      // Điểm tổng kết
	float gpa;             // Điểm hệ 4
} Student;

// Hàm tính điểm tổng kết
float calculateFinalScore(float essayScore, float finalExamScore) {
	return 0.3 * essayScore + 0.7 * finalExamScore;
}

// Hàm quy đổi điểm từ hệ 10 sang hệ 4
float convertToGPA(float score) {
	if (score >= 8.5) return 4.0;
	if (score >= 7.0) return 3.5;
	if (score >= 5.5) return 3.0;
	if (score >= 4.0) return 2.0;
	return 1.0;
}

// Hàm nhập danh sách sinh viên
void inputStudents(Student students[], int *n) {
	printf("Nhập số lượng sinh viên: ");
	scanf("%d", n);

	if (*n <= 0 || *n > MAX_STUDENTS) {
		printf("Số lượng sinh viên không hợp lệ.\n");
		return;
	}

	for (int i = 0; i < *n; i++) {
		printf("Nhập thông tin cho sinh viên thứ %d:\n", i + 1);
		students[i].id = i + 1;
		printf("Mã số sinh viên: ");
		scanf("%s", students[i].studentId);
		printf("Họ tên sinh viên: ");
		getchar();  // Đọc ký tự newline còn lại trong buffer
		fgets(students[i].name, 50, stdin);
		students[i].name[strcspn(students[i].name, "\n")] = '\0'; // Loại bỏ ký tự newline

		printf("Điểm tiểu luận: ");
		scanf("%f", &students[i].essayScore);
		printf("Điểm thi kết thúc môn: ");
		scanf("%f", &students[i].finalExamScore);

		students[i].finalScore = calculateFinalScore(students[i].essayScore, students[i].finalExamScore);
		students[i].gpa = convertToGPA(students[i].finalScore);
	}
}

// Hàm xuất danh sách sinh viên
void printStudents(Student students[], int n) {
	printf("Danh sách sinh viên:\n");
	for (int i = 0; i < n; i++) {
		printf("Số thứ tự: %d\n", students[i].id);
		printf("Mã số sinh viên: %s\n", students[i].studentId);
		printf("Họ tên sinh viên: %s\n", students[i].name);
		printf("Điểm tiểu luận: %.2f\n", students[i].essayScore);
		printf("Điểm thi kết thúc môn: %.2f\n", students[i].finalExamScore);
		printf("Điểm tổng kết: %.2f\n", students[i].finalScore);
		printf("Điểm hệ 4: %.2f\n\n", students[i].gpa);
	}
}

// Hàm tìm sinh viên có điểm tổng kết cao nhất và thấp nhất
void findMinMaxScores(Student students[], int n, Student *min, Student *max) {
	*min = *max = students[0];
	for (int i = 1; i < n; i++) {
		if (students[i].finalScore < min->finalScore) {
			*min = students[i];
		}
		if (students[i].finalScore > max->finalScore) {
			*max = students[i];
		}
	}
}

// Hàm đếm số sinh viên đạt và không đạt
void countPassFail(Student students[], int n, int *passCount, int *failCount) {
	*passCount = *failCount = 0;
	for (int i = 0; i < n; i++) {
		if (students[i].finalScore >= PASSING_GRADE) {
			(*passCount)++;
		}
		else {
			(*failCount)++;
		}
	}
}

// Hàm tính điểm trung bình của tất cả các sinh viên
float calculateAverageScore(Student students[], int n) {
	float sum = 0;
	for (int i = 0; i < n; i++) {
		sum += students[i].finalScore;
	}
	return sum / n;
}

// Hàm sắp xếp danh sách sinh viên theo điểm tổng kết (tăng dần)
void sortStudentsAscending(Student students[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (students[i].finalScore > students[j].finalScore) {
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

// Hàm sắp xếp danh sách sinh viên theo điểm tổng kết (giảm dần)
void sortStudentsDescending(Student students[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (students[i].finalScore < students[j].finalScore) {
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
}

// Hàm ghi dữ liệu vào file
void writeToFile(Student students[], int n, const char *filename) {
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		printf("Không thể mở file để ghi dữ liệu.\n");
		return;
	}

	for (int i = 0; i < n; i++) {
		fprintf(file, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
			students[i].id,
			students[i].studentId,
			students[i].name,
			students[i].essayScore,
			students[i].finalExamScore,
			students[i].finalScore,
			students[i].gpa);
	}

	fclose(file);
}

// Hàm đọc dữ liệu từ file
void readFromFile(Student students[], int *n, const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("Không thể mở file để đọc dữ liệu.\n");
		return;
	}

	*n = 0;
	while (fscanf(file, "%d,%[^,],%[^,],%f,%f,%f,%f\n",
		&students[*n].id,
		students[*n].studentId,
		students[*n].name,
		&students[*n].essayScore,
		&students[*n].finalExamScore,
		&students[*n].finalScore,
		&students[*n].gpa) != EOF) {
		(*n)++;
	}

	fclose(file);
}

int main() {
	Student students[MAX_STUDENTS];
	int n;

	// Nhập dữ liệu
	inputStudents(students, &n);

	// Xuất dữ liệu
	printStudents(students, n);

	// Tìm sinh viên có điểm tổng kết cao nhất và thấp nhất
	Student minStudent, maxStudent;
	findMinMaxScores(students, n, &minStudent, &maxStudent);
	printf("Sinh viên có điểm tổng kết thấp nhất:\n");
	printStudents(&minStudent, 1);
	printf("Sinh viên có điểm tổng kết cao nhất:\n");
	printStudents(&maxStudent, 1);

	// Đếm số sinh viên đạt và không đạt
	int passCount, failCount;
	countPassFail(students, n, &passCount, &failCount);
	printf("Số sinh viên đạt yêu cầu: %d\n", passCount);
	printf("Số sinh viên không đạt yêu cầu: %d\n", failCount);

	// Tính điểm trung bình
	float averageScore = calculateAverageScore(students, n);
	printf("Điểm trung bình của tất cả sinh viên: %.2f\n", averageScore);

	// Sắp xếp sinh viên theo điểm tổng kết (tăng dần và giảm dần)
	sortStudentsAscending(students, n);
	printf("Danh sách sinh viên sắp xếp theo điểm tổng kết (tăng dần):\n");
	printStudents(students, n);

	sortStudentsDescending(students, n);
	printf("Danh sách sinh viên sắp xếp theo điểm tổng kết (giảm dần):\n");
	printStudents(students, n);

	// Ghi dữ liệu vào file
	writeToFile(students, n, "students.txt");

	// Đọc dữ liệu từ file
	Student studentsFromFile[MAX_STUDENTS];
	int nFromFile;
	readFromFile(studentsFromFile, &nFromFile, "students.txt");
	printf("Dữ liệu đọc từ file:\n");
	printStudents(studentsFromFile, nFromFile);

	return 0;
}
