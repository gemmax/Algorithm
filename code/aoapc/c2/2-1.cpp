#include <stdio.h>
#include <cmath>

int main() {
	int num;
	for(int a = 1; a < 10; a++) {
		for(int b = 0; b < 10; b++) {
			for(int c = 0; c < 10; c++) {
				if((a != b) && (a != c) && (b != c)) {
					num = a*100+b*10+c;
					if(num == pow(a, 3) + pow(b, 3) + pow(c, 3))
						printf("%d\n", num);
				}
			}
		}
	}
}
