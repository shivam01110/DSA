#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vl vector<ll> 

void solve(){
    int n;cin>>n;
    ll m;cin>>m;
    vl a(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.rbegin(),a.rend());
    ll maxi=LLONG_MIN;
    int r=0,l=0;ll sum=0;
    while (r < n) {
        sum += a[r];
        while (sum > m || (l < r && a[l] - a[r] > 1)) {
            sum -= a[l];
            l++;
        }
        if (sum <= m) {
            maxi = max(sum, maxi);
        }
        r++;
    }
    cout << (maxi == LLONG_MIN ? 0 : maxi) << endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
