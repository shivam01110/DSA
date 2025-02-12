#include <bits/stdc++.h>
using namespace std;

int dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& batchNodes) {
    int totalPackages = 0;
    if(batchNodes[node]) totalPackages = 1;  // If the node has a batch, count it
    
    int maxPackageInSubtree = 0; // To track the max packages that can be collected from child nodes
    
    for (int i = 0; i < adj[node].size(); i++) {
        int neighbor = adj[node][i];
        if (neighbor != parent) { // Avoid revisiting the parent
            int packagesInSubtree = dfs(neighbor, node, adj, batchNodes);
            maxPackageInSubtree = max(maxPackageInSubtree, packagesInSubtree); // Choose the best path
        }
    }
    
    return totalPackages + maxPackageInSubtree; 
}

int main() {
    int N, R;
    cin >> N >> R;
    
    vector<int> batchUnits(R);
    vector<int> batchNodes(N + 1, 0); // Initialize for all N units, 1-based index
    
    // Read batch nodes and mark them in batchNodes
    for (int i = 0; i < R; i++) {
        cin >> batchUnits[i];
        batchNodes[batchUnits[i]] = 1; // Mark the batch nodes
    }
    
    vector<vector<int>> adj(N + 1);
    
    // Read the tree edges
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int maxBatches = 0;
    
    // Perform DFS starting from each batch node to find the maximum batches we can pick in a valid path
    for (int i = 0; i < R; i++) {
        int start = batchUnits[i];
        maxBatches = max(maxBatches, dfs(start, -1, adj, batchNodes)); // Start DFS from the batch node
    }
    
    cout << maxBatches << endl;
    return 0;
}








// 8 4
// 2 3 5 6
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 3 7
// 6 8

// 4 3
// 2 3 4
// 1 2
// 1 3
// 1 4