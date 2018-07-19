#include <stdio.h>

int catelan(int rest, int queue) {
	int t = 0, stack = rest - queue;

	if(queue == 0) return 1;

	if(stack > 0) t += catelan(rest - 1, queue);

	for(int i = 1; i <= queue; i++) {
		t += catelan(rest - 1, queue - i);
	}
	return t;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", catelan(n,n));
}
