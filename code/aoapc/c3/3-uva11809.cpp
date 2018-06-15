#include <stdio.h>

const int FragBit = 4*sizeof(int) / sizeof(bool);
int main() {
	double a, tmp;
	int e, m, countE, t;

	while(scanf("%lf", &a) == 1 && a != 0e0) {
		m = 0;
		e = 0;

		do {
			tmp = a;
			e++;
			countE = (1 << e) - 1;
			printf("count:%d\t e:%d\n", countE, e);
			while(countE > FragBit) {
				tmp = tmp / (1<<(FragBit-1));
				countE -= FragBit-1;
			}
			tmp = tmp / (1<<countE);
			printf("tmp:%.3lf", tmp);
		} while(tmp > 1);
		
		a = tmp;
		
		printf("%d %d\n", m, e);
	}

}
