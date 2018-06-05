#include <stdio.h>

int main() {
	int n, s = 0;
	scanf("%d", &n);
/*	do {
		for(int i = 0; i < s; i++)
			printf(" ");
		for(int i = 0; i < 2*n - 1; i++)
			printf("#");
		s++;
		printf("\n");
	} while(--n);
*/
	while(n--) {
		for(int i = 0; i < s; i++)
			printf(" ");
		for(int i = 0; i < 2*n + 1; i++)
			printf("#");
		s++;
		printf("\n");
	}
}
