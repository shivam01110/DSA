#include <bits/stdc++.h>
using namespace std;

int recurr(int ind,vector<int>& nums,vector<int> arr1,vector<int> arr2){
    if(ind==nums.size()) return 1;
    int pair=0;
    for(int curr=arr1[max(0,ind-1)];curr<=nums[ind];curr++){
        arr1[ind]=curr;
        arr2[ind]=nums[ind]-curr;
        if(arr1[ind]>=arr1[max(0,ind-1)] && arr2[ind]<=arr2[max(0,ind-1)]){
            pair+=recurr(ind+1,nums,arr1,arr2);
        }
    }
    return pair;
}

int memo(int ind,vector<int>& nums,int prev,vector<vector<int>>& dp){
    if(ind==nums.size()) return 1;
    if(dp[ind][prev]!=-1) return dp[ind][prev];
    int pair=0;
    for(int curr=prev;curr<=nums[ind];curr++){
        if(curr>=prev && nums[max(0,ind-1)]-prev >=nums[ind]-curr){
            pair+=memo(ind+1,nums,curr,dp);
        }
    }
    return dp[ind][prev]= pair;
}

int countOfPairs(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n,vector<int>(51,-1));
    return memo(0,nums,0,dp);
}