#include <stdio.h>
#define PI 3.1415926
int main() {
	double r, h;
	double area;
	scanf("%lf %lf", &r, &h);
	area = 2*r*r*PI + 2*PI*r*h;
	printf("Area = %.3lf\n", area);
}
