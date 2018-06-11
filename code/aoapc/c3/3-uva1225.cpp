#define LOCAL

#include <stdio.h>
#include <string.h>

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w",stdout);
	#endif

	int T, i;
	int d, tmp;
	int count[10];

	scanf("%d", &T);
	while(T--) {
		memset(count, 0, sizeof(count));
		scanf("%d", &d);

		for(i = 1; i <= d; i++) {
			tmp = i;
			while(tmp) {
				count[tmp%10]++;
				tmp /= 10;
			}
		}

		for(int i = 0; i < 9; i++) printf("%d ", count[i]);
		printf("%d\n", count[9]);
	}
}
