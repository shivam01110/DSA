#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int mini=INT_MAX;
        int n=cost.size();
        vector<int> res(n,INT_MAX);
        for(int i=0;i<n;i++){
            mini=min(mini,cost[i]);
            res[i]=mini;
        }
        return res;
    }
};