#include <stdio.h>

// 分数化小数 输出精确到小数点后c位：  %.lf c (double)a/b
int main() {
	int a, b, c, kase = 0;
	while(scanf("%d%d%d", &a, &b, &c)== 3 && (a||b||c)) {
		printf("Case %d: %.*lf\n", ++kase, c, (double)a/b);
	}
	

}
