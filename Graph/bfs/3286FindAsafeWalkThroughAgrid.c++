#include <bits/stdc++.h>
using namespace std;

bool findSafeWalk(vector<vector<int>>& grid, int health) {
    int r=grid.size(),c=grid[0].size();
    vector<vector<int>> points(r,vector<int>(c,INT_MIN));
    vector<pair<int,int>> dir={{1,0},{0,1},{0,-1},{-1,0}};
    set<pair<int,pair<int,int>>,greater<>> st;
    st.insert({health-grid[0][0],{0,0}});
    points[0][0]=health-grid[0][0];
    while(!st.empty()){
        auto t=*(st.begin());
        st.erase(t);
        int h=t.first,x=t.second.first,y=t.second.second;
        if(h<1 && x!=r-1 && y!=c-1) return 0;
        for(int d=0;d<4;d++){
            int nr=x+dir[d].first;
            int nc=y+dir[d].second;
            if(0<=nr &&nr<r && 0<=nc && nc<c && points[nr][nc]<h-grid[nr][nc]){
                if(st.find({points[nr][nc],{nr,nc}})!=st.end()) {
                    st.erase({points[nr][nc],{nr,nc}});
                }
                points[nr][nc]=h-grid[nr][nc];
                st.insert({h-grid[nr][nc],{nr,nc}});
                if(nr==r-1 && nc==c-1 && h-grid[nr][nc] >= 1 ) return 1;
            }
        }
    }
    return 0;
}