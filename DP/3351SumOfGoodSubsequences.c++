#include <bits/stdc++.h>
using namespace std;

const int MAX=1e5+1;
const int MOD=1e9+7;


class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(MAX,0);
        vector<int> sum(MAX,0);
        for(int i=0;i<n;i++){
            dp[nums[i]]=(dp[nums[i]]+1)%MOD;
            sum[nums[i]]=(sum[nums[i]]+nums[i])%MOD;
            if(nums[i]+1<=MAX){
                dp[nums[i]]=(dp[nums[i]]+dp[nums[i]+1])%MOD;
                sum[nums[i]]=(sum[nums[i]+1]+nums[i]*dp[nums[i]+1])%MOD;
            }
            if(nums[i]-1>=0){
                dp[nums[i]]=(dp[nums[i]]+dp[nums[i]-1])%MOD;
                sum[nums[i]]=(sum[nums[i]-1]+nums[i]*dp[nums[i]-1])%MOD;
            }
        }
        int res=0;
        for(int i=0;i<MAX;i++){
            res=(res+sum[i])%MOD;
        }
        return res;
    }
};