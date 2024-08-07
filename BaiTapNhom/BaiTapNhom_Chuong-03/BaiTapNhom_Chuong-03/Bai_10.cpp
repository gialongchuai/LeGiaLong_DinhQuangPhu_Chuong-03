/*
	Viết chương trình tìm kiếm xem ký tự nào xuất nhiện nhiều
	nhất trong chuỗi.
*/

#include <stdio.h>
#include <string.h>

#define MAX 256 // Kích thước tối đa của bảng đếm

int main() {
	char str[1000];
	int count[MAX] = { 0 }; // Bảng đếm số lần xuất hiện của từng ký tự
	int maxCount = 0;
	char maxChar;

	printf("Nhap chuoi: ");
	fgets(str, sizeof(str), stdin);

	// Loại bỏ ký tự newline ở cuối chuỗi nếu có
	size_t len = strlen(str);
	if (len > 0 && str[len - 1] == '\n') {
		str[len - 1] = '\0';
	}

	// Đếm số lần xuất hiện của từng ký tự
	for (int i = 0; str[i] != '\0'; i++) {
		count[(unsigned char)str[i]]++;
	}

	// Tìm ký tự xuất hiện nhiều nhất
	for (int i = 0; i < MAX; i++) {
		if (count[i] > maxCount) {
			maxCount = count[i];
			maxChar = i;
		}
	}

	// Hiển thị kết quả
	if (maxCount > 0) {
		printf("Ky tu xuat hien nhieu nhat la: '%c' (xuat hien %d lan)\n", maxChar, maxCount);
	}
	else {
		printf("Chuoi rong.\n");
	}

	// Dừng màn hình để xem kết quả
	printf("Nhan Enter de thoat...");
	getchar(); // Đọc ký tự Enter để dừng màn hình

	return 0;
}
