#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mini=-20000001;
    int len;
    int prefix[2001];
    int dp[2001][2001][2];
    int solve(vector<int>& nums,int m,int k,int ind,int extend){
        if(ind>=len) return k==0?0:mini;
        int rem=len-ind;
        if((rem/m)<k) return mini;
        if(dp[ind][k][extend]!=mini) return dp[ind][k][extend];
        int res=mini;
        //skip current index
        res=max(res,solve(nums,m,k,ind+1,0));
        if(extend==0){
            if(k==0) return 0;
            //start new subarray
            int include=prefix[ind+m-1]-((ind>0)?prefix[ind-1]:0);
            res=max(res,include+solve(nums,m,k-1,ind+m,1));
        }
        else{
            //include the current index and extend further the current subarray
            res=max(res,nums[ind]+solve(nums,m,k,ind+1,1));
            //stay on the same index and decide whether to skip or do a new start
            res=max(res,solve(nums,m,k,ind,0));
        }
        return dp[ind][k][extend]=res;
    }
    int maxSum(vector<int>& nums, int k, int m) {
        len=nums.size();
        for(int i=0;i<len;i++){
            prefix[i]=nums[i];
            if(i) prefix[i]+=prefix[i-1];
        }
        fill(&dp[0][0][0],&dp[0][0][0]+2001*2001*2,mini);
        return solve(nums,m,k,0,0);
    }
};