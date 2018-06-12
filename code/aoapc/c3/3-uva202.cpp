#define LOCAL

#include <stdio.h>
#include <string.h>

const int maxn = 3005;
int dividend[maxn];
int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	char s[100];
	int divisor;
	int len, tmp;
	int repeatIdx, startIdx, i, j;
	//int first = 1;

	while(scanf("%d", &dividend[0]) != EOF) {
		scanf("%d", &divisor);	
	
		tmp = dividend[0]/divisor;
		sprintf(s, "%d.", tmp);
		len = strlen(s);

		i = 1;
		while(true) {
			dividend[i] = dividend[i - 1] % divisor * 10;
			if(i <= 50) {
				s[len] = (dividend[i] / divisor) + '0';
				s[++len] = '\0';
			}
			for(j = 1; j < i; j++)
				if(dividend[i] == dividend[j]) { 
					startIdx = j; 
					repeatIdx = i; 
					break;
				}
			if(j != i) break;
			i++;
		}
	
	//	if(first) first = 0;
	//	else printf("\n");
		
		printf("%d/%d = ", dividend[0], divisor);
		for(i = 0; s[i] != '.'; i++) {
			printf("%c", s[i]);
		}
	
		for(int deci = 0; s[i+deci]; deci++) {
			if(deci == repeatIdx) break;
			if(deci == startIdx) printf("(");
			printf("%c", s[i+deci]);
		}
		if(repeatIdx > 50) printf("...");
		printf(")\n");

		printf("   %d = number of digits in repeating cycle\n\n", repeatIdx - startIdx);
	}
	
}
