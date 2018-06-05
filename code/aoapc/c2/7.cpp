#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
// 2	for(int i = 2; i <= 2*n; i+=2)
// 1		printf("%d\n", 2 * i);
		printf("%d\n", i);
	return 0;
}
