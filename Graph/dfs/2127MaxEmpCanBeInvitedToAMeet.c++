#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate the length of a cycle starting from a given node
    int lenCycle(int node, vector<vector<int>>& adjList, vector<int>& visited) {
        if (visited[node]) return 0; // If already visited, cycle is complete
        visited[node] = 1; // Mark node as visited
        return 1 + lenCycle(adjList[node][0], adjList, visited); // Recursively traverse cycle
    }
    
    int maximumInvitations(vector<int>& favorite) {
        int n = favorite.size();
        vector<vector<int>> adjList(n); // Adjacency list representation of the graph
        vector<int> indeg(n, 0); // Stores in-degrees of nodes
        vector<int> visited(n, 0); // Tracks visited nodes
        vector<int> depth(n, 1); // Stores depth of nodes in tree-like structures
        queue<int> q; // Queue for topological sorting

        // Construct the adjacency list and in-degree count
        for (int i = 0; i < n; i++) {
            adjList[i].push_back(favorite[i]); // Each node points to its favorite
            indeg[favorite[i]] += 1; // Increment in-degree of the favorite node
        }

        // Push all nodes with zero in-degree into the queue
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        // Topological sorting to compute depth of tree-like components
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            visited[curr] = 1; // Mark node as visited
            int next = favorite[curr]; // The node it points to
            depth[next] = max(depth[next], depth[curr] + 1); // Update depth
            if (--indeg[next] == 0) q.push(next); // If in-degree becomes zero, push to queue
        }

        int res = 0, lenof2 = 0; // Variables to store the longest cycle and sum of length-2 cycles
        
        // Traverse nodes to find cycles
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) { // If not visited, it's part of a cycle
                int lenCyc = lenCycle(i, adjList, visited); // Find cycle length
                if (lenCyc == 2) { // If cycle length is 2 (special case)
                    lenof2 += depth[i] + depth[favorite[i]]; // Sum up depths of both nodes
                    lenCyc = lenof2; // Update length
                }
                res = max(res, lenCyc); // Store the maximum result
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> favorite = {1, 0, 0, 2, 1, 4, 7, 8, 9, 6, 7, 10, 8};
    cout << s.maximumInvitations(favorite) << endl; // Output the maximum invitations
    return 0;
}
