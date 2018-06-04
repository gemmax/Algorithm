#include <stdio.h>
#include <cmath>

int main() {
	int n;
	for(int a = 1; a < 10; a++) {
		for(int b = 0; b < 10; b++) {
			n = a * 1100 + b * 11;
			// 浮点运算可能存在误差，在进行浮点数比较时，应考虑到浮点误差。为减小误差影响，一般改为四舍五入。
			// if(pow(floor(sqrt(n)+0.5), 2) == n)
			if((sqrt(n) - floor(sqrt(n))) == 0)
				printf("%d\n", n);
		}
	}
}
