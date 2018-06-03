#include <stdio.h>
#include <cmath>
int main() {
	printf("A:\n");
	printf("11111*11111 = %d\n", 11111*11111);
	printf("111111*111111 = %d\n", 111111*111111);
	printf("111111111*111111111 = %d\n", 111111111*111111111);
	printf("B:\n");
	printf("11111.0*11111.0 = %f\n", 11111.0*11111.0);
	printf("111111.0*111111.0 = %f\n", 111111.0*111111.0);
	printf("111111111.0*111111111.0 = %f\n", 111111111.0*111111111.0);
	printf("C:\n");
	// warning %f : printf("sqrt(-10) = %d\n", sqrt(-10));
	printf("sqrt(-10) = %f\n", sqrt(-10)); // nan
	printf("sqrt(-10) = %lf\n", sqrt(-10)); // nan
	printf("D:\n");
	// warning %f : printf("1.0/0.0 = %d, 0.0/0.0 = %d\n", 1.0/0.0, 0.0/0.0);
	printf("1.0/0.0 = %f, 0.0/0.0 = %f\n", 1.0/0.0, 0.0/0.0);// inf nan
	printf("E:\n");
	// division by zero is undefined : printf("1/0 = %d\n", 1/0);

}
