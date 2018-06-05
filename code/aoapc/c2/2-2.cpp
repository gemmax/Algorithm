#include <stdio.h>

//Ctrl + D 停止输入

int main() {
	int a, b, c, i, kase = 1;
	while(scanf("%d%d%d", &a, &b, &c) != EOF) {
		for(i = 10; i <=100; i++) {
			if((i % 3 == a) && (i % 5 == b) && (i % 7 == c)) {
				printf("Case %d: %d\n", kase++, i);
				break;
			}
		}
		if(i == 101) printf("Case %d: No answer\n", kase++);
	}
	return 0;
}
