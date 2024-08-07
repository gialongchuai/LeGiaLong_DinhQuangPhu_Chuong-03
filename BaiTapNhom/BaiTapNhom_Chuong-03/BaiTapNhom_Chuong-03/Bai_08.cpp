/*
	Viết 1 chương trình xoá một từ nào đó trong chuỗi.
	Ví dụ: Chuỗi ban đầu: “KHOA CNTT”
	Nhập: “CNTT”
	, và kết quả xuất ra: “KHOA”.
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Hàm để xóa từ trong chuỗi
void xoaTu(char* chuoi, const char* tuXoa) {
	char* pos;
	int lenTuXoa = strlen(tuXoa);
	int lenChuoi;

	// Lặp lại cho đến khi không còn từ cần xóa trong chuỗi
	while ((pos = strstr(chuoi, tuXoa)) != NULL) {
		lenChuoi = strlen(chuoi);

		// Di chuyển phần còn lại của chuỗi về trước để loại bỏ từ
		memmove(pos, pos + lenTuXoa, lenChuoi - (pos - chuoi) - lenTuXoa + 1);

		// Xóa khoảng trắng dư thừa giữa các từ
		while (isspace(*chuoi)) {
			memmove(chuoi, chuoi + 1, lenChuoi - (chuoi - pos) + 1);
		}
	}
}

int main() {
	char chuoi[256];
	char tuXoa[256];

	// Nhập chuỗi ban đầu
	printf("Nhap chuoi: ");
	fgets(chuoi, sizeof(chuoi), stdin);

	// Xóa ký tự newline ở cuối chuỗi nếu có
	chuoi[strcspn(chuoi, "\n")] = 0;

	// Nhập từ cần xóa
	printf("Nhap tu can xoa: ");
	fgets(tuXoa, sizeof(tuXoa), stdin);

	// Xóa ký tự newline ở cuối chuỗi nếu có
	tuXoa[strcspn(tuXoa, "\n")] = 0;

	// Xóa từ trong chuỗi
	xoaTu(chuoi, tuXoa);

	// Xuất kết quả
	printf("Chuoi sau khi xoa: \"%s\"\n", chuoi);

	system("pause");
	return 0;
}
