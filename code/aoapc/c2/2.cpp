#include <stdio.h>

int main() {
	int n1;
	int count = 0;
	scanf("%d", &n1);
	// while(n != 1) { 由题意知，使用n > 1更贴切
	// 避开了对longlong类型的输入输出。	
	long long n = n1;
	while(n > 1) {
		if(n % 2 == 1) {
			// 中间变量可能溢出，采用long long类型存储
			n = 3*n+1;
		}
		else {
			n = n/2;
		}
		count++;
	}
	printf("%d\n", count);
}
