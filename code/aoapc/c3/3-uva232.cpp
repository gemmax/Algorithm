#define LOCAL

#include <stdio.h>
#include <string.h>

const int maxn = 12;
int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int row, col;
	char arr[maxn][maxn];
	int flag[maxn][maxn], t;
	int count, kase = 0, first = 1;

	while(scanf("%d", &row)== 1 && row) {
		scanf("%d", &col);
		memset(flag, 0, sizeof(flag));
		count = 0;

		for(int i = 0; i < row; i++) {
			scanf("%s", arr[i]);
			for(int j = 0; j < col; j++) {
				if(arr[i][j] != '*' && (i == 0 || j == 0 || arr[i-1][j] == '*' || arr[i][j-1] == '*'))
					flag[i][j] = ++count;
			}
		}
		
		if(first) first = 0;
		else printf("\n");
		printf("puzzle #%d:\n", ++kase);
		printf("Across\n");
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(flag[i][j] != 0 && (j == 0 || arr[i][j-1] == '*')) {
					printf("%3d.", flag[i][j]);
					t = j;
					while(t < col && arr[i][t] != '*') {
						printf("%c", arr[i][t]);
						t++;
					}
					printf("\n");
				}
				
			}
		}

		printf("Down\n");
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				if(flag[i][j] != 0 && (i == 0 || arr[i-1][j] == '*')) {
					printf("%3d.", flag[i][j]);
					t = i;
					while(t < row && arr[t][j] != '*') {
						printf("%c", arr[t][j]);
						t++;
					}
					printf("\n");
				}
			}
		}
	}

}
