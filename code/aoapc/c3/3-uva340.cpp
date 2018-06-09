#define LOCAL

#include <stdio.h>
#include <cstring>

const int MAX = 1010;
int  a[MAX], b[MAX];

int main() {

	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n, acount[10], bcount[10];
	int i, kase = 0;
	int ra, rb;
	while(scanf("%d", &n) == 1 && n) {
		memset(acount, 0, sizeof(acount));
		printf("Game %d:\n", ++kase);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);

		for(i = 0; i < n; i++) acount[a[i]]++;

		while(scanf("%d", &b[0]) == 1) {
			ra = 0, rb = 0;
			for(i = 1; i < n; i++) scanf("%d", &b[i]);
			if(b[0] == 0)	break;
			memset(bcount, 0, sizeof(bcount));
			for(i = 0; i < n; i++) if(a[i] == b[i]) ra++;
			for(i = 0; i < n; i++) bcount[b[i]]++;
			for(i = 1; i < 10; i++) rb += (acount[i] < bcount[i] ? acount[i] : bcount[i]);
			
			rb = rb - ra;
			printf("    (%d,%d)\n", ra, rb);
		}
	}
}

