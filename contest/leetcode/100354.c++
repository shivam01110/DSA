#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, vector<int> adj[], vector<int>& subtree_size) {
    int size = 1; // The subtree size includes the node itself
    for (int child : adj[node]) {
        if (child != parent) { // Skip the parent to avoid going back up the tree
            size += dfs(child, node, adj, subtree_size);
        }
    }
    subtree_size[node] = size;
    return size;
}

int countGoodNodes(vector<vector<int>>& edges) {
    int n=edges.size();
    vector<int> adj[n+1];
    for(int i=0;i<n;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> subtreeSize(n+1,0);
    dfs(0,-1,adj,subtreeSize);
    int cnt=0;

    //bfs
    queue<int> q;
    q.push(0);
    vector<int> vis(n+1,0);
    while(!q.empty()){
        int s=q.size();
        for(int i=0;i<s;i++){
            set<int> st;
            int p=q.front();
            q.pop();
            vis[p]=1;
            for(auto c:adj[p]){
                if(vis[c]==0){
                    q.push(c);
                    st.insert(subtreeSize[c]);
                }
            }
            if(st.size()<=1) cnt++; //all the child of current node have the same size
        }
    }
    return cnt;
}

int main(){
    vector<vector<int>> edges={{0,1},{1,2},{1,3},{1,4},{0,5},{5,6},{6,7},{7,8},{0,9},{9,10},{9,12},{10,11}};
    cout<<countGoodNodes(edges);
    return 0;
}