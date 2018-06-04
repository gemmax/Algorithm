#include <stdio.h>
#include <time.h>

int main() {
	int f = 1, s = 0, n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		f = f*i % 1000000;
		s = (s + f) % 1000000;
	}
	printf("%d\n", s);
	printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
}
