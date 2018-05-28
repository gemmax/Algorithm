#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
		int dp[n + 1];
		memset(dp, 0, sizeof(dp));
		return cs(n, dp);
    }
	int cs(int n, int dp[]) {
		if(n == 0)
			return dp[n] = 1;
		if(n < 0)
			return 0;
		if(dp[n] > 0)
			return dp[n];
		return dp[n] = cs(n - 1, dp) + cs(n - 2, dp); 
	}
};

int main(){
	Solution * s = new Solution();
	cout << s->climbStairs(3);
}
