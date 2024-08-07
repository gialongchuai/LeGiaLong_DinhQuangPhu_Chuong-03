/*
	Viết chương trình tìm kiếm tên trong chuỗi họ tên. Nếu có thì xuất ra là
	tên này đã nhập đúng, ngược lại thông báo là đã nhập sai
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>  // Đảm bảo thư viện này được bao gồm
#include <stdlib.h>
// Hàm kiểm tra xem tên có tồn tại trong chuỗi họ tên không
int timTen(char *hoTen, char *ten) {
	// Tìm vị trí của tên trong chuỗi họ tên
	char *pos = strstr(hoTen, ten);
	// Kiểm tra xem tên có nằm trong chuỗi họ tên không
	if (pos != NULL) {
		// Kiểm tra xem tên có phải là từ đứng riêng biệt không
		// Phải đảm bảo rằng tên không nằm giữa các ký tự không phải là chữ cái
		if ((pos == hoTen || !isalpha(*(pos - 1))) &&
			(!isalpha(*(pos + strlen(ten))) && *(pos + strlen(ten)) != '\0')) {
			return 1; // Tên tồn tại và đúng
		}
	}
	return 0; // Tên không tồn tại hoặc không đúng
}

int main() {
	char hoTen[100];
	char ten[50];

	printf("Nhap chuoi ho ten: ");
	fgets(hoTen, sizeof(hoTen), stdin);
	// Xóa ký tự '\n' nếu có
	hoTen[strcspn(hoTen, "\n")] = '\0';

	printf("Nhap ten can tim: ");
	fgets(ten, sizeof(ten), stdin);
	// Xóa ký tự '\n' nếu có
	ten[strcspn(ten, "\n")] = '\0';

	if (timTen(hoTen, ten)) {
		printf("Ten '%s' da nhap dung.\n", ten);
	}
	else {
		printf("Ten '%s' da nhap sai.\n", ten);
	}

	system("pause");
	return 0;
}
