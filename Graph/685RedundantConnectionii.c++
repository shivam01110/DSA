#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool bfs(int n,int root,vector<vector<int>>& adj){
        vector<int> vis(n+1,0);
        vis[root]=1;
        queue<int> q;
        q.push(root);
        while(!q.empty()){
            int s=q.size();
            for(int i=0;i<s;i++){
                int f=q.front();
                q.pop();
                for(auto neighbour:adj[f]){
                    if(vis[neighbour]==1) return false;
                    vis[neighbour]=1;
                    q.push(neighbour);
                }
            }
        }
        for(int i=1;i<n+1;i++){
            if(vis[i]==0) return false;
        }
        return true;
    }
    bool IsRooted(vector<int>& indegree,vector<int>& outdegree,int ind,vector<vector<int>>& edges,int n){
        int root=0;
        indegree[edges[ind][1]]--;
        outdegree[edges[ind][0]]--;
        for(int i=1;i<n+1;i++){
            if(indegree[i]==0){
                if(root!=0 || outdegree[i]==0){    //we have already found a root
                    indegree[edges[ind][1]]++;
                    outdegree[edges[ind][0]]++;
                    return false;
                }
                root=i;
            }
        }
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            if(i!=ind){
                adj[edges[i][0]].push_back(edges[i][1]);
            }
        }
        if(bfs(n,root,adj)==false){
            indegree[edges[ind][1]]++;
            outdegree[edges[ind][0]]++;
            return false;
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0);
        for(auto e:edges){
            indegree[e[1]]++;
            outdegree[e[0]]++;
        }
        for(int i=n-1;i>=0;i--){
            if(IsRooted(indegree,outdegree,i,edges,n)) return edges[i];
        }
        return {};
    }
};