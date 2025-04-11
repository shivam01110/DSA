#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        vector<pair<int,int>> e;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                e.push_back(make_pair(grid[i][j],i));
            }
        }
        sort(e.rbegin(),e.rend());
        long long sum=0;
        for(int i=0;i<e.size() && k>0;i++){
            if(limits[e[i].second]>0){
                sum+=e[i].first;
                k--;
                limits[e[i].second]-=1;
            }
        }
        return sum;
    }
};