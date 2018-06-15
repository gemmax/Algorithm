#define LOCAL

#include <iostream>
#include <algorithm>
using namespace std;

const int N = 6;
struct Rec{int w, h;} r[N];

bool cmp(Rec a, Rec b) {
	return a.w<b.w || (a.w==b.w && a.h<b.h);
}
int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	bool isTrue;

	while(cin >> r[0].w >> r[0].h) {
		isTrue = true;

		for(int i = 1; i < N; i++)
			cin >> r[i].w >> r[i].h;
		for(int i = 0; i < N; i++)
			if(r[i].w > r[i].h) swap(r[i].w, r[i].h);
		sort(r, r+N, cmp);

		for(int i = 0; i < N; i+=2) {
			if(r[i].w != r[i+1].w || r[i].h != r[i+1].h) isTrue = false; 
		}
		if(r[0].w != r[2].w || r[0].h != r[4].w || r[2].h != r[4].h) isTrue = false;
		if(isTrue) cout << "POSSIBLE" << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
}
