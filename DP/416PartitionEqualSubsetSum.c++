#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i,int& req,int sum,vector<int>& nums,int& len,vector<vector<int>>& dp){
        if(sum==req) return true;
        if(i>=len) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool ans=solve(i+1,req,sum,nums,len,dp);
        if(sum+nums[i]<=req) ans=ans|solve(i+1,req,sum+nums[i],nums,len,dp);
        return dp[i][sum]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int len=nums.size();
        int tot=0;
        for(int n:nums){
            tot+=n;
        }
        if(tot%2) return false;
        int req=tot/2;
        vector<vector<int>> dp(len+1,vector<int>(req+1,-1));
        bool res=solve(0,req,0,nums,len,dp);
        return res;
    }
};