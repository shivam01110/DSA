#include <bits/stdc++.h>
using namespace std;


bool touch(vector<int> b1,vector<int> b2){
    float distC2C=pow(pow((b1[0]-b2[0]),2)+pow((b1[1]-b2[1]),2),0.5);
    if(distC2C<=b1[2]) return 1;
    return 0;
}
int dfs(vector<vector<int>>& adj,vector<int>& vis,int curr){
    vis[curr]=1;
    int count=1;
    for(int neighbour:adj[curr]){
        if(vis[neighbour]==0){
            count+=dfs(adj,vis,neighbour);
        }
    }
    return count;
}
int maximumDetonation(vector<vector<int>>& bombs) {
    int n=bombs.size();
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(touch(bombs[i],bombs[j]) && j!=i){
                adj[i].push_back(j);
            }
        }
    }   
    int maxi=0;
    for(int i=0;i<n;i++){
        vector<int> vis(n,0);
        maxi=max(maxi,dfs(adj,vis,i));
    }
    return maxi;
}