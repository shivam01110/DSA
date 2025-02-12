#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> optShuffling(long long n, vector<vector<long long>> &edges) {
        vector<vector<long long>> adj(n + 1);
        vector<bool> used(n + 1, false);
        vector<long long> subSize(n + 1, 0);
        long long matching = 0;

        for (auto &e : edges) {
            long long u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        function<void(long long, long long)> dfs_match = [&](long long u, long long parent) {
            for (long long v : adj[u]) {
                if (v == parent) continue;
                dfs_match(v, u);
            }
            if (parent != -1 && !used[u] && !used[parent]) {
                used[u] = used[parent] = true;
                matching++;
            }
        };

        function<long long(long long, long long, long long &)> dfs_size = [&](long long u, long long parent, long long &ma) {
            long long s = 1;
            for (long long v : adj[u]) {
                if (v == parent) continue;
                long long t = dfs_size(v, u, ma);
                s += t;
                ma += 2LL * min(t, n - t);
            }
            subSize[u] = s;
            return s;
        };

        dfs_match(1, -1);
        long long mi = 2LL * (n - matching);
        long long ma = 0;
        dfs_size(1, -1, ma);
        return {mi, ma};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<vector<long long>> edges(n - 1, vector<long long>(2));

    for (long long i = 0; i < n - 1; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    Solution solution;
    vector<long long> result = solution.optShuffling(n, edges);

    cout << result[0] << " " << result[1] << "\n";
    return 0;
}
