#include <stdio.h>
#include <cstring>
#define maxn 10

// 输入n <= 10
int main() {
	int n, x, y, count;
	int a[maxn][maxn];
	scanf("%d", &n);
	
	memset(a, 0, sizeof(a));
	count = a[x = 0][y = n-1] = 1;
	
	while(count < n*n) {	
		while(x+1 < n && !a[x+1][y]) a[++x][y] = ++count;
		while(y-1 >=0 && !a[x][y-1]) a[x][--y] = ++count;
		while(x-1 >=0 && !a[x-1][y]) a[--x][y] = ++count;
		while(y+1 < n && !a[x][y+1]) a[x][++y] = ++count;
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}
