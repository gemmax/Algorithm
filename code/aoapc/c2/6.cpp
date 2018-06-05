#include <stdio.h>

int main() {
	const int MAX = ((unsigned int)-1 >> 1);
	const int MIN = ~MAX;
	int kase = 0;
	int min, max, mean, n, t;
	while(scanf("%d", &n) == 1 && n) {
		min = MAX; max = MIN; mean = 0;
		for(int i = 0; i < n; i++) {
			scanf("%d", &t);
			if(min > t) min = t;
			if(max < t) max = t;
			mean += t;
		}
		if(kase) printf("\n");
		printf("Case %d: %d %d %.3f\n", ++kase, min, max, ((double)mean)/n);
	}
	
}
