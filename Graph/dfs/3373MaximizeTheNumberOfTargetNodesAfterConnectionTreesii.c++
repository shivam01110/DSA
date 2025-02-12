#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<int>>& adj, int node, int parent, vector<int>& odd, vector<int>& even) {
        even[node] = 1; // Initialize even count for this node
        for (auto child : adj[node]) { // Iterate over children of the current node
            if (child != parent) { // Avoid revisiting the parent
                dfs(adj, child, node, odd, even);
                even[node] += odd[child];
                odd[node] += even[child];
            }
        }
    }
    void dfs2(vector<vector<int>>& adj, int node, int parent, vector<int>& odd, vector<int>& even) {
        for (auto child : adj[node]) { // Iterate over children of the current node
            if (child != parent) { // Avoid revisiting the parent
                odd[child] = even[node]; // Propagate even and odd counts to children
                even[child] = odd[node];
                dfs2(adj, child, node, odd, even);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1; // Number of nodes in graph 1
        int m = edges2.size() + 1; // Number of nodes in graph 2
        // Build adjacency list for both graphs
        vector<vector<int>> adj1(n);
        for (auto& edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> adj2(m);
        for (auto& edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        // Initialize odd and even vectors
        vector<int> odd1(n, 0), even1(n, 0);
        vector<int> odd2(m, 0), even2(m, 0);
        // Perform DFS and calculations
        dfs(adj1, 0, -1, odd1, even1);
        dfs2(adj1, 0, -1, odd1, even1);
        dfs(adj2, 0, -1, odd2, even2);
        dfs2(adj2, 0, -1, odd2, even2);
        // Calculate target nodes
        vector<int> TargetNode(n, 0);
        for (int i = 0; i < n; i++) {
            TargetNode[i] = max(even1[i] + odd2[0], even1[i] + even2[0]);
        }
        return TargetNode;
    }
};
