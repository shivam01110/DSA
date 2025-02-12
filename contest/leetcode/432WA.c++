#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int take=1;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(i%2==0){
                for(int j=0;j<m;j++){
                    if(take) res.push_back(grid[i][j]);
                    take=1-take;
                }
            }else{
                for(int j=m-1;j>=0;j--){
                    if(take) res.push_back(grid[i][j]);
                    take=1-take;
                }
            }
        }
        return res;
    }
};