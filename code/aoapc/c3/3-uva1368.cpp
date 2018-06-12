#define LOCAL

#include <stdio.h>
#include <string.h>

const int maxn = 1010;
//const int maxm = 55;

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int T, m, n, maxIdx;
	int count[maxn][4];
	char amap[4] = {'A', 'C', 'G', 'T'};
	//char s[maxm];
	int s;
	int hamming;

	scanf("%d", &T);
	while(T--) {
		hamming = 0;
		scanf("%d%d", &m, &n);
		//memset(count, 0, sizeof(count));
		memset(count, 0, maxn * 4 * sizeof(int));
	

		/* 输入输出IO与CPU计算速度不匹配
		for(int i = 0; i < m; i++) {
			scanf("%s", s);
			printf("%d\n", (int)strlen(s));
			for(int j = 0; j < n; j++) {
				if(s[j] == 'A') count[j][0]++;
				else if(s[j] == 'C') count[j][1]++;
				else if(s[j] == 'G') count[j][2]++;
				else if(s[j] == 'T') count[j][3]++;
			}
			printf("count[3][] A %d C %d G %d T %d\n", count[3][0],count[3][1],count[3][2],count[3][3]);
		}
		*/

		for(int i = 0; i < m; i++) {
			getchar();
			for(int j = 0; j < n; j++) {
				s = getchar();
				if(s == 'A') count[j][0]++;
				else if(s == 'C') count[j][1]++;
				else if(s == 'G') count[j][2]++;
				else if(s == 'T') count[j][3]++;

			}
		}

		

		for(int i = 0; i < n; i++) {
			maxIdx = 0;
			for(int j = 1; j < 4; j++) {
				if(count[i][j] > count[i][maxIdx]) maxIdx = j;
			}
			printf("%c", amap[maxIdx]);
			for(int j = 0; j < 4; j++) {
				if(j != maxIdx) hamming += count[i][j];
			}
		}
		printf("\n%d\n", hamming);

	}
}
