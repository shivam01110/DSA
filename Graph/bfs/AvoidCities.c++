#include <bits/stdc++.h>
using namespace std;

int findShortestPath(int N, int M, int src, int target, vector<int>& cursed, vector<pair<int, int>>& edges) {
    if (cursed[src] == 1 || cursed[target] == 1) return -1;
    vector<vector<int>> adj(N + 1);
    for (auto& edge : edges) {
        int u = edge.first, v = edge.second;
        if (cursed[u] == 0 && cursed[v] == 0) { 
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    vector<bool> visited(N + 1, false);
    queue<pair<int, int>> q;
    q.push({src, 0});
    visited[src] = true;
    while (!q.empty()) {
        int city = q.front().first;
        int dist = q.front().second;
        q.pop();
        if (city == target) return dist;
        for (int neighbor : adj[city]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push({neighbor, dist + 1});
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    cin >> N >> M;
    int src, target;
    cin >> src >> target;
    vector<int> cursed(N);
    for (int i = 0; i < N; i++) {
        cin >> cursed[i];
    }
    vector<pair<int, int>> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].first >> edges[i].second;
    }
    cout << findShortestPath(N, M, src, target, cursed, edges) << endl;
    return 0;
}
