#include <bits/stdc++.h>
using namespace std;

long long maxPoints(vector<vector<int>>& points) {
    int n=points.size();
    int m=points[0].size();
    vector<long long> prev(m,0),left(m,0),right(m,0);
    long long res=LLONG_MIN;
    for(int i=0;i<m;i++){
        prev[i]=points[0][i];
        res=max(res,prev[i]);
    }
    for(int r=1;r<n;r++){
        left[0]=prev[0];
        right[m-1]=prev[m-1];
        for(int c=1;c<m;c++){
            left[c]=max(left[c-1]-1,prev[c]);
            right[m-1-c]=max(right[m-c]-1,prev[m-1-c]);
        }
        for(int c=0;c<m;c++){
            prev[c]=points[r][c]+max(left[c],right[c]);
            left[c]=0;
            right[c]=0;
            res=max(res,prev[c]);
        }
    }
    return res;
}