#include <stdio.h>
#include <cmath>

int main() {
	double quarterPI = 0.0;
	int n = 0;
	double t;
	do {
		t = 1.0 / (2*n+1);
		quarterPI += pow(-1, n)*t;
		n++;
	} while(t > 1e-6);
	printf("%lf\n", quarterPI);
}
