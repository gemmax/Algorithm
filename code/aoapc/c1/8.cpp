#include <stdio.h>

int main() {
	printf("A:\n");
	printf("integer min = %d, max = %d\n", ~((unsigned int)(-1) >> 1), (unsigned int)(-1) >> 1);
	printf("B:\n");
	printf("C:\n");
	printf("D:\n");
	printf("%d\n", false&&true||true);//(false&&true)||true = 1, false&&(true||true) = 0
	// output : 1 是(false && true) || true 还是从左到右的顺序呢？
	printf("%d\n", true || true && false);
	// output : 1 是(false && true) || true.
	printf("E:\n");
}
