#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        // u and v are adjacent vertices
        adj[u].push_back(v);    
        adj[v].push_back(u);
    }
    map<int,int> m;    // {deg-->number of vertices with deg} 
    int res=0;
    for(int v=1;v<n+1;v++){
        m[adj[v].size()]+=1;   //degree of vertex is the equal to its number of adjacent vertecies
    }
    for(int u=1;u<n+1;u++){
        m[adj[u].size()]--;
        if(m[adj[u].size()]==0) m.erase(adj[u].size());    //remove this {key,val} from m if val becomes 0
        for(auto v:adj[u]){
            res=max(res,(int)adj[v].size()+(int)adj[u].size()-2);   //for adjacent vertex
            m[adj[v].size()]--;
            if(m[adj[v].size()]==0) m.erase(adj[v].size());
        }
        if(m.size()!=0){
            res=max(res,m.rbegin()->first+(int)adj[u].size()-1);    //for non-adjacent vertex
        }
        m[adj[u].size()]++; //add degree which was removed earlier
        for(auto v:adj[u]){
            m[adj[v].size()]++; //add degree of adjcent vertex of u which was removed earlier
        }
    }
    cout<<res<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
