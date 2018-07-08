#define LOCAL

/*
Accepted OutputAccepted Output		Your OutputYour Output
9797	Cell·data·in·(6,3)·moved·to·(5,10)Cell·data·in·(6,3)·moved·to·(5,10)	9797	Cell·data·in·(6,3)·GONECell·data·in·(6,3)·GONE

but passed oj judgement
*/

#include <stdio.h>
#include <string.h>
#define maxd 100
#define BIG 10000

int r, c, n, d[maxd][maxd], d2[maxd][maxd], ans[maxd][maxd], xflag[maxd];

void copy(char cmd, int p, int q) {
	if(cmd == 'R') {
		for(int i = 1; i <= c; i++)
			d[p][i] = d2[q][i];
	} else {
		for(int i = 1; i <= r; i++)
			d[i][p] = d2[i][q];
	}
}

void del(char cmd) {
	memcpy(d2, d, sizeof(d)); //notice
	int cnt = cmd == 'R' ? r:c;
	int cnt2 = 0;
	for(int i = 1; i <= cnt; i++)
		if(!xflag[i]) copy(cmd, ++cnt2, i); // 这段很简洁
	if(cmd == 'R') r = cnt2;
	else c = cnt2;
}

void ins(char cmd) {
	memcpy(d2, d, sizeof(d)); // notice
	int cnt = cmd == 'R' ? r : c;
	int cnt2 = 0;
	for(int i = 1; i <= cnt; i++){
		if(xflag[i]) copy(cmd, ++cnt2, 0);// 只能copy，不能移动
		copy(cmd, ++cnt2, i);
	}
	if(cmd == 'R') r = cnt2;
	else c = cnt2;
}


int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int r1, c1, r2, c2, q, kase = 0;
	char cmd[10];
	memset(d, 0, sizeof(d));
	while(scanf("%d%d%d", &r, &c, &n) == 3 && r) {
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				d[i][j] = i*BIG + j;
		while(n--) {
			scanf("%s", cmd);
			if(cmd[0] == 'E') {
				scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
				int t = d[r1][c1];
				d[r1][c1] = d[r2][c2];
				d[r2][c2] = t;
			}
			else {
				int a, x;
				scanf("%d", &a);
				memset(xflag, 0, sizeof(xflag));
				for(int i = 1; i<=a; i++) {scanf("%d", &x); xflag[x] = 1;}
				
				if(cmd[0] == 'D')
					del(cmd[1]);
				else if(cmd[0] == 'I')
					ins(cmd[1]);
			}
		}

		memset(ans, 0, sizeof(ans));
		for(int i = 1; i <= r; i++)
			for(int j = 1; j <= c; j++)
				ans[d[i][j]/BIG][d[i][j]%BIG] = i*BIG+j;

		if(kase) printf("\n");
		printf("Spreadsheet #%d\n", ++kase);
		scanf("%d", &q);
		while(q--) {
			scanf("%d%d", &r1, &c1);
			printf("Cell data in (%d,%d) ", r1, c1);
			if(ans[r1][c1] == 0) printf("GONE\n");
			else printf("moved to (%d,%d)\n", ans[r1][c1]/BIG, ans[r1][c1]%BIG);
		}
	}
	return 0;
}
