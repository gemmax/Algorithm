#include <stdio.h>

int sumArr(int a[], int n) {
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans+=a[i];
	return ans;
}

int sumPt(int * a, int n) {
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += *(a+i);
	return ans;
}

int main() {
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("%d\n", sumArr(a+2, 8));
	printf("%d\n", sumPt(a+2, 8));
}
