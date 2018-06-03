#include <stdio.h>

int main() {
	const int price = 95;
	int n;
	double count;
	scanf("%d", &n);
	count = price * n;
	if(count >= 300) {
		count = count * 0.85;
	}
	printf("%.2f\n", count);
}
