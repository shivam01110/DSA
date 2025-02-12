#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        vector<int> c(1e9,0);
        for(int i=0;i<coins.size();i++){
            for(int i=coins[i][0]-1;i<coins[i][1];i++){
                c[i]=coins[i][2];
            }
        }
        long long res=0,l=0;
        for(int i=0;i<coins.size();i++){
            res+=c[i];
            if()
        }
    }
};