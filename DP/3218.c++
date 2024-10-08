#include <bits/stdc++.h>
using namespace std;

int recur(int r1,int r2,int c1,int c2,vector<int>& row,vector<int>& col){
    if(r2-r1==1 && c2-c1==1) return 0;
    int cost=INT_MAX;
    for(int i=r1+1;i<r2;i++){
        cost=min(cost,row[i-1]+recur(r1,i,c1,c2,row,col)+recur(i,r2,c1,c2,row,col));
    }
    for(int j=c1+1;j<c2;j++){
        cost=min(cost,col[j-1]+recur(r1,r2,c1,j,row,col)+recur(r1,r2,j,c2,row,col));
    }
    return cost;
}

int memo(int r1,int r2,int c1,int c2,vector<int>& row,vector<int>& col,vector<vector<vector<vector<int>>>>& dp){
    if(r2-r1==1 && c2-c1==1) return 0;
    if(dp[r1][r2][c1][c2]!=-1) return dp[r1][r2][c1][c2];
    int cost=INT_MAX;
    for(int i=r1+1;i<r2;i++){
        cost=min(cost,row[i-1]+memo(r1,i,c1,c2,row,col,dp)+memo(i,r2,c1,c2,row,col,dp));
    }
    for(int j=c1+1;j<c2;j++){
        cost=min(cost,col[j-1]+memo(r1,r2,c1,j,row,col,dp)+memo(r1,r2,j,c2,row,col,dp));
    }
    return dp[r1][r2][c1][c2]=cost;
}


int main(){
    int m=1,n=7;
    vector<int> row={};
    vector<int> col={2,1,2,1,2,1};
    vector<vector<vector<vector<int>>>> dp(m+1,vector<vector<vector<int>>>(m+1,vector<vector<int>>(n+1,vector<int>(n+1,-1))));
    cout<<memo(0,m,0,n,row,col,dp)<<endl;
    return 0;
}