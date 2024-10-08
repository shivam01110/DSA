#include <bits/stdc++.h>
using namespace std;

void dfs(int src,int dest,vector<vector<int>>& graph,vector<int>& path,vector<vector<int>>& ans){
    if(!path.empty() && path.back()==dest){
        ans.push_back(path);
    }
    for(auto neighbour:graph[src]){
        path.push_back(neighbour);
        dfs(neighbour,dest,graph,path,ans);
        path.pop_back();        //backtracking
    }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int> path;
    path.push_back(0);
    vector<vector<int>> ans;
    dfs(0,n-1,graph,path,ans);
    return ans;
}