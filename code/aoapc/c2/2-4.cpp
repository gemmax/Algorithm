#include <stdio.h>
#include <cmath>
int main() {
	int n, m, kase = 0;
	double r;
	while(scanf("%d%d", &n, &m) == 2 && (n||m)) {
		r = 0.0;
		for(int i = n; i <= m; i++) {
			r += 1.0/pow(i, 2);
		}
		printf("Case %d: %.5f\n", ++kase, r);
	}
}
