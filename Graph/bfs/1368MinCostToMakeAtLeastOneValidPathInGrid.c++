#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> cost(m,(vector<int>(n,INT_MAX)));
        cost[0][0]=0;
        deque<pair<int,int>> dq;    //to avoid priority queue ,as there are only 2 option for cost either 0 or 1 //  --->{0,0,....,1,1,1}
        dq.push_front({0,0});       //cost->0 push_front ,otherwise cost->1 push_back
        while(!dq.empty()){
            int x=dq.front().first,y=dq.front().second;
            dq.pop_front(); //alway pop from front for minimum cost {0,0,....,1,1,1}
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(0<=nx && nx<m && 0<=ny && ny<n){
                    int newCost=cost[x][y]+(grid[x][y]!=i+1);
                    if(newCost<cost[nx][ny]){
                        cost[nx][ny]=newCost;
                        (grid[x][y]==i+1)?dq.push_front({nx,ny}):dq.push_back({nx,ny}); //if move is in the same direction then push it at front, and otherwise push it from back
                    }
                }
            }
        }
        return cost[m-1][n-1];
    }
};