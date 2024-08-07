/*
	Viết hàm đổi những kí tự đầu tiên của mỗi từ thành chữ in hoa và
	những từ không phải đầu câu sang chữ thường*/#include <stdio.h>
#include <ctype.h>  // Để sử dụng các hàm isalpha, toupper, tolower
#include <stdlib.h>
// Hàm chuyển đổi ký tự đầu tiên của mỗi từ thành chữ in hoa và các ký tự còn lại thành chữ thường
void chuyenDoiChu(char *str) {
	int inWord = 0; // Biến đánh dấu có đang ở trong một từ hay không

	while (*str) {
		// Kiểm tra xem ký tự hiện tại có phải là một ký tự chữ không
		if (isalpha(*str)) {
			if (!inWord) {
				// Nếu chưa ở trong từ, chuyển ký tự đầu tiên của từ thành chữ in hoa
				*str = toupper(*str);
				inWord = 1; // Đánh dấu đang ở trong một từ
			}
			else {
				// Nếu đã ở trong từ, chuyển ký tự còn lại thành chữ thường
				*str = tolower(*str);
			}
		}
		else {
			// Ký tự không phải là chữ, đặt lại trạng thái từ
			inWord = 0;
		}
		str++;
	}
}

int main() {
	char str[100];

	printf("Nhap chuoi: ");
	fgets(str, sizeof(str), stdin); // Đọc chuỗi từ người dùng

	chuyenDoiChu(str); // Gọi hàm để chuyển đổi

	printf("Chuoi sau khi chuyen doi: %s", str); // In chuỗi đã chuyển đổi

	system("pause");
	return 0;
}
