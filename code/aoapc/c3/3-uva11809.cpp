// WRONG!!!
// 应该分两段，考虑尾数与阶码部分。

//#define LOCAL

#include <stdio.h>

// const int FragBit = 8*sizeof(int) / sizeof(bool) - 1;
int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	double a, tmp;
	int e, m, countE, t;

	while(scanf("%lf", &a) == 1 && a != 0e0) {
		m = 0;
		e = 0;
	/* 超时 method1
		tmp = a;

		do {
			e++;
			countE = (1 << (e-1));
			// 主要是这里，但不这样处理，存储不了太大的整数 2^countE
			while(countE > FragBit) {
				tmp = tmp / (1<<(FragBit-1));
				countE -= FragBit-1;
			}
			tmp = tmp / (1<<countE);
		} while(tmp > 1);
	*/	
	
	/* double类型，位操作行不通 method2
		do {
			e++;
			tmp = 1<< ((1<<e) -1);
		
		} while (tmp < a);

		e--;
		a = a - (1<<((1<<e) -1));
	*/
	//	tmp = 1<<((1<<31)-1);
	//	printf("%.3lf\n", tmp);

	/*  当 0<a<1时 
		while(a > 0) {
			a = a * 2 - 1;
			m++;
		}
		m--;
	*/

		printf("%d %d\n", m, e);
	}

}
