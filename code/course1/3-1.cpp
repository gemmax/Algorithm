#include <stdio.h>
#include <stdlib.h>

//#define LOCAL

#define maxd 82

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int n;
	char s[maxd];
	const char ps[28] = "bcdefghijklmnopqrstuvwxyza";
	
	gets(s);
	n = atoi(s);
	while(n--) {
		gets(s);
		for(int i = 0; s[i] != '\0'; i++) {
			if(s[i] >= 'A' && s[i] <= 'Z') {
				printf("%c", ps[s[i]-'A'] - 'a' + 'A');
			} else if(s[i] >= 'a' && s[i] <= 'z') {
				printf("%c", ps[s[i] - 'a']);
			} else {
				printf("%c", s[i]);
			}
		}
		printf("\n");
	}

}
