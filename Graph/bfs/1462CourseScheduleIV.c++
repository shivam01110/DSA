#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& adjList,int src,vector<vector<int>>& adjMatrix){
        queue<int> q;
        vector<bool> visited(adjList.size(), false);
        q.push(src);
        visited[src] = true;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int neighbour : adjList[f]) {
                if (!visited[neighbour]) {
                    adjMatrix[src][neighbour] = 1;
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }      
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(numCourses);
        vector<vector<int>> adjMatrix(numCourses,vector<int>(numCourses,0));
        for(auto p:prerequisites){
            adjList[p[0]].push_back(p[1]);
            adjMatrix[p[0]][p[1]]=1;
            adjMatrix[p[0]][p[0]]=1;
        }
        for(int i=0;i<numCourses;i++){
            bfs(adjList,i,adjMatrix);
        }
        int n=queries.size();
        vector<bool> res(n,0);
        for(int i=0;i<n;i++){
            res[i]=adjMatrix[queries[i][0]][queries[i][1]];
        }
        return res;
    }
};