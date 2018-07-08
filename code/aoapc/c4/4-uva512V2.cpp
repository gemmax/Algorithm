#define LOCAL

#include <stdio.h>
#include <string.h>
#define maxd 10000

typedef struct{
	char c[5];
	int r1, c1, r2, c2;
	int a, x[10];
}Command;

Command cmd[maxd];

void simulate(int * r1, int * c1, int cmds) {
	for(int i = 0; i < cmds; i++) {
		if(cmd[i].c[0] == 'E') {
			if(cmd[i].r1 == *r1 && cmd[i].c1 == *c1) { // 原本遗漏此判断
				*r1 = cmd[i].r2;
				*c1 = cmd[i].c2;
			} else if(cmd[i].r2 == *r1 && cmd[i].c2 == *c1) { // 遗漏
				*r1 = cmd[i].r1;
				*c1 = cmd[i].c1;
			}
		} else if(cmd[i].c[0] == 'D') {
			int * t = cmd[i].c[1] == 'R' ? r1:c1;
			int tmp = 0;
			for(int j = 0; j < cmd[i].a; j++) {
				if(cmd[i].x[j] == *t) *t = 0;
				if((*t) && cmd[i].x[j] < (*t)) tmp++;
			}
			if(*t) (*t) -= tmp;

		} else {
			int * t = cmd[i].c[1] == 'R' ? r1:c1;
			int tmp = 0;
			for(int j = 0; j < cmd[i].a; j++) {
				if(cmd[i].x[j] <= *t) tmp++;
			}
			(*t) += tmp; 
		}
	}
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	int r, c, cmds, q, kase = 0;
	while(scanf("%d%d%d", &r, &c, &cmds) == 3 && r) {
		for(int i = 0; i < cmds; i++) {
			scanf("%s", cmd[i].c);
			if(cmd[i].c[0] == 'E'){
				scanf("%d%d%d%d", &cmd[i].r1, &cmd[i].c1, &cmd[i].r2, &cmd[i].c2);
			} else {
				scanf("%d", &cmd[i].a);
				for(int j = 0; j < cmd[i].a; j++)
					scanf("%d", &cmd[i].x[j]);
			}
		}
	
		scanf("%d", &q);
		if(kase) printf("\n");
		printf("Spreadsheet #%d\n", ++kase);
		while(q--) {
			scanf("%d%d", &r, &c);
			printf("Cell data in (%d,%d) ", r, c);
			simulate(&r, &c, cmds);
			if(!r || !c) printf("GONE\n");
			else printf("moved to (%d,%d)\n", r, c);
		}
	}
	return 0;
}
