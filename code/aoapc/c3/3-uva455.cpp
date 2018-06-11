#define LOCAL

#include <stdio.h>
#include <string.h>

const int maxn = 85;
int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T, first = 1;
	char s[maxn];
	int len, k, i;
	scanf("%d", &T);

	while(T--) {
		scanf("%s", s);
		len = strlen(s);
		for(k = 1; k <= len; k++) {
			if(len % k == 0) {
				for(i = k; i < len; i++) {
					if(s[i] != s[i%k]) break;
				}
				if(i == len) break;
			}
		}
		if(first) {printf("%d\n", k); first = 0;}
		else printf("\n%d\n", k);
		
	}
}
