#include <bits/stdc++.h>
using namespace std;

vector<bool> upd(const vector<bool>& cur, const vector<set<int>>& g) {
    int n = cur.size();
    vector<bool> nxt(n, false);
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int nb : g[i]) cnt += cur[nb];
        if ((cur[i] && cnt == 3) || (!cur[i] && cnt < 3)) 
            nxt[i] = true;
    }
    return nxt;
}

int sim(int n, int t, const vector<set<int>>& g) {
    int d = 1, act = n;
    vector<bool> cur(n, true);

    while (act < t) {
        cur = upd(cur, g);
        act = count(cur.begin(), cur.end(), true);
        ++d;
    }
    return d;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<set<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int t;
    cin >> t;
    cout << sim(n, t, g);
    return 0;
}