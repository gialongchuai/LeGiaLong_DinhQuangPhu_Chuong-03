/*
Bài 03: Nhập vào một chuỗi, xóa những khoảng trắng thừa trong chuỗi.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Ham xoa khoang trang thua trong chuoi
void xoaKhoangTrangThua(char* chuoi) {
	int len = strlen(chuoi);
	int j = 0; // bien j de luu vi tri cua ky tu hop le

	for (int i = 0; i < len; i++) {
		// Bo qua khoang trang neu no o dau hoac theo sau khoang trang khac
		if (chuoi[i] != ' ' || (i > 0 && chuoi[i - 1] != ' ')) {
			chuoi[j++] = chuoi[i];
		}
	}

	// Xoa khoang trang o cuoi chuoi neu co
	if (j > 0 && chuoi[j - 1] == ' ') {
		chuoi[j - 1] = '\0';
	}
	else {
		chuoi[j] = '\0';
	}
}

int main() {
	char chuoi[100];

	printf("Nhap chuoi: ");
	fgets(chuoi, sizeof(chuoi), stdin); // Su dung fgets() de nhap chuoi co khoang trang

	// Xoa ky tu xuong dong o cuoi chuoi neu co
	size_t len = strlen(chuoi);
	if (len > 0 && chuoi[len - 1] == '\n') {
		chuoi[len - 1] = '\0';
	}

	xoaKhoangTrangThua(chuoi);

	printf("Chuoi sau khi xoa khoang trang thua: %s\n", chuoi);

	system("pause"); // Tam dung man hinh

	return 0;
}
