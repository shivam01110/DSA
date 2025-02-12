#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    unordered_map<int, int> m; // Frequency map
    int e;

    // Input array and build frequency map
    for (int i = 0; i < n; i++) {
        cin >> e;
        m[e]++;
    }

    int cnt = 0;

    for (auto it = m.begin(); it != m.end(); ++it) {
        int num = it->first;
        int freq = it->second;

        int req = k - num;

        // Case 1: When `req` equals `num`, count pairs within the same group
        if (req == num) {
            cnt += freq / 2; // Each pair requires 2 elements
            m[num] = 0;      // All elements used up
        }
        // Case 2: When `req` is different from `num`
        else if (m.find(req) != m.end()) {
            int pairs = min(freq, m[req]);
            cnt += pairs;        // Count valid pairs
            m[num] -= pairs;     // Remove used elements
            m[req] -= pairs;     // Remove used elements
        }
    }

    cout << cnt << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
