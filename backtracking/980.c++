#include <bits/stdc++.h>
using namespace std;

int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};

int m=0;
int n=0;

int recurr(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& vis,int free){
    if(free==0 && grid[r][c]==2) return 1;
    vis[r][c]=1;
    free--;
    int ans=0;
    for(int i=0;i<4;i++){
        int nr=r+dr[i];
        int nc=c+dc[i];
        if(0<=nr && nr<m && 0<=nc && nc<n && vis[nr][nc]==0 && grid[nr][nc]!=-1){
            ans+=recurr(grid,nr,nc,vis,free);
        }
    }
    vis[r][c]=0;
    return ans;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    m=grid.size();
    n=grid[0].size();
    int free=0;
    int r=-1,c=-1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0) free++;
            if(grid[i][j]==1) {r=i;j=c;}
        }
    } 
    vector<vector<int>> vis(m,vector<int>(n,0)); 
    return recurr(grid,r,c,vis,free+1);
}