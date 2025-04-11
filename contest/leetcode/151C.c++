#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int countArrays(vector<int>& original, vector<vector<int>>& bounds) {
        int n = original.size(),ind=0;
        ll l = bounds[ind][0], h = bounds[ind][1]; 
        ind++;
        while(ind<n){
            ll diff = original[ind] - original[ind - 1];
            l = max((ll)bounds[ind][0],(ll)(l + diff));
            h = min((ll)bounds[ind][1], (ll)(h + diff));
            if (l > h) return 0;  
            ind++;
        }        
        return  h-l+1;  
    }
};
