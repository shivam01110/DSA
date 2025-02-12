#include <bits/stdc++.h>
using namespace std;

class DSU{
    vector<int> rank,parent,size;
    public:
    DSU(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int findParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findParent(parent[node]);
    }
    bool UnionByRank(int u,int v){
        int Parent_u=findParent(u);
        int Parent_v=findParent(v);
        if(Parent_u==Parent_v) return false;    //already in same component
        if(rank[Parent_u]<rank[Parent_v]){
            parent[Parent_u]=Parent_v;
        }
        else if(rank[Parent_u]>rank[Parent_v]){
            parent[Parent_v]=Parent_u;
        }
        else{
            parent[Parent_v]=Parent_u;
            rank[Parent_u]++;
        }
        return true;
    }
    bool UnionBySize(int u,int v){
        int Parent_u=findParent(u);
        int Parent_v=findParent(v);
        if(Parent_u==Parent_v) return false;    //already in same component
        if(size[Parent_u]<size[Parent_v]){
            size[Parent_v]+=size[Parent_u];
            parent[Parent_u]=Parent_v;
        }
        else{
            size[Parent_u]+=size[Parent_v];
            parent[Parent_v]=Parent_u;
        }
        return true;
    }
    
};

class Solution{
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            if(!dsu.UnionByRank(edges[i][0],edges[i][1])){
                return edges[i];
            }
        }
        return {};
    }
};