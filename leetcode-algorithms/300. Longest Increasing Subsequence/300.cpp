#include<vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       	if(nums.empty())
			return 0;
		int N = nums.size();
		int dp[nums.size()];
		memset(dp, 0, sizeof(dp));	
        int max = 1; // {0}时，直接等于此处值 
        for(int i = 0; i < N; i++)
            _lis(nums, i, &max, dp);
        return max;
    }

    int _lis(vector<int>& arr, int i, int * globalMax, int dp[]){
        int max = 1, tmp = 1;
        if(dp[i] != 0)
            return dp[i];
        
		if(i == 0)
			return dp[i] = 1;
        
		//int t;
		for(int j = 0; j < i; j++){
            tmp = _lis(arr, j, globalMax, dp);
			if(arr[i] > arr[j] && tmp+1 > max){ //条件 s
                max = tmp+1;
            } // e
			/*if(tmp >= max){
				max = tmp;
				t = j;	
			}*/
        }
		//if(arr[i] > arr[t]) max++;

        if(*globalMax < max)
            *globalMax = max;
		
        return dp[i] = max;
    }
};

int main(int argc, char *argv[]){
    int a[] = {10, 9, 2, 5, 3, 7, 101, 18};
    
    vector<int> arr(a, a + sizeof(a) / sizeof(int));
    Solution * s = new Solution();
    cout << s->lengthOfLIS(arr);
    return 0;
}

