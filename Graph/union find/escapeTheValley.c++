#include <bits/stdc++.h>
using namespace std;

struct Lamp {
    int x, y, r, idx;
    bool operator<(const Lamp& other) const {
        return x - r < other.x - other.r;
    }
};

class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootY] = rootX;
        }
    }
};

bool overlap(const Lamp& a, const Lamp& b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long r_sum = a.r + b.r;
    return dx * dx + dy * dy <= r_sum * r_sum;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<Lamp> lamps(N);
        vector<int> source, target;
        for (int i = 0; i < N; i++) {
            cin >> lamps[i].x >> lamps[i].y >> lamps[i].r;
            lamps[i].idx = i;
            if (lamps[i].x - lamps[i].r <= 0) source.push_back(i);
            if (lamps[i].x + lamps[i].r >= M) target.push_back(i);
        }
        sort(lamps.begin(), lamps.end());
        DSU dsu(N);
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N && lamps[j].x - lamps[j].r <= lamps[i].x + lamps[i].r; j++) {
                if (overlap(lamps[i], lamps[j])) {
                    dsu.union_sets(i, j);
                }
            }
        }
        bool reachable = false;
        for (int s : source) {
            for (int t : target) {
                if (dsu.find(s) == dsu.find(t)) {
                    reachable = true;
                    break;
                }
            }
            if (reachable) break;
        }
        cout << (reachable ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
