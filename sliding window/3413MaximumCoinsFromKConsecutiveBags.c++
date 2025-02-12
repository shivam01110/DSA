#include <bits/stdc++.h>
using namespace std;

#define ll long long

class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(),coins.end());
        int n=coins.size();
        ll tot=0;
        ll res=LLONG_MIN;
        //taking coins[i][0] as the start of the interval
        for(int i=0,j=0;i<n;i++){
            while(j<n && coins[j][1]<=coins[i][0]+k-1){
                tot+=(ll)(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }
            ll partial=0ll;
            if(j<n){
                partial=max(partial,(ll)(coins[i][0]+k-coins[j][0])*coins[j][2]);
            }
            res=max(res,tot+partial);
            tot-=(ll)(coins[i][1]-coins[i][0]+1)*coins[i][2]; 
        }
        //taking coins[i][1] as the end of the interval
        ll total=0;
        for(int i=0,j=0;i<n;i++){
            total+=(ll)(coins[i][1]-coins[i][0]+1)*coins[i][2];
            while(coins[j][1]<coins[i][1]-k+1){
                total-=(ll)(coins[j][1]-coins[j][0]+1)*coins[j][2];
                j++;
            }
            ll partial=max(partial,(ll)(coins[i][1]-k+1-coins[j][0])*coins[j][2]);
            res=max(res,total-partial);
        }
        return res;
    }
};