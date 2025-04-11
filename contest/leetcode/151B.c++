#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<vector<int>>& dp,vector<int>& nums,int first,int ind){
        if(ind==nums.size()) return nums[first];
        if(ind==nums.size()-1) return max(nums[first],nums.back());
        if(dp[ind][first]!=-1) return dp[ind][first];
        int second=ind,third=ind+1;
        int res=INT_MAX;
        int ans1=max(nums[first],nums[second])+solve(dp,nums,third,ind+2);
        res=min(res,ans1);
        int ans2=max(nums[first],nums[third])+solve(dp,nums,second,ind+2);
        res=min(res,ans2);
        int ans3=max(nums[second],nums[third])+solve(dp,nums,first,ind+2);
        res=min(res,ans3);
        return dp[ind][first]=res;
    }
    int minCost(vector<int>& nums) {
        if(nums.size()==2) return max(nums[0],nums[1]);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(dp,nums,0,1);
    }
};