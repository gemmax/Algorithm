#include <stdio.h>

int main() {
	const int MAX = ((unsigned int)-1 >> 1);
	const int MIN = ~MAX;
	int a, count = 0;
	int min = MAX, max = MIN;
	double mean = 0.0;
	while(scanf("%d", &a) == 1) {
		if(a < min) min = a;
		if(a > max) max = a;
		mean += a;
		count++;
	}
	mean = mean / count;
	printf("%d %d %.3f\n", min, max, mean);
}
