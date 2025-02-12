#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n,m1,m2;
    cin>>n>>m1>>m2;
    set<pair<int,int>> s;
    int u,v;
    for(int i=0;i<m1;i++){
        u=min(u,v);
        v=max(u,v);
        s.insert(make_pair(u,v));
    }
    int intersection=0;
    for(int i=0;i<m1;i++){
        u=min(u,v);
        v=max(u,v);
        if(s.count({u,v})) intersection++;
    }
    

}