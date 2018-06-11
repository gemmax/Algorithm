#define LOCAL

#include <stdio.h>
#include <string.h>

const int maxn = 85;

char s[maxn];

void counter(char c, int value, int count[4]) {
	switch(c) {
		case 'C': count[0] += value;break;
		case 'H': count[1] += value;break;
		case 'O': count[2] += value;break;
		case 'N': count[3] += value;break;
	}
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T;
	int count[4];
	double molar = 0;
	scanf("%d", &T);
	while(T--) {
		int j, tmp, i = 0;
		memset(count, 0, sizeof(count));

		scanf("%s", s);
		while(s[i]) {
			j = i+1;
			tmp = 0;
			for(;s[j] && s[j] >= '0' && s[j] <= '9'; j++) {
				tmp = tmp * 10 + s[j] - '0';
			}
			counter(s[i], tmp, count);
			if(j != i+1) i = j;
			else {
				counter(s[i], 1, count);
				i++;
			}
			
		}
		molar = count[0] * 12.01 + count[1] * 1.008 + count[2] * 16.00 +count[3] * 14.01;
		printf("%.3f\n", molar);
	}
	
}
