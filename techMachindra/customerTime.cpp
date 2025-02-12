#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int to, time;
    Edge(int to, int time) : to(to), time(time) {}
};

vector<int> dijkstra(int s, int n, vector<vector<Edge>>& g) {
    vector<int> d(n + 1, INT_MAX);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        auto cur = pq.top();
        pq.pop();
        int v = cur.second, dist = cur.first;
        if (dist > d[v]) continue;
        for (const Edge& e : g[v]) {
            int newDist = dist + e.time;
            if (newDist < d[e.to]) {
                d[e.to] = newDist;
                pq.push({newDist, e.to});
            }
        }
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;
    int constX;
    cin >> constX; // Reading the constant value which is 3
    vector<vector<Edge>> g(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(Edge(b, c));
        g[b].push_back(Edge(a, c));
    }
    
    int q, constY;
    cin >> q >> constY; // Reading the constant value which is 2
    
    vector<int> z(q), t(q);
    for (int i = 0; i < q; i++) {
        cin >> z[i] >> t[i];
    }
    
    vector<int> d = dijkstra(1, n, g);
    
    for (int i = 0; i < q; i++) {
        int x = z[i], k = t[i];
        int time = d[x];
        if (time * 2 <= k) cout << k - time * 2 << " ";
        else cout << "0 ";
    }
    
    return 0;
}
 