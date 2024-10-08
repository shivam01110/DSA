#include <bits/stdc++.h>
using namespace std;

int help(int i,int n,int m,vector<int>& vis,vector<vector<int>>& grid,unordered_map<string,int>& dp){
    if(i>=n) return 0;
    string key=to_string(i)+"-";
    for(auto v:vis) key+=to_string(v);
    if(dp.find(key)!=dp.end()) return dp[key];
    int res=INT_MIN;
    for(int j=0;j<m;j++){
        bool visrow=false;
        if(vis[grid[i][j]]==0){
            visrow=true;
            vis[grid[i][j]]=1;
            res=max(res,grid[i][j]+help(i+1,n,m,vis,grid,dp));
            vis[grid[i][j]]=0;
        }
        if(visrow==false) res=max(res,help(i+1,n,m,vis,grid,dp));
    }
    return dp[key] = res;
}
int maxScore(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size();
    vector<int> vis(101,0);
    vector<int> dp(n);
    unordered_map<string,int> dp;
    for(int i=0;i<n;i++){
        sort(grid[i].begin(),grid[i].end());
    }
    return help(0,n,m,vis,grid,dp);
}