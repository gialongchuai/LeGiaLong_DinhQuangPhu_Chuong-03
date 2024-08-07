/*
	Nhập 1 chuỗi bất kì, liệt kê xem mỗi ký tự xuất hiện mấy lần.*/#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LEN 100

// Hàm để kiểm tra xem ký tự đã xuất hiện trước đó chưa
int daXuatHien(char arr[], char c, int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] == c) {
			return 1; // Đã xuất hiện
		}
	}
	return 0; // Chưa xuất hiện
}

int main() {
	char chuoi[MAX_LEN];
	char daXuatHienArr[MAX_LEN];
	int dem[MAX_LEN];
	int i, j;
	int len = 0;

	// Nhập chuỗi từ người dùng
	printf("Nhap chuoi: ");
	fgets(chuoi, MAX_LEN, stdin);

	// Xóa ký tự newline nếu có
	chuoi[strcspn(chuoi, "\n")] = '\0';

	// Khởi tạo mảng đếm và mảng đã xuất hiện
	memset(dem, 0, sizeof(dem));
	memset(daXuatHienArr, 0, sizeof(daXuatHienArr));

	// Đếm số lần xuất hiện của từng ký tự
	for (i = 0; chuoi[i] != '\0'; i++) {
		if (!daXuatHien(daXuatHienArr, chuoi[i], len)) {
			daXuatHienArr[len] = chuoi[i];
			len++;
			int count = 0;
			for (j = 0; chuoi[j] != '\0'; j++) {
				if (chuoi[j] == chuoi[i]) {
					count++;
				}
			}
			dem[i] = count;
		}
	}

	// Hiển thị kết quả
	printf("So lan xuat hien cua cac ky tu:\n");
	for (i = 0; i < len; i++) {
		printf("'%c': %d lan\n", daXuatHienArr[i], dem[i]);
	}

	// Dừng chương trình để xem kết quả
	system("pause");

	return 0;
}
