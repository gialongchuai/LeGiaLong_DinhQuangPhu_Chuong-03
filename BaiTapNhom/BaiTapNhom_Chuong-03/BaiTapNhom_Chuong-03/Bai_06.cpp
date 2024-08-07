/*
	Viết hàm cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên.
	Ví dụ: chuỗi họ tên là: “Nguyễn Văn A” cắt ra 2 chuỗi là chuỗi họ lót:
	“NguyễnVăn” ,chuỗi tên là: “A”.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// Hàm cắt chuỗi họ tên thành chuỗi họ lót và chuỗi tên
void catChuoi(char *hoTen, char *hoLot, char *ten) {
	int i, j;
	int len = strlen(hoTen);

	// Xóa khoảng trắng đầu và cuối chuỗi họ tên
	while (*hoTen == ' ') hoTen++;
	while (len > 0 && hoTen[len - 1] == ' ') len--;
	hoTen[len] = '\0';

	// Tìm vị trí của ký tự khoảng trắng cuối cùng trong chuỗi họ tên
	i = len - 1;
	while (i >= 0 && hoTen[i] != ' ') i--;

	// Nếu có khoảng trắng, tách chuỗi họ lót và chuỗi tên
	if (i >= 0) {
		// Cắt chuỗi họ lót
		strncpy(hoLot, hoTen, i);
		hoLot[i] = '\0';

		// Cắt chuỗi tên
		strcpy(ten, hoTen + i + 1);
	}
	else {
		// Nếu không có khoảng trắng, toàn bộ chuỗi là tên
		hoLot[0] = '\0';
		strcpy(ten, hoTen);
	}
}

int main() {
	char hoTen[] = "Nguyen Van A";
	char hoLot[100];
	char ten[100];

	// Gọi hàm để cắt chuỗi
	catChuoi(hoTen, hoLot, ten);

	// In kết quả
	printf("Chuoi ho lot: '%s'\n", hoLot);
	printf("Chuoi ten: '%s'\n", ten);

	system("pause");
	return 0;
}
