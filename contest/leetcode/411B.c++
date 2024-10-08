#include <bits/stdc++.h>
using namespace std;

long long energy(vector<int>& a,vector<int>& b,int i,int curr,vector<vector<long long>>& dp){
    if(i>=a.size()) return 0;
    if(dp[i][curr]!=-1) return dp[i][curr];
    long long ans=0;
    if(curr){
        ans=max(ans,b[i]+energy(a,b,i+2,!curr,dp));
        ans=max(ans,b[i]+energy(a,b,i+1,curr,dp));
    }
    else{
        ans=max(ans,a[i]+energy(a,b,i+2,!curr,dp));
        ans=max(ans,a[i]+energy(a,b,i+1,curr,dp));
    }
    return dp[i][curr] = ans;
}