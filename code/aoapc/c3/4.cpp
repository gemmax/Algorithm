#include <stdio.h>
#include <cstring>

bool isValid(int n, int flag) {
	int tmp = n, resflag = 0;
	while(tmp != 0) {
		resflag = 1<<(tmp%10);
		if((flag & resflag) != 0)
			return false;
		tmp /= 10;
	}
	if(tmp) return false;
	return true;
}

int main() {
	// 从第0位开始
	int i, ssize, flag = 0;
	int a,b,abc,d,e,de,n1,n2,n;
	int count = 0;
	char s[10];
	int set[10];
	
	memset(set, -1, sizeof(set));
	scanf("%s", s);
	for(i = 0; s[i] != '\0'; i++) {
		set[i] = s[i]-'0';
		flag = flag | (1<<set[i]);
	}
	ssize = i;
	flag = ~flag; // flag & resflag != 0 存在非集合中数字

	for(i = 0; i < ssize; i++) {
		a = set[i];
		for(int j = 0; j < ssize; j++) {
			b = set[j];
			for(int z = 0; z < ssize; z++) {
				abc = a*100+b*10+set[z];
				for(int k = 0; k < ssize; k++) {
					d = set[k];
					for(int l = 0; l < ssize; l++) {
						e = set[l];
						de = d*10+e;
						n1 = abc*e;
						
						if(!isValid(n1, flag)) continue;
						
						n2 = abc*d;

						if(!isValid(n2, flag)) continue;
						
						n = abc * de;

						if(!isValid(n, flag)) continue;

						printf("<%d>\n", ++count);
						printf("%5d\nX%4d\n-----\n%5d\n%-5d\n-----\n%d\n\n", abc, de, n1, n2, n);

	
						
					}
				}
			}
		}
	}
	printf("The number of solutions = %d\n", count);
}
