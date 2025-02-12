#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int recurr(int l,int r,int score,vector<int>& nums){
        if(l>=r) return 0;
        int maxi=0;
        if(nums[l]+nums[l+1]==score) maxi=max(maxi,1+recurr(l+2,r,score,nums));
        if(nums[l]+nums[r]==score) maxi=max(maxi,1+recurr(l+1,r-1,score,nums));
        if(nums[r-1]+nums[r]==score) maxi=max(maxi,1+recurr(l,r-2,score,nums));
        return maxi;
    }
    int memo(int l,int r,int score,vector<int>& nums,vector<vector<int>>& dp){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int maxi=0;
        if(nums[l]+nums[l+1]==score) maxi=max(maxi,1+memo(l+2,r,score,nums,dp));
        if(nums[l]+nums[r]==score) maxi=max(maxi,1+memo(l+1,r-1,score,nums,dp));
        if(nums[r-1]+nums[r]==score) maxi=max(maxi,1+memo(l,r-2,score,nums,dp));
        return dp[l][r]=maxi;
    }
    int maxOperations(vector<int>& nums) {
        int l=0,r=nums.size()-1;
        int score1=nums[0]+nums[1];
        int score2=nums[0]+nums[r];
        int score3=nums[r-1]+nums[r];
        vector<vector<int>> dp(r+1,vector<int>(r+1,-1));
        int res=0;
        res=max(res,memo(2,r,score1,nums,dp)+1);
        res=max(res,memo(1,r-1,score2,nums,dp)+1);
        res=max(res,memo(l,r-2,score3,nums,dp)+1);
        return res;
    }
};