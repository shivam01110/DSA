#include <bits/stdc++.h>
using namespace std;

void dfs(int curr,vector<vector<int>>& adj,unordered_map<int,int>&m){
    m[curr]=1;
    for(int neigh:adj[curr]){
        if(m[neigh]==0) dfs(neigh,adj,m);
    }
}

vector<int> remainingMethods(int n, int k, vector<vector<int>>& edge) {
    sort(edge.begin(),edge.end());
    vector<vector<int>>adj(n);
    unordered_map<int,int> m;
    for(int i=0;i<edge.size();i++){
        adj[edge[i][0]].push_back(edge[i][1]);
    }
    dfs(k,adj,m);
    bool safe=true;
    for(int i=0;i<edge.size();i++){
        int u=edge[i][0],v=edge[i][1];
        if(m[u]==0 && m[v]==1){
            safe=false;
            break;
        }
    }
    vector<int> res;
    for(int i=0;i<n;i++){
        if(safe && m[i]==0){res.push_back(i);}
        if(!safe) res.push_back(i);
    }
    return res;
}