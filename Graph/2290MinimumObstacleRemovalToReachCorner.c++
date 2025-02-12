#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[4][4]={{0,1},{-1,0},{0,-1},{1,0}};
        vector<vector<int>> cost(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq; //{cost,{x,y}}
        pq.push({0,{0,0}});
        cost[0][0]=0;
        while(!pq.empty()){
            int c=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nx=x+dr[i][0];
                int ny=y+dr[i][1];
                if(0<=nx && nx<n && 0<=ny && ny<m && c+grid[nx][ny]<cost[nx][ny]){
                    cost[nx][ny]=c+grid[nx][ny];
                    pq.push({cost[nx][ny],{nx,ny}});
                }
            }
        }
        return cost[n-1][m-1];
    }
};