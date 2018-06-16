// Learning from https://blog.csdn.net/noob_f/article/details/51255109

#define LOCAL

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
const int M = 10;
const int E = 31;
const int LEN = 200;
int main() {

	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	double A[M][E];// 10进制尾数
	int B[M][E]; // 10进制指数
	double a, t;
	char s[LEN], sa[LEN],sb[LEN]; //有没有更好的解决方法？
	double inA;
	int inB;

	for(int i = 0; i < 10; i++) {
		for(int j = 1; j <= 30; j++) {
			a = 1- 1.0/(1<<(i+1));

			t = ((1<<j) - 1)*log10(2);
			B[i][j] = (int)t;

			t = t - B[i][j];
			t = pow(10, t);
			A[i][j] = a * t;
			while(A[i][j] < 1) {A[i][j] *= 10; B[i][j]--;}

		}
	}

	while(scanf("%s", s) == 1 && strcmp(s, "0e0") != 0) {
		int idxe = strchr(s, 'e') - s;
		strncpy(sa, s, idxe);
		strcpy(sb, s+idxe+1);

		sscanf(sa, "%lf", &inA);
		//inA = atof(sa);
		sscanf(sb, "%d", &inB);

		// printf("A:%lf\tB:%d\n", inA, inB);
		for(int i = 0; i < 10; i++) {
			for(int j = 1; j <= 30; j++) {
				if(B[i][j] == inB) {
					// printf("A %lf \t B %d\n", A[i][j], B[i][j]);
					if(fabs(A[i][j] - inA) < 0.000001)
						printf("%d %d\n", i, j);
				}
					
			}
		}
	}
}
