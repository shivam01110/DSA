#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        int s=edges.size();
        vector<int> adj[n];
        vector<int> indegree(n,0);
        for(int i=0;i<s;i++){
            //from->to
            adj[edges[i][0]].push_back(edges[i][1]);
            indegree[edges[i][1]]++;
        }
        vector<set<int>> ancestor(n);
        vector<int> visited(n,0);
        int vis=0;
        while(vis!=n){
            for(int i=0;i<n;i++){
                if(indegree[i]==0 && visited[i]==0){
                    visited[i]=1;
                    vis++;
                    for(auto ch:adj[i]){
                        ancestor[ch].insert(i);
                        for(auto p:ancestor[i]){
                            ancestor[ch].insert(p);
                        }
                        indegree[ch]--;
                    }
                }
            }
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            for(auto ele:ancestor[i]){
                ans[i].push_back(ele);
            }
        }
        return ans;
    }
};