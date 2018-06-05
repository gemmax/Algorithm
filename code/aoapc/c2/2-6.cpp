#include <stdio.h>
#include <cstring>

int main() {
	int t, t2, t3;
	int flag[9];
	for(int a = 1; a < 10; a++) {
		for(int b = 1; b < 10; b++) {
			for(int c = 1; c < 10; c++) {
				memset(flag, 0, sizeof(flag));
				if((a != b) && (a != c) && (b != c)) {
					t = a * 100 + b * 10 + c;
					flag[a-1] = 1; flag[b-1] = 1; flag[c-1] = 1;
					t3 = t * 3;
					if(t3 >= 1000) continue;
					if(flag[t3/100 - 1] || flag[t3/10%10 - 1] || flag[t3%10 - 1]){
						continue;
					}
					else{
						flag[t3/100 - 1] = 1;
						flag[t3/10%10 - 1] = 1;
						flag[t3%10 - 1] = 1;
					}

					t2 = t * 2;
					if(t2 >= 1000) continue;
					if(flag[t2/100 - 1] || flag[t2/10%10 - 1] || flag[t2%10 - 1]){
						continue;
					}
					printf("%d %d %d\n", t, t2, t3);	
				}
			}
		}
	}
}
