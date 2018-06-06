#include <stdio.h>
#include <cstring>
#define max 1005

int d[max];
int main() {
	int n, k, first = 1;
	memset(d, 0, sizeof(d));
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= k; j++) {
			if(i % j == 0)
				d[i] = d[i]^1;
				// d[i] = !d[i];
		}
	}
	for(int i = 1; i <= n; i++) {
		if(!d[i]) continue;
		if(first) first = 0;
		else printf(" ");
		printf("%d", i);
	}
	printf("\n");
}
