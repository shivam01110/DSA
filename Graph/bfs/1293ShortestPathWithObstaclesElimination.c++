#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();  
        int m=grid[0].size();  
        int dr[4][4]={{0,1},{-1,0},{0,-1},{1,0}};
        vector<vector<int>> remains(n,vector<int>(m,-1));   // To store max remaining obstacles that can be removed
        queue<array<int,3>> q;//{x,y,remaining number of obstacles}
        q.push({0,0,k});    // at the beginning, we can eliminate at most k obstacles
        grid[0][0]=k; 
        int step=0;
        while(!q.empty()){
            int l=q.size();
            for(int i=0;i<l;i++){
                auto f=q.front();
                q.pop();
                int x=f[0],y=f[1],remain=f[2];
                if(x==n-1 && y==m-1) return step;
                for(int j=0;j<4;j++){
                    int nx=x+dr[j][0];
                    int ny=y+dr[j][1];
                    if(0<=nx && nx<n && 0<=ny && ny<m){
                        int nextRemain=remain-grid[nx][ny];
                        // we can only do that when `nextRemain` is greater or equal to 0
                        // and the target remaining k must be less than the current remaining k
                        if(nextRemain>=0 && remains[nx][ny]<nextRemain){
                            q.push({nx,ny,nextRemain});
                            remains[nx][ny]=nextRemain; // update the remaining k
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }
};