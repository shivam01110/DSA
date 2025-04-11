#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcdab(ll a,ll b){
    if(b==0) return a;
    return gcdab(b,a%b);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(ll i=0;i<n;i++) cin>>a[i];
    for(ll i=0;i<m;i++) cin>>b[i];
    ll precompute=0;
    for(ll i=1;i<m;i++){
        precompute=gcdab(precompute,abs(a[i]-a[i-1]));  //gcd of a[1] to a[n-1]
    }
    ll res=0;
    for(ll i=0;i<m;i++){
        res=gcdab(precompute,a[0]+b[i]);
        cout<<res<<" ";
    }
    cout<<"\n";
}

int main(){
    solve();
    return 0;
}