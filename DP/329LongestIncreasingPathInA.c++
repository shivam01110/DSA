#include <bits/stdc++.h>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int dfs(int x,int y,vector<vector<int>>& grid,vector<vector<int>>& lip,int n,int m){
    if(lip[x][y]) return lip[x][y];
    int maxi=1;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(0<=nx && nx<n && 0<=ny && ny<m && grid[nx][ny]>grid[x][y]){
            maxi=max(maxi,1+dfs(nx,ny,grid,lip,n,m));
        }
    }    
    return lip[x][y]=maxi;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int n=matrix.size(),m=matrix[0].size();
    vector<vector<int>> lip(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(lip[i][j]==0) dfs(i,j,matrix,lip,n,m);
        }
    }
    int res=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            res=max(res,lip[i][j]);
        }
    }
    return res;
}

int main(){
    vector<vector<int>> matrix={{9,9,4},{6,6,8},{2,1,1}};
    cout<<longestIncreasingPath(matrix);
    return 0;
}