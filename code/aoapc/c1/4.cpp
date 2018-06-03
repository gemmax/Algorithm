#include <stdio.h>

int main() {
	int m, n;
	int x, y;
	scanf("%d %d", &n, &m);
	/* 易遗漏情况
	if(m % 2 == 0) {
		y = m/2 - n;
		x = 2*n - m/2;
		if(x > 0 && y > 0) {
			printf("%d %d\n", x, y);
			return 0;
		}
	}
	printf("No answer\n");
	*/
	x = 2*n - m/2;
	y = m/2 - n;
	if(m % 2 == 0 && x > 0 && y > 0) {
		printf("%d %d\n", x, y);
	} else {
		printf("No answer\n");
	}

}
