#define LOCAL

#include <stdio.h>
#include <string.h>

bool chosen(int * arr, int a_size, int a_step, int b_step, int * a, int * b) {
	int beginA = (*a) - 1; // 为下标，从0开始，a指向值为从1开始。
	int beginB = (*b) - 1;
	bool rlt = false;

	for(int i = 0; i < a_size; i++)
		if(*(arr+i) != 0) {rlt = true; break;}

	while(rlt) {
		if(a_step && *(arr + beginA)) {
			a_step--;

			if(!a_step) {
				*a = *(arr+beginA);
				break;
			}

		}
		beginA = (beginA + 1) % a_size; 
	}

	while(rlt) {
		if(b_step && *(arr + beginB)) {
			b_step--;

			if(!b_step) {
				*b = *(arr+beginB);
				break;
			}	
		}
		if(!beginB) beginB = a_size;
		beginB--;

	}

	*(arr+beginA) = 0;
	*(arr+beginB) = 0;

	return rlt;
}

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	const int N = 20;
	int cir[N];
	int n, k, m;
	int a, b;
	bool first;
	while(scanf("%d%d%d", &n, &k, &m) == 3 && n && k && m) {
		first = true;
		memset(cir, 0, sizeof(cir));
		for(int i = 0; i < n; i++) cir[i] = i + 1;
		
		a = 1; b = n; 
		while(chosen(cir, n, k, m, &a, &b)) {
			if(first) first = false;
			else printf(",");
			
			if(a == b) printf("%3d", a);
			else printf("%3d%3d", a, b);
		}
		printf("\n");
		
	}

}
