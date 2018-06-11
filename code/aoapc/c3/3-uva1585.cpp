#define LOCAL

#include <stdio.h>
const int maxn = 85;

char s[maxn];

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T;
	int flag, score;
	scanf("%d", &T);

	while(T--) {	
		scanf("%s", s);
		flag = 0, score = 0;
		for(int i = 0; s[i]; i++) {
			if(s[i] == 'O') flag++;
			else flag = 0;
			score += flag;
		}
		printf("%d\n", score);
	}
}
