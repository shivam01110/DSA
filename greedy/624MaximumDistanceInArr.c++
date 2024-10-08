#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<vector<int>>& arrays) {
    int maxi=arrays[0].back();
    int mini=arrays[0].front();
    int res=INT_MIN;
    for(int i=1;i<arrays.size();i++){
        res=max(res,abs(arrays[i].back()-mini));
        res=max(res,abs(arrays[i].front()-maxi));
        maxi=max(maxi,arrays[i].back());
        mini=min(mini,arrays[i].front());
    }
    return res;
}