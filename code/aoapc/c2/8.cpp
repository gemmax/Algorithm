#include <stdio.h>
#include <cmath>
int main() {
	double i;
	// 无限循环 for(i = 0; i != 10; i+=0.1) {
	// 无限循环 for(i=0; i != 10.0; i+=0.1){
	for(i=0; fabs(10.0-i) > 1e-8; i+=0.1){
		printf("%.1f\n", i);
	}
	return 0;
}
