#define LOCAL

#include <stdio.h>
#include <string.h>

const int maxn = 100005;
int mmap[maxn];

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int m, x, y;
	int T,q;

	memset(mmap, 0, sizeof(mmap));
	for(int m = 1; m <=100000; m++) {
		x = m, y = m;
		while(x>0) {
			y += x%10;
			x /= 10;
		}
		
		if(mmap[y] == 0) mmap[y] = m;
	}

	scanf("%d", &T);
	while(T--) {
		scanf("%d", &q);
		printf("%d\n", mmap[q]);
	}
}

