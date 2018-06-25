#define LOCAL

#include <stdio.h>

const int MAX = 51;
const int max_A = 12;

typedef struct{
	int r;
	int c;
}Point;

void ex(Point map[][MAX], int r, int c, int a[]) {
	Point t1, t2;
	t1.r = 0; t1.c = 0;
	t2.r = 0; t2.c = 0;
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			if(map[i][j].r == a[0] && map[i][j].c == a[1]) {
				t1.r = i;
				t1.c = j;
			}
			if(map[i][j].r == a[2] && map[i][j].c == a[3]) {
				t2.r = i;
				t2.c = j;
			}
		}
	}

	if(t1.r) { map[t1.r][t1.c].r = a[2]; map[t1.r][t1.c].c = a[3];}
	if(t2.r) { map[t2.r][t2.c].r = a[0]; map[t2.r][t2.c].c = a[1];}
}

void dc(Point map[][MAX], int r, int c, int a[]) {
	int t;
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			t = 0;
			for(int k = 0; k < a[0]; k++) {
				if(map[i][j].c == a[k+1]) map[i][j].c = 0;
				if(map[i][j].c > a[k+1]) t++;
			}
			if(map[i][j].c) map[i][j].c -= t;
		}
	}
}

void dr(Point map[][MAX], int r, int c, int a[]) {
	int t;
	for(int j = 1; j <= c; j++) {
		for(int i = 1; i <= r; i++) {
			t = 0;
			for(int k = 0; k < a[0]; k++) {
				if(map[i][j].r == a[k+1]) map[i][j].r = 0;
				if(map[i][j].r > a[k+1]) t++;
			}
			if(map[i][j].r) map[i][j].r -= t;
		}
	}
}

void ic(Point map[][MAX], int r, int c, int a[]) {
	int t;
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			t = 0;
			for(int k = 0; k < a[0]; k++) {
				if(map[i][j].c >= a[k+1]) t++;
			}
			if(map[i][j].c) map[i][j].c += t;
		}
	}
}

void ir(Point map[][MAX], int r, int c, int a[]) {
	int t;
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			t = 0;
			for(int k = 0; k < a[0]; k++) {
				if(map[i][j].r >= a[k+1]) t++;
			}
			map[i][j].r += t;
		}
	}
}

int readCMD(int a[]) {
	int ch, ch2, op = 0;
	ch = getchar();
	while(ch < 'A' || ch > 'Z') ch = getchar();
	ch2 = getchar();
	
	if(ch == 'E' && ch2 == 'X') op = 1;
	if(ch == 'D' && ch2 == 'R') op = 2;
	if(ch == 'D' && ch2 == 'C') op = 3;
	if(ch == 'I' && ch2 == 'R') op = 4;
	if(ch == 'I' && ch2 == 'C') op = 5;

	/* Wrong
	do{
		a[0] = getchar();
	} while(a[0] < '0' || a[0] > '9');

	a[0] = a[0] - '0';
	*/
	scanf("%d", &a[0]);

	if(op == 1) {
		for(int i = 0; i < 3; i++)
			scanf("%d", &a[i+1]);
	}
	else if(op > 1 && op < 6) {
		for(int i = 0; i < a[0]; i++)
			scanf("%d", &a[i+1]);
	}

	return op;
}

void operateCMD(Point map[][MAX], int r, int c, int a[max_A], int op_code) {
	if(op_code == 1) {
		ex(map, r, c, a);
	}
	else if(op_code == 2) {
		// for(int i = 0; i < a[0]; i++) {
		dr(map, r, c, a);
		// }
	}
	else if(op_code == 3) {
		dc(map, r, c, a);
	}
	else if(op_code == 4) {
		ir(map, r, c, a);
	}
	else if(op_code == 5) {
		ic(map, r, c, a);
	}
}

void printfInfo(Point map[][MAX], int r, int c) {
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++)
			printf("(%3d,%3d)", map[i][j].r, map[i][j].c);
		printf("\n");
	}
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int kase = 0;
	int a[max_A];
	// int row[MAX], col[MAX];
	Point map[MAX][MAX];
	int r, c, r1, c1;
	int op, query, op_code;
	char ch1, ch2;

	while(scanf("%d%d", &r, &c) == 2 && r && c) {
		// for(int i = 0; i <= r; i++) row[i] = i;
		// for(int i = 0; i <= c; i++) col[i] = i;
		for(int i = 0; i <= r; i++) {
			for(int j = 0; j <= c; j++) {
				map[i][j].r = i;
				map[i][j].c = j;
			}
		}

		scanf("%d", &op);

		while(op--) {
			op_code = readCMD(a);
			operateCMD(map, r, c, a, op_code);
		}
		
		scanf("%d", &query);
		if(kase) printf("\n");
		printf("Spreadsheet #%d\n", ++kase);
		while(query--) {
			scanf("%d%d", &r1, &c1);
			printf("Cell data in (%d,%d) ", r1, c1);
			if(map[r1][c1].r && map[r1][c1].c)
				printf("moved to (%d,%d)\n", map[r1][c1].r, map[r1][c1].c);
			else
				printf("GONE\n");

		}
		
	}
}
