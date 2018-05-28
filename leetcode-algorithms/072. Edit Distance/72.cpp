#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
		int dp[word1.length() + 1][word2.length() + 1];
		memset(dp, -1, sizeof(int) * (1+word1.length()) * (1+word2.length()));
		
		for(int i = 0; i <= word1.length(); i++)
			dp[i][0] = i;
		for(int i = 0; i <= word2.length(); i++)
			dp[0][i] = i;
        return md(word1, word2, word1.length(), word2.length(), &dp[0][0]);
    }

	int md(string s1, string s2, int n, int m, int * dp) {
		if(*(dp + n * (s2.length()+1) + m) >= 0)
			return *(dp + n*(s2.length()+1) + m);

		if(s1.at(n - 1) == s2.at(m - 1)) {
			return *(dp + n*(s2.length()+1) + m) = md(s1, s2, n - 1, m - 1, dp);
		}

		return *(dp + n*(s2.length()+1) + m) = 1 + min(md(s1, s2, n-1, m, dp),md(s1, s2, n, m-1, dp),md(s1, s2, n-1, m-1, dp));
	}

	int min(int a, int b, int c){
		int min = a;
		min = (min > b) ? b : min;
		min = (min > c) ? c : min;
		return min;
	}
};

int main() {
	string a ="";
	string b = "";
	Solution * s = new Solution();
	cout << s->minDistance(a, b);
	return 0;
}
