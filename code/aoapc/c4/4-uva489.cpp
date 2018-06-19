// #define LOCAL

#include <stdio.h>
#include <string.h>

const int chance = 7;
void judge(char * s, int s_size, char c, int * wrong, bool * ok, bool * nope) {
	bool fd = false;
	for(int i = 0; i < s_size; i++) {
		if(*(s+i) == c) {
			*(s+i) = ' ';
			if(!fd) fd = true;
		}
	}

	if(!fd) *wrong = *(wrong) + 1;

//	printf("wrong: %d\n", *(wrong));

	*ok = true;
	for(int i = 0; i < s_size; i++)
		if(*(s+i) != ' ') {*ok = false;break;}
	if((*wrong) == chance) *nope = true;
}


int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	const int LEN = 1000;
	int rd;
	char s[LEN], g[LEN], c[27];
	int wrong, s_size;
	bool ok, nope;

	while(scanf("%d", &rd) == 1 && rd != -1) {
		scanf("%s%s", s, g);

		wrong = 0; ok = false; nope = false;
		memset(c, 0, sizeof(c));
		s_size = strlen(s);
		
		for(int i = 0; g[i] != '\0'; i++) {
			for(int j = 0; j < 27; j++) {
				if(c[j] == g[i]) break;
				else if(c[j] == 0) {
					c[j] = g[i];
					break;
				}
			}
		}
//		puts(c);

		for(int i = 0; c[i] != 0; i++) {
			judge(s, s_size, c[i], &wrong, &ok, &nope);
			if(ok || nope) break;
		}

		printf("Round %d\n", rd);
		if(ok) puts("You win.");
		else if(nope) puts("You lose.");
		else puts("You chickened out.");
	}

}
