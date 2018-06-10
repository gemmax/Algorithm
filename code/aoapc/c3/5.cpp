#define LOCAL

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// 存储量：当对输入中每个数操作两次及以上，且操作不能同时处理，即只能串行执行时，必须借助数组（guess）

const int MAX = ((unsigned int)-1) >> 1, MIN = ~MAX;

void q1() {
	int d, count = 0;
	while(scanf("%d", &d) != EOF) {
		count++;
	}
	printf("%d\n", count);
}

void q2() {
	int d, count = 0;
	int max = MIN, min = MAX;
	double mean = 0;
	while(scanf("%d", &d) != EOF) {
		if(d > max) max = d;
		if(d < min) min = d;
		mean += d;
		count++;
	}
	printf("%d %d %lf\n", max, min, mean/count);
}


// -------------------------------------must use array-----------------
void q3() {
	const int MAXN = 105;
	int arr[MAXN], d, min = MAX, n=0;
	int aidx, bidx, t;
	while(scanf("%d", &d) != EOF) {
		arr[n++] = d;
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(i != j) {
				t = abs(arr[i] - arr[j]);
				if(t < min) {
					aidx = i;
					bidx = j;
					min = t;
				}
			}
		}
	}
	printf("%d %d\n", arr[aidx], arr[bidx]);

}

void q4() {
	int max = MIN, max2 = MIN;
	int d;
	while(scanf("%d", &d) != EOF) {
		if(d > max) {
			max2 = max;
			max = d;
		} else {
			if(d > max2) {
				max2 = d;
			}
		}
	}
	printf("%d\n", max2);
}

//-----------------------------------must use array---------------------
void q5() {
	const int maxn = 105;
	int arr[maxn], d, n = 0;
	double mean = 0, variance = 0;
	while(scanf("%d", &d) != EOF) {
		arr[n++] = d;
	}
	for(int i = 0; i < n; i++) {
		mean += arr[i];
	}
	mean = mean / n;
	for(int i = 0; i < n; i++) {
		variance += pow((arr[i] - mean), 2);
	}
	variance /= n;
	printf("%lf\n", variance);
}

//----------------------------------must use array---------------------
void q6() {
	const int maxn = 105;
	int arr[maxn], d, n = 0, count = 0;
	double mean = 0;
	while(scanf("%d", &d) != EOF) {
		arr[n++] = d;
		mean += d;
	}
	mean /= n;
	for(int i = 0; i < n; i++) {
		if(arr[i] <= (mean+0.1)) count++; //因为浮点数比较可能有精度误差
	}
	printf("%d\n", count);
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	//q1();
	//q2();
	//q3();
	//q4();
	//q5();
	q6();
}
