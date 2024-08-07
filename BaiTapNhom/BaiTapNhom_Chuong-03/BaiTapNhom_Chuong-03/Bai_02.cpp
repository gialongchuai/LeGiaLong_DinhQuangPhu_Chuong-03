/*
2. Viết hàm đếm có bao nhiêu khoảng trắng trong chuỗi
*/

#include <stdio.h>
#include <stdlib.h>

// Ham dem so luong khoang trang trong chuoi
int demKhoangTrang(const char* chuoi) {
	int dem = 0;
	for (int i = 0; chuoi[i] != '\0'; i++) {
		if (chuoi[i] == ' ') {
			dem++;
		}
	}
	return dem;
}

int main() {
	char chuoi[100];

	printf("Nhap chuoi: ");
	gets(chuoi); // Su dung gets() de nhap chuoi co khoang trang

	int soLuongKhoangTrang = demKhoangTrang(chuoi);

	printf("So luong khoang trang trong chuoi: %d\n", soLuongKhoangTrang);

	system("pause");
	return 0;
}
