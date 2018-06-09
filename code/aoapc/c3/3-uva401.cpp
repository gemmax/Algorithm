#define LOCAL

#include <stdio.h>
#include <string.h>

const char mirrors[36] = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

const char* msg[] = {"is not a palindrome", "is a regular palindrome", "is a mirrored string", "is a mirrored palindrome"};
	
int mmap(int a) {
	if(a >= 'A' && a <= 'Z')
		return mirrors[a-'A'];
	return mirrors[a-'0'+25];
}

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int i, len, resIdx;
	int pbit, mbit;
	
	char s[50];
	while(scanf("%s", s) != EOF) {
		pbit = 1; mbit = 1, resIdx = 0;
		len = strlen(s);
		for(i = len/2; s[i]; i++) {
			if(pbit && s[i] != s[len-1-i]) pbit = 0;
			if(mbit && mmap(s[i]) != s[len-1-i]) mbit = 0;
		}
		
		resIdx = (pbit << 0) + (mbit << 1);
		
		printf("%s -- %s.\n\n", s, msg[resIdx]);
	}
	return 0;
}
