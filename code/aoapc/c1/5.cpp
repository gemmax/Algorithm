#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	/* 尽可能减少if-else层数，防止漏算。
	if(a > b) {
		if(a > c) {
			if (b > c) {
				printf("%d %d %d\n", c, b, a);
			}
			else {
				printf("%d %d %d\n", b, c, a);
			}
		}
		else {
			printf("%d %d %d\n", b, a, c);
		}
	}
	else {
		if(a < c) {
			if(b > c) {
				printf("%d %d %d\n", a, c, b);
			}
			else {
				printf("%d %d %d\n", a, b, c);
			}
		}
		else {
			printf("%d %d %d\n", c, a, b);
		}
	}
	*/
	int tmp;
	if(a > b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	if (b > c) {
		tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d\n", a, b, c);

}
