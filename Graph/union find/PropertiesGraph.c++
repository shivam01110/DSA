#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> rank, parent, size;

public:
    DSU(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    bool UnionByRank(int u, int v) {
        int Parent_u = findParent(u);
        int Parent_v = findParent(v);
        if (Parent_u == Parent_v) return false;  // Already in the same component
        if (rank[Parent_u] < rank[Parent_v]) {
            parent[Parent_u] = Parent_v;
        } else if (rank[Parent_u] > rank[Parent_v]) {
            parent[Parent_v] = Parent_u;
        } else {
            parent[Parent_v] = Parent_u;
            rank[Parent_u]++;
        }
        return true;
    }

    bool UnionBySize(int u, int v) {
        int Parent_u = findParent(u);
        int Parent_v = findParent(v);
        if (Parent_u == Parent_v) return false;  // Already in the same component
        if (size[Parent_u] < size[Parent_v]) {
            size[Parent_v] += size[Parent_u];
            parent[Parent_u] = Parent_v;
        } else {
            size[Parent_u] += size[Parent_v];
            parent[Parent_v] = Parent_u;
        }
        return true;
    }

    int countConnectedComponents(int n) {
        unordered_set<int> uniqueParents;
        for (int i = 0; i < n; i++) {
            uniqueParents.insert(findParent(i));
        }
        return uniqueParents.size();
    }
};

class Solution {
public:
    bool intersection(vector<int>& a,vector<int>& b,int m,int k){
        int cnt=0;
        for(int i=1;i<=100 && cnt<k ;i++){
            auto it1=binary_search(a.begin(),a.end(),i);
            auto it2=binary_search(b.begin(),b.end(),i);
            if(it1 && it2){
                cnt++;
            }
        }
        return cnt>=k;
    }
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n=properties.size();
        int m=properties[0].size();
        for(int i=0;i<n;i++){
            sort(properties[i].begin(),properties[i].end());
        }
        vector<vector<int>> edges;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(intersection(properties[i],properties[j],m,k)){
                    edges.push_back({i,j});
                }
            }
        }
        DSU dsu(n);
        for(auto e:edges){
            dsu.UnionByRank(e[0],e[1]);
        }
        int res=dsu.countConnectedComponents(n);
        return res;
    }
};

