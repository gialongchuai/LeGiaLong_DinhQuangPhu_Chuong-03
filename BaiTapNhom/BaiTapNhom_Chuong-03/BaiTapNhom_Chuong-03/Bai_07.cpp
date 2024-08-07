/*
	Viết chương trình chèn 1 từ ở bất cứ vị trí nào người dùng yêu cầu.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LENGTH 100

// Hàm để chèn một từ vào chuỗi tại vị trí yêu cầu
void chenTu(char *chuoi, const char *tuChen, int viTri) {
	int lenChuoi = strlen(chuoi);
	int lenTuChen = strlen(tuChen);

	// Kiểm tra vị trí chèn hợp lệ
	if (viTri < 0 || viTri > lenChuoi) {
		printf("Vi tri chen khong hop le.\n");
		return;
	}

	// Di chuyển phần còn lại của chuỗi để tạo khoảng trống cho từ chèn
	for (int i = lenChuoi; i >= viTri; i--) {
		chuoi[i + lenTuChen] = chuoi[i];
	}

	// Chèn từ vào vị trí yêu cầu
	for (int i = 0; i < lenTuChen; i++) {
		chuoi[viTri + i] = tuChen[i];
	}

	chuoi[lenChuoi + lenTuChen] = '\0'; // Kết thúc chuỗi
}

int main() {
	char chuoi[MAX_LENGTH];
	char tuChen[MAX_LENGTH];
	int viTri;

	// Nhập chuỗi gốc từ người dùng
	printf("Nhap chuoi goc: ");
	fgets(chuoi, MAX_LENGTH, stdin);
	chuoi[strcspn(chuoi, "\n")] = '\0'; // Loại bỏ ký tự newline

	// Nhập từ cần chèn
	printf("Nhap tu can chen: ");
	fgets(tuChen, MAX_LENGTH, stdin);
	tuChen[strcspn(tuChen, "\n")] = '\0'; // Loại bỏ ký tự newline

	// Nhập vị trí chèn
	printf("Nhap vi tri chen: ");
	scanf("%d", &viTri);

	// Gọi hàm chèn từ
	chenTu(chuoi, tuChen, viTri);

	// In chuỗi sau khi chèn từ
	printf("Chuoi sau khi chen: %s\n", chuoi);

	system("pause");
	return 0;
}
