#include <stdio.h>
#include <cmath>

int main() {
	const double pi = acos(-1.0);
	int n;
	scanf("%d", &n);
	printf("%lf %lf\n", sin(n*pi/180), cos(n*pi/180));
}
