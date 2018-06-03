#include <stdio.h>

int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d %d\n", a, b);
	// A: yes
	// B: yes
	// C: yes
	// D: 所有输出，12 32767	
	printf("%d%%\n", a);	
	// 输出% : 使用%%
	return 0;
}
