#include <stdio.h>

long long factorial(int n) {
	long long m = 1;
	for(int i = 1; i <= n; i++) {
		m *= i;
	}
	printf("%d! : %lld\n", n, m); // 溢出
	return m;
}

long long C(int n, int m) {
	return factorial(n)/(factorial(m) * factorial(n-m));
}

long long C2(int n, int m) {
	long long ans = 1;
	if(m < n-m) m = n-m;
	for(int i = m+1; i <= n; i++) ans *= i;
	for(int i = 1; i <= n-m; i++) ans /= i;
	return ans;
}
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	// printf("%lld\n", C(n, m));
	printf("%lld\n", C2(n, m));
}
