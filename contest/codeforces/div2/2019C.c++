#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, k;
    cin >> n >> k;
    ll maxi = LLONG_MIN;
    ll totalSum = 0;
    vector<ll> arr(n);    
    for (int i=0;i<n;i++){ 
        cin>>arr[i];
        maxi=max(maxi,arr[i]);
        totalSum+=arr[i];
    }
    for (ll decksize = n; decksize > 0; decksize--) {
        ll deck = (totalSum + k) / decksize;     
        if ((deck * decksize <= totalSum - 1) || (deck <= maxi - 1)) continue;  
        else {
            cout << decksize << endl;
            break;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
