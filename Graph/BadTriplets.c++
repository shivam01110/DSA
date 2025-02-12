#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(const vector<vector<int>>& adj, int N, const vector<tuple<int, int, int>>& forbidden, int start, int end) {
    set<tuple<int, int, int>> forbiddenSet(forbidden.begin(), forbidden.end());
    queue<tuple<int, int, vector<int>>> q;
    q.push({start, -1, {start}}); 
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    visited[start][0] = true;
    while (!q.empty()) {
        auto front = q.front();  
        int city = get<0>(front);  
        int prev = get<1>(front); 
        vector<int> path = get<2>(front);
        q.pop();
        if (city == end) {
            return path;
        }
        for (int neighbor : adj[city]) {
            if (prev != -1 && forbiddenSet.count({prev, city, neighbor})) {
                continue;
            }
            if (!visited[neighbor][city]) {
                visited[neighbor][city] = true;
                vector<int> newPath = path;
                newPath.push_back(neighbor);
                q.push({neighbor, city, newPath});
            }
        }
    }
    return {};
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> adj(N + 1);
    vector<tuple<int, int, int>> forbidden;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        forbidden.push_back({a, b, c});
    }
    vector<int> result = bfs(adj, N, forbidden, 1, N);
    if (result.empty()) {
        cout << -1 << endl;
    } else {
        cout << result.size() << endl;
        for (int city : result) {
            cout << city << " ";
        }
        cout << endl;
    }
    return 0;
}
