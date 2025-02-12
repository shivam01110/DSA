#include <bits/stdc++.h>
using namespace std;

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    int s=intervals[1][0],e=intervals[1][1];
    set<int> grp;
    for(int i=0;i<n;i++){
        int l=intervals[i][0],r=intervals[i][1];
        if((s<=l && l<=e) || (l<=s && s<=r) && (min(r,e)-max(s,l)>0)){
            s=max(s,l);
            e=min(e,r);
        }
        else{
            grp.insert(s);
            grp.insert(e);
            s=l,e=r;
        }
    }
    grp.insert(s);
    grp.insert(e);
    return grp.size();
}