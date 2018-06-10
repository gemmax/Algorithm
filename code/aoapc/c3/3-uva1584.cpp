#define LOCAL

#include <stdio.h>
#include <string.h>
const int maxn = 105;

char s[maxn];

bool less(char* s, int len, int p, int ans) {
	for(int i = 0; i < len; i++) {
		if(s[(p+i)%len] < s[(ans+i)%len]) return true;
		else if(s[(p+i)%len] > s[(ans+i)%len])	return false;
	}
	return false;
}


int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T;
	int len, ansHead;
	scanf("%d", &T);
	while(T--) {
		ansHead = 0;
		scanf("%s", s);
		len = strlen(s);
		for(int i = 1; i < len; i++) 
			if(less(s, len, i, ansHead)) ansHead = i;
		for(int i = 0; i < len; i++)
			printf("%c", s[(ansHead+i)%len]);
		printf("\n");
	}
}
