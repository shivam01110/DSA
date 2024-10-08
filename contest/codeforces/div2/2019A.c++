#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll n, q;
    cin >> n >> q;
    vector<ll> x(n);
    for (int i=0;i<n;i++) cin >> x[i];
    vector<ll> que(q);
    for (int i=0;i<q;i++) cin >> que[i];
    unordered_map<ll, ll> freq;
    for (ll i = 1; i <= n; ++i) {
        ll k_p = (i - 1) * (n - i + 1) + (n - i);
        freq[k_p]++;
        if (i < n) {
            ll diff = x[i] - x[i - 1] - 1;
            if (diff > 0) {
                ll gap = i * (n - i);
                freq[gap] += diff;
            }
        }
    }
    for (ll ki : que) {
        cout<<freq[ki]<<" ";
    }
    cout << endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
