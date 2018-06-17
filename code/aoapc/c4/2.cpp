#include <cstdio>
#include <cmath>
int is_prime(int n) {
	if(n <= 1) return 0;
	// int m = sqrt(n);  in:15 out:1
	int m = sqrt(n) + 0.5;
	for(int i = 2; i <= m; i++)
		if(n % i == 0) return 0;
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", is_prime(n));
}
