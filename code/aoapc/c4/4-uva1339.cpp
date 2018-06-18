#define LOCAL

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void * a, const void * b) {
	return (*(int*)b - *(int*)a);
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	const int len = 102;
	char s1[len], s2[len];
	int count1[26], count2[26];
	bool isOk;

	while(scanf("%s", s1) != EOF) {
		isOk = true;
		scanf("%s", s2);
		memset(count1, 0, sizeof(count1));
		memset(count2, 0, sizeof(count2));
		for(int i = 0; s1[i] != '\0'; i++) {
			count1[s1[i] - 'A']++;
			count2[s2[i] - 'A']++;
		}

		qsort(count1, 26, sizeof(int), cmp);
		qsort(count2, 26, sizeof(int), cmp);

		for(int i = 0; i < 26; i++) {
			if(count1[i] != count2[i]) {
				isOk = false;
				break;
			}
		}
	
		puts(isOk ? "YES" : "NO");
	}
}
