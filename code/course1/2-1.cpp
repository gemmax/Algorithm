//#define LOCAL

#include <stdio.h>
#include <string.h>
#define maxd 305

int cir[maxd];

void printInfo(int n) {
	for(int i = 1; i < n; i++)
		printf("%d ", cir[i]);
	printf("%d\n", cir[0]);
}

void del(int idx, int len) {
	if(idx == 0) cir[0] = cir[len-1];
	else {
		for(int i = idx; i < len - 1; i++)
			cir[i] = cir[i+1];
	}
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// 边界情况：m=1出现问题
	int n, m;
	memset(cir, 0, sizeof(cir));
	while(scanf("%d%d", &n, &m) == 2 && n) {
		cir[0] = n;
		for(int i = 1; i < n; i++)
			cir[i] = i;
		
		int i, j = 0;
		for(i = 1; n > 1; i++) {
			i = (i+n)%n;
			j++;
			if(j == m) {
	//			printf("delete %d:\n", i);
				del(i, n);
				n--;
	//			printInfo(n);
				
				if(i) i--;
				j = 0; //当删除第0位时，数组不会自动左移
			}
		}
		printf("%d\n", cir[0]); //结果一定是index为0吗？
	}
}
