#define LOCAL

#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int LEN = 105;

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char n1[LEN], n2[LEN];
	int p, q, t;
	int l, min;
	int len1, len2;

	while(scanf("%s", n1) != EOF) {
		scanf("%s", n2);
		l = 0;

		len1 = strlen(n1), len2 = strlen(n2);

		min = len1 + len2;
		for(p = 0; n1[p] != '\0'; p++) {
			for(q = 0; n2[q] != '\0'; q++) {
				if(p != 0 && q != 0) continue;
				for(t = 0; n1[t+p] != '\0' && n2[t+q] != '\0'; t++) {
					if((n1[t+p]-'0' + (n2[t+q]-'0')) == 4) break;
				}
				if(n1[t+p] == '\0' || n2[t+q] == '\0') {
					l = (p > q) ? p : q;
					if(n1[t+p] == '\0') l += (len2 - q);
					else if(n2[t+q] == '\0') l += (len1 - p);
					if(l < min) min = l;
				}
			}
		}

	
		printf("%d\n", min);
	}
	
}
