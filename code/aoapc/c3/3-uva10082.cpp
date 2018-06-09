#include <stdio.h>

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	int i, c;
	while((c = getchar()) != EOF) {
		for(i = 0; s[i]; i++) {
			if(c == s[i]) break;
		}
		if(s[i]) printf("%c", s[i-1]);
		else printf("%c", c);
	}
	return 0;
}
