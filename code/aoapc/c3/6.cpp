#include <stdio.h>
// 无法运行 add
#include <string.h>

#define maxn 10000000 + 10

// 段溢出 remove
char s[maxn];

int main() {
	scanf("%s", s);
	int tot = 0;
	for(int i = 0; i < strlen(s); i++) {
		// 结果不正确 change
		if(s[i] == '1') tot++;
	}
	printf("%d\n", tot);
}
