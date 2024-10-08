#include <bits/stdc++.h>
using namespace std;


int find_position(int n, const vector<int>& teachers, int a) {
    int m = teachers.size();
    if (a < teachers[0]) {
        return teachers[0] - 1;
    }
    if (a > teachers[m - 1]) {
        return n - teachers[m - 1];
    }
    int lo = 0, hi = m - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (teachers[mid] < a) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    int right = teachers[lo];
    int left = teachers[lo - 1];
    return (right - left) / 2;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> teachers(m);
        for (int i = 0; i < m; i++) {
            cin >> teachers[i];
        }
        sort(teachers.begin(), teachers.end());
        for (int i = 0; i < q; i++) {
            int a;
            cin >> a;
            int result = find_position(n, teachers, a);
            cout << result << endl;
        }
    }

    return 0;
}
