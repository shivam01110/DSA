#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int NodesAtDistancek(vector<vector<int>>& adj,int u,int k,int n){
        vector<int> vis(n,0);
        queue<int> q;
        q.push(u);
        vis[u]=1;
        int cnt=1;
        while(k>0 && !q.empty()){
            int l=q.size();
            for(int i=0;i<l;i++){
                int f=q.front();
                q.pop();
                for(int neigh:adj[f]){
                    if(vis[neigh]==0){
                        q.push(neigh);
                        vis[neigh]=1;
                        cnt++;
                    }
                }
            }
            k--;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size(),m=edges2.size();
        vector<vector<int>> adj1(n);
        for(auto v:edges1){
            adj1[v[0]].push_back(v[1]);
            adj1[v[1]].push_back(v[0]);
        }
        vector<vector<int>> adj2(n);
        for(auto v:edges2){
            adj2[v[0]].push_back(v[1]);
            adj2[v[1]].push_back(v[0]);
        }
        int maxi=INT_MIN;
        if(k>1){
            for(int i=0;i<m;i++){
                maxi=max(maxi,NodesAtDistancek(adj2,i,k-1,m));
            }
        }
        else maxi=k;
        vector<int> TargetNode(n,0);
        for(int i=0;i<m;i++){
            TargetNode[i]=NodesAtDistancek(adj1,i,k,n)+maxi;
        }
        return TargetNode;
    }
};