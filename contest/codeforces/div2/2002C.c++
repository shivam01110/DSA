#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n;
    cin >> n;
    vector<ll> x(n + 1), y(n + 1);
    ll x1, y1, x2, y2;
    for (ll i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    cin >> x1 >> y1 >> x2 >> y2;
    ll mindist = LLONG_MAX;
    for (ll i = 1; i <= n; ++i) {
        ll dist = (x[i] - x2) * (x[i] - x2) + (y[i] - y2) * (y[i] - y2);
        mindist = min(mindist, dist);
    }
    ll dis = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    if (mindist <= dis) {
        cout << "NO";
    } else {
        cout << "YES";
    }
    cout <<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
