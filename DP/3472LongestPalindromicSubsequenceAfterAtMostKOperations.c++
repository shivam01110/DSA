#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int solve(int left,int right,int k,string& s,vector<vector<vector<int>>>& dp){
        if(left==right) return 1;
        if(left>right) return 0;
        if(dp[left][right][k]!=-1) return dp[left][right][k];
        int res=0;
        //do nothing,move left pointer
        res=max(res,solve(left+1,right,k,s,dp));
        //do nothing,move right pointer
        res=max(res,solve(left,right-1,k,s,dp));
        //make the s[left]==s[right] with min operation
        int ops=min(abs(s[left]-s[right]),26-abs(s[right]-s[left]));
        if(ops<=k) res=max(res,2+solve(left+1,right-1,k-ops,s,dp));
        return dp[left][right][k]=res;
    }
    int longestPalindromicSubsequence(string s,int k){
        string rev=s;
        reverse(rev.begin(),rev.end());
        int len=s.length();
        vector<vector<vector<int>>>dp(len+1,vector<vector<int>>(len+1,vector<int>(k+1,-1)));
        return solve(0,len-1,k,s,dp);
    }
};


