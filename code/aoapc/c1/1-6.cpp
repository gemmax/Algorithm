#include <stdio.h>
#include <cmath>

int main() {
	int a, b, c, t;
	scanf("%d%d%d", &a, &b, &c);
	if(a > b) {t = a; a = b; b = t;}
	if(a > c) {t = a; a = c; c = t;}
	if(b > c) {t = b; b = c; c = t;}
	if(a + b > c) {
		if(pow(a, 2) + pow(b, 2) == pow(c, 2)) {
			printf("yes\n");
		}
		else {
			printf("no\n");
		}
	}
	else {
		printf("not a triangle\n");
	}
}
