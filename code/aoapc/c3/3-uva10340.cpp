#define LOCAL

#include <iostream>
#include <string>
using namespace std;

int main() {
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	string s, t;
	string::iterator p;
	//while(!cin.eof()) {
	//	cin >> s >> t;
	while(cin >> s) {
		cin >> t;
		p = s.begin();
		for(string::iterator it = t.begin(); it!= t.end(); it++) {
			if(p == s.end()) break;
			if(*it == *p) p++;
		}
		if(p == s.end()) cout << "Yes\n";
		else cout << "No\n";
	}
	
}

